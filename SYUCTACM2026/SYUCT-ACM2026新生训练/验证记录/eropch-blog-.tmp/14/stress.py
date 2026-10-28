import os, random, subprocess, sys

ROOT = r"C:\Users\Asanagi\eropch-blog"
BUILD = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-14"
BIN = os.path.join(BUILD, "bin")
GEN = os.path.join(BIN, "generator.exe")
WORK = os.path.join(ROOT, ".tmp", "14", "stress")
os.makedirs(WORK, exist_ok=True)

main = os.path.join(BIN, "main.exe")
sol2 = os.path.join(BIN, "solution2.exe")

def oracle(data):
    tok = data.split()
    n, m = int(tok[0]), int(tok[1])
    a = list(map(int, tok[2:]))
    assert len(a) == n * m, (len(a), n * m)
    sums = [sum(a[i * m + j] for i in range(n)) for j in range(m)]
    return " ".join(str(x) for x in sums)

def run(exe, inp):
    p = subprocess.run([exe], input=inp.encode(), capture_output=True, timeout=30)
    if p.returncode != 0:
        return None, "RE rc=%d %s" % (p.returncode, p.stderr[:200])
    return p.stdout.decode().strip(), None

rng = random.Random(12345)
rounds = 100
fail = 0
for t in range(1, rounds + 1):
    # mix: generator stress type with derived seed, plus hand-rolled small random shapes
    if t % 2 == 1:
        seed = str(rng.randrange(1, 10**9))
        p = subprocess.run([GEN, "stress", seed], capture_output=True, timeout=30)
        data = p.stdout.decode()
        tag = "gen-stress seed=" + seed
    else:
        n = rng.randint(1, 7)
        m = rng.randint(1, 7)
        lo, hi = rng.choice([(-5, 5), (-1000000000, 1000000000), (-2, 2)])
        vals = [str(rng.randint(lo, hi)) for _ in range(n * m)]
        data = "%d %d\n" % (n, m)
        data += "\n".join(" ".join(vals[i * m:(i + 1) * m]) for i in range(n)) + "\n"
        tag = "hand n=%d m=%d range=(%d,%d)" % (n, m, lo, hi)

    exp = oracle(data)
    o1, e1 = run(main, data)
    o2, e2 = run(sol2, data)
    ok = (o1 == exp and o2 == exp)
    if not ok:
        fail += 1
        print("MISMATCH round", t, tag)
        print("input:", data[:500])
        print("oracle:", exp)
        print("main  :", o1, e1)
        print("sol2  :", o2, e2)
        open(os.path.join(WORK, "counterexample-%d.in" % t), "w").write(data)
    else:
        print("round %2d ok  %s" % (t, tag))

print("\nrounds:", rounds, "mismatches:", fail)
sys.exit(1 if fail else 0)
