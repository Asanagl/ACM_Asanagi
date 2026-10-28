import json, os, subprocess, time

ROOT = r"C:\Users\Asanagi\eropch-blog"
WS = os.path.join(ROOT, "problemsets", "2026syuctacm-weekly-04", "problems", "14")
BUILD = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-14"
BIN = os.path.join(BUILD, "bin")
GEN = os.path.join(BUILD, "generated")
TMP = os.path.join(ROOT, ".tmp", "14", "killout")
os.makedirs(TMP, exist_ok=True)

cfg = json.load(open(os.path.join(WS, "config.json"), encoding="utf-8"))
wrongs = cfg["wrongSolutions"]
rows = []

for case in cfg["generator"]["cases"]:
    name, grp = case["name"], case["group"]
    inp = os.path.join(GEN, grp, name + ".in")
    ans = os.path.join(GEN, grp, name + ".ans")
    if not os.path.exists(ans):
        continue
    for w in wrongs:
        exe = os.path.join(BIN, w["name"] + ".exe")
        out = os.path.join(TMP, name + "." + w["name"] + ".out")
        start = time.time()
        try:
            with open(inp, "rb") as fin, open(out, "wb") as fout:
                p = subprocess.run([exe], stdin=fin, stdout=fout, stderr=subprocess.DEVNULL, timeout=3.0)
            elapsed = time.time() - start
            if p.returncode != 0:
                verdict = "RE"
            else:
                chk = subprocess.run([os.path.join(BIN, "checker.exe"), inp, out, ans], capture_output=True)
                verdict = "AC" if chk.returncode == 0 else "WA"
        except subprocess.TimeoutExpired:
            elapsed = 3.0
            verdict = "TLE"
        rows.append((name, grp, w["name"], verdict, round(elapsed, 3)))

print("== full matrix (non-AC only shown per wrong) ==")
for w in wrongs:
    vs = [r for r in rows if r[2] == w["name"]]
    bad = [r for r in vs if r[3] != "AC"]
    ac = [r for r in vs if r[3] == "AC"]
    print("\n" + w["name"], "total:", len(vs), "nonAC:", len(bad), "AC:", len(ac))
    for r in bad:
        print("   ", r[0], r[1], r[3], r[4])
    if ac:
        print("    AC cases:", ", ".join(r[0] for r in ac))
