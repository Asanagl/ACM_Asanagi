import json
import os
import subprocess
import sys

WS = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04\problems\03"
HERE = os.path.dirname(os.path.abspath(__file__))
BIN = os.path.join(HERE, "bin2")
TMP = os.path.join(HERE, "judge2")
LOG = os.path.join(HERE, "killmap.log")
os.makedirs(TMP, exist_ok=True)

cfg = json.load(open(os.path.join(WS, "config.json"), encoding="utf-8"))
cases = cfg["generator"]["cases"]
wrongs = cfg["wrongSolutions"]

GEN = os.path.join(BIN, "generator.exe")
MAIN = os.path.join(BIN, "main.exe")
CHK = os.path.join(BIN, "checker.exe")
VAL = os.path.join(BIN, "validator.exe")

lines = []


def run(exe, data):
    p = subprocess.run([exe], input=data, capture_output=True, timeout=180)
    return p.returncode, p.stdout, p.stderr


def run_file(exe, path):
    with open(path, "rb") as f:
        p = subprocess.run([exe], stdin=f, capture_output=True, timeout=180)
    return p.returncode, p.stdout, p.stderr


# generate + validate + main answer
lines.append("=== generation / validation / main ===")
for c in cases:
    p = subprocess.run([GEN, c["type"], str(c["seed"])], capture_output=True, timeout=180)
    if p.returncode != 0:
        lines.append("GEN FAIL %s rc=%d %s" % (c["name"], p.returncode, p.stderr[:200]))
        print("\n".join(lines))
        sys.exit(1)
    data = p.stdout
    ip = os.path.join(TMP, c["name"] + ".in")
    open(ip, "wb").write(data)

    rc, out, err = run_file(VAL, ip)
    if rc != 0:
        lines.append("VALIDATOR FAIL %s rc=%d %s" % (c["name"], rc, err[:300]))
        print("\n".join(lines))
        sys.exit(1)

    rc, ans, err = run(MAIN, data)
    if rc != 0:
        lines.append("MAIN FAIL %s rc=%d" % (c["name"], rc))
        print("\n".join(lines))
        sys.exit(1)
    ap = os.path.join(TMP, c["name"] + ".ans")
    open(ap, "wb").write(ans)
    lines.append("%-22s group=%-6s type=%-18s len=%-8d ans=%s"
                 % (c["name"], c["group"], c["type"], len(data.strip()), ans.decode().strip()))

# wrong kill map
lines.append("")
lines.append("=== wrong solution kill map ===")
all_killed = True
for w in wrongs:
    exe = os.path.join(BIN, w["name"] + ".exe")
    first = None
    reason = ""
    for c in cases:
        if c["group"] not in w.get("groups", ["sample", "secret"]):
            continue
        ip = os.path.join(TMP, c["name"] + ".in")
        ap = os.path.join(TMP, c["name"] + ".ans")
        rc, out, err = run_file(exe, ip)
        if rc != 0:
            first = (c["name"], "RE")
            reason = err.decode("utf-8", "replace")[:120]
            break
        op = os.path.join(TMP, c["name"] + "." + w["name"] + ".out")
        open(op, "wb").write(out)
        jr = subprocess.run([CHK, ip, op, ap], capture_output=True, timeout=60)
        if jr.returncode != 0:
            first = (c["name"], "WA")
            reason = jr.stdout.decode("utf-8", "replace").strip()[:160]
            break
    status = "KILLED" if first else "SURVIVED"
    if not first:
        all_killed = False
    lines.append("%-18s %-9s at %-40s %s"
                 % (w["name"], status, str(first), reason))

lines.append("")
from collections import Counter
grp = Counter(c["group"] for c in cases)
lines.append("sample=%d secret=%d total=%d" % (grp.get("sample", 0), grp.get("secret", 0), len(cases)))
lines.append("ALL_KILLED=%s" % all_killed)

with open(LOG, "w", encoding="utf-8") as f:
    f.write("\n".join(lines) + "\n")
print("\n".join(lines))
sys.exit(0 if all_killed else 1)
