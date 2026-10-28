import os, json, subprocess, hashlib, sys, time

ROOT = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04\problems"
WORK = r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28"
BIN = os.path.join(WORK, "bin")
BLIND = os.path.join(WORK, "blind")
DIFF = os.path.join(WORK, "diffs")
GPP = r"C:\Algo Bootstrap\mingw64\bin\g++.exe"

os.makedirs(BIN, exist_ok=True)
os.makedirs(DIFF, exist_ok=True)
env = dict(os.environ)
env["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + env["PATH"]

ROUNDS = int(sys.argv[1]) if len(sys.argv) > 1 else 105
BASE_SEED = 12345

def run(cmd, inp=None, timeout=30, cwd=None):
    try:
        r = subprocess.run(cmd, input=inp, capture_output=True, timeout=timeout, env=env, cwd=cwd)
        return r.returncode, r.stdout
    except subprocess.TimeoutExpired:
        return -999, b""

def build(pid):
    d = os.path.join(ROOT, pid)
    cfg = json.load(open(os.path.join(d, "config.json"), encoding="utf-8"))
    flags = cfg["build"]["cppFlags"]
    inc = ["-I", os.path.join(d, "include")]
    out = {}
    jobs = [
        ("gen", os.path.join(d, "src", "generator", "generator.cpp"), inc),
        ("main", os.path.join(d, cfg["solutions"][0]["path"]), []),
        ("sol2", os.path.join(d, cfg["solutions"][1]["path"]), []),
        ("checker", os.path.join(d, cfg["checker"]), inc),
    ]
    rv = os.path.join(BLIND, "p" + pid, "review.cpp")
    if os.path.isfile(rv):
        jobs.append(("review", rv, []))
    for name, src, extra in jobs:
        exe = os.path.join(BIN, pid + "-" + name + ".exe")
        stale = (not os.path.exists(exe)) or os.path.getmtime(exe) < os.path.getmtime(src)
        if stale:
            try:
                r = subprocess.run([GPP] + flags + extra + [src, "-o", exe],
                                   capture_output=True, timeout=120, env=env)
            except subprocess.TimeoutExpired:
                return None, cfg, "COMPILE_TIMEOUT:" + name
            if r.returncode != 0:
                msg = (r.stderr or r.stdout or b"").decode("utf-8", "replace")[:600]
                return None, cfg, "COMPILE_FAIL:" + name + ": " + msg
        out[name] = exe
    return out, cfg, None

summary = []
PIDS = [p.strip() for p in (sys.argv[2].split(",") if len(sys.argv) > 2 else []) if p.strip()]
for i in range(1, 26):
    pid = "%02d" % i
    if PIDS and pid not in PIDS:
        continue
    bins, cfg, err = build(pid)
    if err:
        print(pid, err)
        summary.append({"pid": pid, "error": err})
        continue

    types = []
    for c in cfg["generator"]["cases"]:
        if c["type"] not in types:
            types.append(c["type"])

    # sample 组是题面展示的固定数据，交给标准验题器覆盖；对拍轮次只用 secret 用的类型，
    # 这样 105 轮全部落在新生成的输入上。
    sample_only = set()
    for t in types:
        cs = [c for c in cfg["generator"]["cases"] if c["type"] == t]
        if cs and all(c["group"] == "sample" for c in cs):
            sample_only.add(t)
    rot = [t for t in types if t not in sample_only] or types

    ok_rounds = 0
    fail = []
    hashes = set()
    fmt_only = 0
    t0 = time.time()
    for k in range(ROUNDS):
        typ = rot[k % len(rot)]
        seed = BASE_SEED + k
        rc, inp = run([bins["gen"], typ, str(seed)], timeout=60)
        if rc != 0:
            fail.append({"round": k, "type": typ, "seed": seed, "why": "gen rc=%d" % rc})
            continue
        hashes.add(hashlib.md5(inp).hexdigest())
        rc1, o1 = run([bins["main"]], inp=inp, timeout=30)
        rc2, o2 = run([bins["sol2"]], inp=inp, timeout=30)
        rc3, o3 = run([bins["review"]], inp=inp, timeout=30) if "review" in bins else (0, b"")
        if rc1 != 0 or rc2 != 0 or rc3 != 0:
            fail.append({"round": k, "type": typ, "seed": seed,
                         "why": "rc main=%d sol2=%d review=%d" % (rc1, rc2, rc3)})
            open(os.path.join(DIFF, pid + "-r%d.in" % k), "wb").write(inp)
            continue
        if not (o1 == o2 == o3):
            # semantic check through the official checker, both directions
            ip = os.path.join(DIFF, "_tmp.in"); a = os.path.join(DIFF, "_tmp.a"); b = os.path.join(DIFF, "_tmp.b")
            open(ip, "wb").write(inp); open(a, "wb").write(o1); open(b, "wb").write(o2)
            c1, _ = run([bins["checker"], ip, b, a], timeout=30)
            open(b, "wb").write(o3)
            c2, _ = run([bins["checker"], ip, b, a], timeout=30)
            if c1 == 0 and c2 == 0:
                fmt_only += 1
            else:
                fail.append({"round": k, "type": typ, "seed": seed,
                             "why": "MISMATCH checker sol2=%d review=%d; byte-eq main/sol2=%s main/review=%s"
                                    % (c1, c2, o1 == o2, o1 == o3)})
                open(os.path.join(DIFF, pid + "-r%d.in" % k), "wb").write(inp)
                continue
        ok_rounds += 1

    summary.append({"pid": pid, "rounds": ROUNDS, "ok": ok_rounds, "fails": fail,
                    "distinct_inputs": len(hashes), "format_only": fmt_only,
                    "secs": round(time.time() - t0, 1)})
    print("%s rounds=%d ok=%d distinct=%d fmt_only=%d fails=%d %.1fs"
          % (pid, ROUNDS, ok_rounds, len(hashes), fmt_only, len(fail), time.time() - t0))
    for f in fail[:3]:
        print("   ", f)

summary_path = os.path.join(WORK, "diff_summary.json")
if PIDS and os.path.exists(summary_path):
    old = json.load(open(summary_path, encoding="utf-8"))
    keep = [s for s in old if s.get("pid") not in PIDS]
    merged = keep + summary
    merged.sort(key=lambda s: s.get("pid", ""))
    json.dump(merged, open(summary_path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    full = merged
else:
    json.dump(summary, open(summary_path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    full = summary

bad = [s for s in full if s.get("error") or s.get("ok", 0) != ROUNDS]
print("\nPROBLEMS WITH ISSUES:", [s["pid"] for s in bad] or "none")
