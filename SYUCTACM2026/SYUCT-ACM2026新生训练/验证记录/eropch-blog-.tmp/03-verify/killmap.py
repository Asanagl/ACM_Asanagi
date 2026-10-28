import json, os, subprocess, sys

WS = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04\problems\03"
BIN = r"C:\Users\Asanagi\eropch-blog\.tmp\03-verify\bin"
GEN = os.path.join(BIN, "generator.exe")
MAIN = os.path.join(BIN, "solution.exe")
CHK = os.path.join(BIN, "checker.exe")
TMP = r"C:\Users\Asanagi\eropch-blog\.tmp\03-verify\judge"
os.makedirs(TMP, exist_ok=True)

cfg = json.load(open(os.path.join(WS, "config.json"), encoding="utf-8"))
cases = cfg["generator"]["cases"]
wrongs = cfg["wrongSolutions"]

def run(exe, data):
    p = subprocess.run([exe], input=data, capture_output=True, timeout=60)
    return p.returncode, p.stdout, p.stderr

report = {}
verdicts = {}
for c in cases:
    rc, out, err = run(GEN, b"")
    # generator needs args; call properly
for c in cases:
    p = subprocess.run([GEN, c["type"], str(c["seed"])], capture_output=True, timeout=120)
    if p.returncode != 0:
        print("GEN FAIL", c["name"], p.returncode, p.stderr[:200])
        sys.exit(1)
    data = p.stdout
    rc, ans, err = run(MAIN, data)
    if rc != 0:
        print("MAIN FAIL", c["name"], rc)
        sys.exit(1)
    ip = os.path.join(TMP, c["name"] + ".in")
    ap = os.path.join(TMP, c["name"] + ".ans")
    open(ip, "wb").write(data)
    open(ap, "wb").write(ans)
    verdicts[c["name"]] = {"len": len(data.strip()), "group": c["group"], "type": c["type"]}

print("=== wrong solution kill map (first failing case per solution) ===")
all_ok = True
for w in wrongs:
    exe = os.path.join(BIN, w["name"] + ".exe")
    first_fail = None
    reason = None
    ac_count = 0
    tested = 0
    for c in cases:
        if c["group"] not in w.get("groups", ["sample", "secret"]):
            continue
        tested += 1
        data = open(os.path.join(TMP, c["name"] + ".in"), "rb").read()
        rc, out, err = run(exe, data)
        if rc != 0:
            first_fail = (c["name"], "RE")
            reason = err[:120].decode("utf-8", "replace")
            break
        op = os.path.join(TMP, c["name"] + "." + w["name"] + ".out")
        open(op, "wb").write(out)
        jr = subprocess.run([CHK, os.path.join(TMP, c["name"] + ".in"), op,
                             os.path.join(TMP, c["name"] + ".ans")],
                            capture_output=True, timeout=60)
        if jr.returncode != 0:
            first_fail = (c["name"], "WA")
            reason = jr.stdout.decode("utf-8", "replace").strip()[:150]
            break
        ac_count += 1
    status = "KILLED" if first_fail else "SURVIVED"
    if not first_fail:
        all_ok = False
    print(f"{w['name']:18s} {status:8s} at {first_fail}  AC-before-kill={ac_count}/{tested}")
    if reason:
        print("   ", reason)

print()
print("=== sample/secret counts ===")
from collections import Counter
grp = Counter(c["group"] for c in cases)
print(dict(grp), "total", len(cases))
lengths = sorted(set(v["len"] for v in verdicts.values()))
print("distinct input lengths:", len(lengths), "min", min(lengths), "max", max(lengths))
print("sample inputs:")
for c in cases:
    if c["group"] == "sample":
        print(" ", c["name"], repr(open(os.path.join(TMP, c["name"] + ".in"), "rb").read()[:40]))

# first failing case per wrong (full map, no early break) for evidence table
print()
print("=== full per-case matrix (W=wa, R=re, .=ac) ===")
for w in wrongs:
    exe = os.path.join(BIN, w["name"] + ".exe")
    row = []
    for c in cases:
        if c["group"] not in w.get("groups", ["sample", "secret"]):
            row.append("-")
            continue
        data = open(os.path.join(TMP, c["name"] + ".in"), "rb").read()
        rc, out, err = run(exe, data)
        if rc != 0:
            row.append("R")
            continue
        op = os.path.join(TMP, c["name"] + "." + w["name"] + ".out")
        open(op, "wb").write(out)
        jr = subprocess.run([CHK, os.path.join(TMP, c["name"] + ".in"), op,
                             os.path.join(TMP, c["name"] + ".ans")], capture_output=True)
        row.append("." if jr.returncode == 0 else "W")
    print(f"{w['name']:18s} {''.join(row)}")
print("case order:", ", ".join(c["name"] for c in cases))

sys.exit(0 if all_ok else 1)
