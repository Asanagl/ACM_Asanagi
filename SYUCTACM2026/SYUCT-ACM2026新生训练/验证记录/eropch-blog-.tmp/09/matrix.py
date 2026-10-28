import json, os, subprocess, sys

ROOT = os.path.dirname(os.path.abspath(__file__))
PROB = os.path.join(ROOT, "..", "..", "problemsets", "2026syuctacm-weekly-04", "problems", "09")
BUILD = os.path.join(ROOT, "build")
GEN = os.path.join(BUILD, "generator.exe")
CHK = os.path.join(BUILD, "checker.exe")
SOL = os.path.join(BUILD, "solution.exe")

cfg = json.load(open(os.path.join(PROB, "config.json"), encoding="utf-8"))
cases = cfg["generator"]["cases"]
wrongs = [w["name"] for w in cfg["wrongSolutions"]]

def run(exe, args=(), inp=None):
    p = subprocess.run([exe] + list(args), input=inp, capture_output=True, timeout=30)
    return p.returncode, p.stdout, p.stderr

os.makedirs(os.path.join(ROOT, "matrix"), exist_ok=True)
summary = {}
for w in wrongs:
    summary[w] = {"wa": 0, "pe": 0, "re": 0, "ac": 0, "first": None}

for c in cases:
    rc, out, err = run(GEN, [c["type"], str(c["seed"])])
    assert rc == 0, (c["name"], err)
    ipath = os.path.join(ROOT, "matrix", c["name"] + ".in")
    open(ipath, "wb").write(out)
    rc, ans, err = run(SOL, inp=out)
    assert rc == 0, (c["name"], "main failed", err)
    apath = os.path.join(ROOT, "matrix", c["name"] + ".ans")
    open(apath, "wb").write(ans)

    for w in wrongs:
        wpath = os.path.join(BUILD, w + ".exe")
        rc, wout, werr = run(wpath, inp=out)
        if rc != 0:
            # 程序自身崩溃/异常退出
            summary[w]["re"] += 1
            verdict = "RE"
        else:
            opath = os.path.join(ROOT, "matrix", f"{c['name']}.{w}.out")
            open(opath, "wb").write(wout)
            jrc, jout, jerr = run(CHK, [ipath, opath, apath])
            if jrc == 0:
                verdict = "AC"
                summary[w]["ac"] += 1
            elif jrc == 1:
                verdict = "WA"
                summary[w]["wa"] += 1
            elif jrc == 2:
                verdict = "PE"
                summary[w]["pe"] += 1
            else:
                verdict = f"J{jrc}"
                summary[w]["re"] += 1
        if verdict != "AC" and summary[w]["first"] is None:
            summary[w]["first"] = (c["name"], verdict)
        print(f"{c['name']:<20} {w:<26} {verdict}")

print("\n=== summary ===")
for w, s in summary.items():
    print(f"{w:<26} AC={s['ac']:<3} WA={s['wa']:<3} PE={s['pe']:<3} RE/other={s['re']:<3} first_fail={s['first']}")
