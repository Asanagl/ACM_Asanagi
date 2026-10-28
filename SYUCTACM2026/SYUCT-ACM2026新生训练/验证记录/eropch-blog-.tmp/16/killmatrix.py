import json
import os
import subprocess

ROOT = r"C:\Users\Asanagi\eropch-blog\.tmp\16"
BIN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-16\bin"
GEN = os.path.join(BIN, "generator.exe")
CHK = os.path.join(BIN, "checker.exe")
MAIN = os.path.join(BIN, "main.exe")

PROB = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04\problems\16"
cfg = json.load(open(os.path.join(PROB, "config.json"), encoding="utf-8"))
cases = cfg["generator"]["cases"]
wrongs = cfg["wrongSolutions"]

ENV = dict(os.environ)


def run(exe, inp=None, args=None):
    cmd = [exe] + (args or [])
    p = subprocess.run(cmd, input=inp, stdout=subprocess.PIPE, stderr=subprocess.PIPE, env=ENV)
    return p.returncode, p.stdout, p.stderr


print("case name                type                  verdict-for-each-wrong")
print("-" * 100)

summary = {w["name"]: {"wa": 0, "re": 0, "ac": 0, "cases": []} for w in wrongs}

for c in cases:
    rc, inp, err = run(GEN, args=[c["type"], str(c["seed"])])
    assert rc == 0, (c["name"], rc, err)
    base = os.path.join(ROOT, "matrix")
    os.makedirs(base, exist_ok=True)
    ip = os.path.join(base, c["name"] + ".in")
    open(ip, "wb").write(inp)

    rc, ans, err = run(MAIN, inp=inp)
    assert rc == 0, (c["name"], "main", rc, err)
    ap = os.path.join(base, c["name"] + ".ans")
    open(ap, "wb").write(ans)

    row = []
    for w in wrongs:
        exe = os.path.join(BIN, w["name"] + ".exe")
        wrc, wout, werr = run(exe, inp=inp)
        op = os.path.join(base, c["name"] + "." + w["name"] + ".out")
        if wrc != 0:
            kind = "RE"
            summary[w["name"]]["re"] += 1
        else:
            open(op, "wb").write(wout)
            crc, cout, cerr = run(CHK, args=[ip, op, ap])
            kind = "AC" if crc == 0 else ("WA" if crc == 1 else "PE")
            if kind == "AC":
                summary[w["name"]]["ac"] += 1
            else:
                summary[w["name"]]["wa"] += 1
        summary[w["name"]]["cases"].append((c["name"], kind))
        row.append("%s:%s" % (w["name"].replace("wrong-", ""), kind))

    print("%-24s %-20s %s" % (c["name"], c["type"], " ".join(row)))

print()
print("=== wrong solution summary ===")
for w in wrongs:
    s = summary[w["name"]]
    first_kill = next((n for n, k in s["cases"] if k != "AC"), None)
    print("%-22s WA=%2d RE=%2d AC=%2d  first-non-AC=%s" % (w["name"], s["wa"], s["re"], s["ac"], first_kill))

bad = [w["name"] for w in wrongs if summary[w["name"]]["wa"] + summary[w["name"]]["re"] == 0]
re_only = [w["name"] for w in wrongs if summary[w["name"]]["wa"] == 0 and summary[w["name"]]["re"] > 0]
print()
print("never-killed:", bad or "none")
print("killed-only-by-RE:", re_only or "none")
