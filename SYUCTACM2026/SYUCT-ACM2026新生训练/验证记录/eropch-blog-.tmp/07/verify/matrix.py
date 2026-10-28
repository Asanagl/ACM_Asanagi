import json
import os
import subprocess

PROB = r"C:/Users/Asanagi/eropch-blog/problemsets/2026syuctacm-weekly-04/problems/07"
HERE = r"C:/Users/Asanagi/eropch-blog/.tmp/07/verify"
BIN = os.path.join(HERE, "bin")
CASES = os.path.join(HERE, "cases")

env = dict(os.environ)
env["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + env["PATH"]

cfg = json.load(open(os.path.join(PROB, "config.json"), encoding="utf-8"))


def run(exe, args, stdin=None, timeout=60):
    return subprocess.run([os.path.join(BIN, exe)] + args, input=stdin,
                          capture_output=True, env=env, timeout=timeout)


rows = []
for c in cfg["generator"]["cases"]:
    out = run("generator.exe", [c["type"], str(c["seed"])])
    assert out.returncode == 0, (c, out.returncode, out.stderr)
    assert out.stderr.strip() == b"", (c, out.stderr)
    d = os.path.join(CASES, c["group"])
    os.makedirs(d, exist_ok=True)
    p = os.path.join(d, c["name"] + ".in")
    open(p, "wb").write(out.stdout)
    rows.append((c, p, out.stdout))

# determinism check: regenerate and compare
for c, p, data in rows:
    again = run("generator.exe", [c["type"], str(c["seed"])])
    assert again.stdout == data, ("nondeterministic", c)

print("cases:", len(rows))
print("sample:", sum(1 for r in rows if r[0]["group"] == "sample"))
print("secret:", sum(1 for r in rows if r[0]["group"] == "secret"))

# validator
bad = []
for c, p, data in rows:
    v = run("validator.exe", [], stdin=data)
    if v.returncode != 0:
        bad.append((c["name"], v.returncode, v.stderr.decode("utf-8", "replace")[:200]))
print("validator failures:", bad)

# main + solution2 answers
answers = {}
mismatch = []
for c, p, data in rows:
    m = run("solution.exe", [], stdin=data)
    r2 = run("solution2.exe", [], stdin=data)
    if m.returncode != 0 or r2.returncode != 0:
        mismatch.append((c["name"], "crash", m.returncode, r2.returncode))
        continue
    if m.stdout != r2.stdout:
        mismatch.append((c["name"], m.stdout, r2.stdout))
    answers[c["name"]] = m.stdout
    ap = os.path.join(os.path.dirname(p), c["name"] + ".ans")
    open(ap, "wb").write(m.stdout)
print("main vs solution2 mismatches:", mismatch)

# main output accepted by checker
chk_bad = []
for c, p, data in rows:
    ap = os.path.join(os.path.dirname(p), c["name"] + ".ans")
    r = run("checker.exe", [p, ap, ap], timeout=30)
    if r.returncode != 0:
        chk_bad.append((c["name"], r.returncode, r.stderr.decode("utf-8", "replace")[:200]))
print("checker rejects main output:", chk_bad)

# YES/NO distribution
yes = sum(1 for v in answers.values() if v.strip() == b"YES")
no = sum(1 for v in answers.values() if v.strip() == b"NO")
print("answer distribution: YES=", yes, "NO=", no)
print("secret YES=", sum(1 for c, p, d in rows if c["group"] == "secret" and answers[c["name"]].strip() == b"YES"),
      "secret NO=", sum(1 for c, p, d in rows if c["group"] == "secret" and answers[c["name"]].strip() == b"NO"))

# wrong solutions: first killing case per wrong solution
for w in cfg["wrongSolutions"]:
    exe = w["path"].split("/")[-1].replace(".cpp", ".exe")
    killed_by = []
    verdicts = []
    for c, p, data in rows:
        ap = os.path.join(os.path.dirname(p), c["name"] + ".ans")
        r = run(exe, [], stdin=data, timeout=30)
        if r.returncode != 0:
            verdicts.append((c["name"], c["group"], "RE/TLE rc=%d" % r.returncode))
            killed_by.append(c["name"])
            continue
        tp = os.path.join(HERE, "tmp.wrong.out")
        open(tp, "wb").write(r.stdout)
        jr = run("checker.exe", [p, tp, ap], timeout=30)
        if jr.returncode != 0:
            verdicts.append((c["name"], c["group"], "WA"))
            killed_by.append(c["name"])
    samples = [v for v in verdicts if v[1] == "sample"]
    secrets = [v for v in verdicts if v[1] == "secret"]
    print("== %s (%s): killed_by_total=%d sample_killed=%d secret_killed=%d first=%s"
          % (w["name"], exe, len(killed_by), len(samples), len(secrets),
             killed_by[0] if killed_by else "NONE"))
    print("   secret killers:", [v[0] for v in secrets][:6])
