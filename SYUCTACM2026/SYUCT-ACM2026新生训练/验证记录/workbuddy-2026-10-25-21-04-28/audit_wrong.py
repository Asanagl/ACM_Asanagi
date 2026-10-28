import os, json, subprocess, time

ROOT = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04\problems"
WORK = r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28"
BIN = os.path.join(WORK, "bin")
GPP = r"C:\Algo Bootstrap\mingw64\bin\g++.exe"
env = dict(os.environ)
env["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + env["PATH"]

def run(exe, inp_path, out_path, timeout_s):
    with open(inp_path, "rb") as fi, open(out_path, "wb") as fo:
        try:
            r = subprocess.run([exe], stdin=fi, stdout=fo, stderr=subprocess.DEVNULL,
                               timeout=timeout_s, env=env)
            return r.returncode, False
        except subprocess.TimeoutExpired:
            return None, True

rows = []
for i in range(1, 26):
    pid = "%02d" % i
    d = os.path.join(ROOT, pid)
    cfg = json.load(open(os.path.join(d, "config.json"), encoding="utf-8"))
    man = json.load(open(os.path.join(d, "exported-tests", "manifest.json"), encoding="utf-8"))
    tl = cfg["timeLimitMs"] / 1000.0
    cases = []
    for c in man["cases"]:
        cases.append((c["group"], c["name"],
                      os.path.join(d, "exported-tests", c["input"].replace("/", os.sep)),
                      os.path.join(d, "exported-tests", c["answer"].replace("/", os.sep))))
    checker = os.path.join(BIN, pid + "-checker.exe")
    for w in cfg.get("wrongSolutions", []):
        exe = os.path.join(BIN, pid + "-w-" + w["name"] + ".exe")
        src = os.path.join(d, w["path"])
        if (not os.path.exists(exe)) or os.path.getmtime(exe) < os.path.getmtime(src):
            r = subprocess.run([GPP] + cfg["build"]["cppFlags"] + [src, "-o", exe],
                               capture_output=True, env=env)
            if r.returncode != 0:
                rows.append({"pid": pid, "wrong": w["name"], "killed": None,
                             "why": "COMPILE_FAIL " + r.stderr.decode("utf-8", "replace")[:200]})
                continue
        first = None
        n_fail = 0
        for grp, name, cin, cans in cases:
            outp = os.path.join(WORK, "diffs", "_w.out")
            rc, tle = run(exe, cin, outp, max(tl * 3, 2.0))
            if tle:
                kind = "TLE"
            elif rc != 0:
                kind = "RE(rc=%d)" % rc
            else:
                cr = subprocess.run([checker, cin, outp, cans], capture_output=True, env=env, timeout=30)
                if cr.returncode == 0:
                    continue
                kind = {1: "WA", 2: "PE", 3: "FAIL"}.get(cr.returncode, "CHK%d" % cr.returncode)
            n_fail += 1
            if first is None:
                first = {"case": name, "group": grp, "kind": kind}
            if w.get("expected") == "fail":
                break
        rows.append({"pid": pid, "wrong": w["name"], "expected": w.get("expected"),
                     "killed": bool(n_fail) if w.get("expected") == "fail" else None,
                     "first": first, "n_fail": n_fail, "n_cases": len(cases)})
    print(pid, "done", len([r for r in rows if r["pid"] == pid]))

json.dump(rows, open(os.path.join(WORK, "wrong_audit.json"), "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)

print("\n%-4s %-24s %-8s %-7s %s" % ("pid", "wrong", "expected", "killed", "first failure"))
for r in rows:
    f = r.get("first") or {}
    print("%-4s %-24s %-8s %-7s %s %s %s" % (
        r["pid"], r["wrong"], r.get("expected"), r.get("killed"),
        f.get("case", "-"), f.get("kind", r.get("why", "")), ""))
bad = [r for r in rows if r.get("expected") == "fail" and not r.get("killed")]
print("\nUNKILLED:", [(r["pid"], r["wrong"]) for r in bad] or "none")
re_kills = [r for r in rows if (r.get("first") or {}).get("kind", "").startswith("RE")]
print("KILLED-BY-RE:", [(r["pid"], r["wrong"], r["first"]["kind"]) for r in re_kills] or "none")
pe_kills = [r for r in rows if (r.get("first") or {}).get("kind", "") == "PE"]
print("KILLED-BY-PE:", [(r["pid"], r["wrong"]) for r in pe_kills] or "none")
print("TOTAL WRONGS:", len(rows))
