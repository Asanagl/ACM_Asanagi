import os, re, json, subprocess, sys, tempfile

ROOT = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04"
P = os.path.join(ROOT, "problems")
BIN = r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28\bin"
GPP = r"C:\Algo Bootstrap\mingw64\bin\g++.exe"

env = dict(os.environ)
env["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + env["PATH"]

def norm(s):
    return "\n".join(line.rstrip() for line in s.replace("\r\n", "\n").strip().split("\n"))

def blocks(text):
    # match ~~~inputN ... ~~~ and ~~~outputN ... ~~~
    text = text.replace("\r\n", "\n")
    out = {}
    for m in re.finditer(r"~~~[ \t]*(input|output)(\d*)[ \t]*\n(.*?)\n~~~", text, re.S):
        kind, idx, body = m.group(1), m.group(2) or "1", m.group(3)
        out.setdefault(kind, {})[idx] = body
    # also ``` style
    if not out:
        for m in re.finditer(r"```[ \t]*(input|output)(\d*)[ \t]*\n(.*?)\n```", text, re.S):
            kind, idx, body = m.group(1), m.group(2) or "1", m.group(3)
            out.setdefault(kind, {})[idx] = body
    return out

def compile_main(pid):
    d = os.path.join(P, pid)
    os.makedirs(BIN, exist_ok=True)
    exe = os.path.join(BIN, pid + ".exe")
    if os.path.exists(exe):
        return exe
    src = os.path.join(d, "src", "solution.cpp")
    r = subprocess.run([GPP, "-std=gnu++17", "-O2", "-static", src, "-o", exe],
                       capture_output=True, text=True, env=env)
    if r.returncode != 0:
        return None
    return exe

report = []
for i in range(1, 26):
    pid = "%02d" % i
    d = os.path.join(P, pid)
    st = os.path.join(d, "docs", "statement.md")
    text = open(st, encoding="utf-8").read()
    b = blocks(text)
    ins = b.get("input", {})
    outs = b.get("output", {})
    row = {"pid": pid, "n_samples_stmt": len(ins), "mismatch": []}
    cfgp = os.path.join(d, "config.json")
    if os.path.exists(cfgp):
        cfg = json.load(open(cfgp, encoding="utf-8"))
        cases = cfg["generator"]["cases"]
        row["n_sample_cfg"] = sum(1 for c in cases if c.get("group") == "sample")
    else:
        row["n_sample_cfg"] = None
    exe = compile_main(pid)
    if exe is None:
        row["mismatch"].append("COMPILE_FAIL")
        report.append(row); continue
    ok = True
    for idx in sorted(ins.keys()):
        if idx not in outs:
            row["mismatch"].append(f"sample{idx}: missing output block"); ok = False; continue
        inp = ins[idx]
        r = subprocess.run([exe], input=inp, capture_output=True, text=True, env=env)
        if r.returncode != 0:
            row["mismatch"].append(f"sample{idx}: main RE rc={r.returncode}"); ok = False; continue
        if norm(r.stdout) != norm(outs[idx]):
            row["mismatch"].append(f"sample{idx}: OUTPUT DIFFERS")
            row.setdefault("detail", {})[idx] = {"got": norm(r.stdout)[:300], "want": norm(outs[idx])[:300]}
            ok = False
    row["ok"] = ok
    report.append(row)

for r in report:
    flag = "OK " if r.get("ok") else "BAD"
    print(f"{flag} {r['pid']} stmt_samples={r['n_samples_stmt']} cfg_samples={r['n_sample_cfg']} {r['mismatch'] if r['mismatch'] else ''}")
json.dump(report, open(os.path.join(r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28", "statement_audit.json"), "w", encoding="utf-8"), ensure_ascii=False, indent=1)
