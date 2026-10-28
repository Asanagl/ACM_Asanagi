"""Kill matrix: which cases each wrong solution fails.

For every wrong solution, generate every config case, run it, and judge with
the real checker. A wrong solution must fail at least one case.
"""

import json
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
BIN = os.path.join(HERE, "..", "04", "bin")
WORK = os.path.join(HERE, "..", "04", "killwork")
ROOT = os.path.abspath(os.path.join(HERE, "..", ".."))
CONFIG = os.path.join(
    ROOT, "problemsets", "2026syuctacm-weekly-04", "problems", "04", "config.json"
)

os.environ["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + os.environ["PATH"]

cfg = json.load(open(CONFIG, encoding="utf-8"))
cases = cfg["generator"]["cases"]
wrongs = [w["name"] for w in cfg["wrongSolutions"]]

os.makedirs(WORK, exist_ok=True)

GEN = os.path.join(BIN, "gen.exe")
VAL = os.path.join(BIN, "val.exe")
CHK = os.path.join(BIN, "checker.exe")
MAIN = os.path.join(BIN, "main.exe")
SOL2 = os.path.join(BIN, "sol2.exe")


def run(exe, stdin_data=None, args=None):
    return subprocess.run(
        [exe] + (args or []), input=stdin_data, capture_output=True
    )


fail_matrix = {w: [] for w in wrongs}
total = 0

for case in cases:
    name = case["name"]
    data = run(GEN, args=[case["type"], str(case["seed"])]).stdout
    if not data:
        print(f"GENERATOR EMPTY for {name}")
        sys.exit(1)
    total += 1

    v = run(VAL, stdin_data=data)
    if v.returncode != 0:
        print(f"VALIDATOR REJECT {name}: {v.stderr.decode(errors='replace')[:200]}")
        sys.exit(1)

    ans = run(MAIN, stdin_data=data).stdout
    if not ans:
        print(f"MAIN EMPTY {name}")
        sys.exit(1)
    s2 = run(SOL2, stdin_data=data).stdout
    if s2.replace(b"\r\n", b"\n") != ans.replace(b"\r\n", b"\n"):
        print(f"REFERENCE MISMATCH {name}")
        sys.exit(1)

    inpath = os.path.join(WORK, name + ".in")
    anspath = os.path.join(WORK, name + ".ans")
    open(inpath, "wb").write(data)
    open(anspath, "wb").write(ans)

    for w in wrongs:
        out = run(os.path.join(BIN, w + ".exe"), stdin_data=data).stdout
        outpath = os.path.join(WORK, name + "." + w + ".out")
        open(outpath, "wb").write(out)
        j = subprocess.run([CHK, inpath, outpath, anspath], capture_output=True)
        if j.returncode != 0:
            fail_matrix[w].append(name)

print(f"cases={total} samples={sum(1 for c in cases if c['group']=='sample')} "
      f"secret={sum(1 for c in cases if c['group']=='secret')}")
print()
bad = 0
for w in wrongs:
    killed = fail_matrix[w]
    status = "KILLED" if killed else "*** SURVIVED ***"
    if not killed:
        bad += 1
    print(f"{w:18s} {status:20s} fails {len(killed):2d}/{total} cases")
    print(f"   e.g. {killed[:6]}")

if bad:
    print(f"\n{bad} wrong solution(s) survived all cases")
    sys.exit(1)
print("\nall wrong solutions killed")
sys.exit(0)
