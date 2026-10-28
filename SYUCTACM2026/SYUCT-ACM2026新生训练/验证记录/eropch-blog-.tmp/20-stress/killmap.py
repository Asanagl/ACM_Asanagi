import json
import subprocess
from pathlib import Path

REPO = Path(r"C:/Users/Asanagi/eropch-blog")
PROBLEM = REPO / "problemsets/2026syuctacm-weekly-04/problems/20"
ART = Path(r"C:/Users/Asanagi/.codex/skills/icpc-problem-creator/.codex-test-artifacts/build/04-20")
BIN = ART / "bin"
GEN = ART / "generated"
CONFIG = json.loads((PROBLEM / "config.json").read_text(encoding="utf-8"))


def run(name, data):
    return subprocess.run([str(BIN / f"{name}.exe")], input=data, capture_output=True, timeout=30)


def check(inf, ouf, ansf):
    return subprocess.run(
        [str(BIN / "checker.exe"), str(inf), str(ouf), str(ansf)], capture_output=True, timeout=30
    )


cases = CONFIG["generator"]["cases"]
report = {}
for w in CONFIG["wrongSolutions"]:
    killed_by = []
    survived = []
    for c in cases:
        inf = GEN / c["group"] / f"{c['name']}.in"
        ansf = GEN / c["group"] / f"{c['name']}.ans"
        data = inf.read_bytes()
        r = run(w["name"], data)
        if r.returncode != 0:
            killed_by.append((c["name"], f"RE({r.returncode})"))
            continue
        out = GEN / c["group"] / f"{c['name']}.{w['name']}.probe.out"
        out.write_bytes(r.stdout)
        verdict = check(inf, out, ansf)
        out.unlink()
        if verdict.returncode != 0:
            killed_by.append((c["name"], "WA"))
        else:
            survived.append(c["name"])
    report[w["name"]] = {"killed": killed_by, "survived_count": len(survived)}

print(json.dumps(report, ensure_ascii=False, indent=2))
