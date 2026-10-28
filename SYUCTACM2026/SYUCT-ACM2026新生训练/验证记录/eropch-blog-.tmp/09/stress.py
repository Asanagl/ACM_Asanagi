import random, subprocess, sys, os

BUILD = os.path.join(os.path.dirname(os.path.abspath(__file__)), "build")

def norm(b):
    return b.decode().replace("\r\n", "\n").replace("\r", "\n")

def run(exe, inp):
    p = subprocess.run([os.path.join(BUILD, exe)], input=inp.encode(),
                       capture_output=True, timeout=20)
    return p.returncode, norm(p.stdout), norm(p.stderr)

def brute(s, l, r):
    return "".join(s[i] for i in range(l - 1, r))

rng = random.Random(12345)
ROUNDS = 120
fails = 0
cases = 0

for t in range(1, ROUNDS + 1):
    n = rng.randint(1, 30)
    alpha = rng.choice(["ab", "abc", "abcdefghijklmnopqrstuvwxyz", "a"])
    s = "".join(rng.choice(alpha) for _ in range(n))
    shape = rng.choice(["any", "single", "full", "prefix", "suffix"])
    if shape == "single":
        l = rng.randint(1, n); r = l
    elif shape == "full":
        l, r = 1, n
    elif shape == "prefix":
        l = 1; r = rng.randint(1, n)
    elif shape == "suffix":
        r = n; l = rng.randint(1, n)
    else:
        l = rng.randint(1, n); r = rng.randint(l, n)
    inp = f"{s}\n{l} {r}\n"
    cases += 1

    rc1, out1, err1 = run("solution.exe", inp)
    rc2, out2, err2 = run("solution2.exe", inp)
    expect = brute(s, l, r) + "\n"

    if rc1 != 0 or rc2 != 0:
        print(f"ROUND {t} RE rc1={rc1} rc2={rc2} input={inp!r} err={err1[:200]} {err2[:200]}")
        fails += 1; continue
    if out1 != expect:
        print(f"ROUND {t} main mismatch input={inp!r} got={out1!r} expect={expect!r}")
        fails += 1; continue
    if out2 != expect:
        print(f"ROUND {t} solution2 mismatch input={inp!r} got={out2!r} expect={expect!r}")
        fails += 1; continue
    if out1 != out2:
        print(f"ROUND {t} main!=solution2 input={inp!r} {out1!r} vs {out2!r}")
        fails += 1

for n in range(1, 7):
    for mask in range(1 << n):
        s = "".join("ab"[(mask >> i) & 1] for i in range(n))
        for l in range(1, n + 1):
            for r in range(l, n + 1):
                inp = f"{s}\n{l} {r}\n"
                cases += 1
                rc1, out1, _ = run("solution.exe", inp)
                rc2, out2, _ = run("solution2.exe", inp)
                expect = brute(s, l, r) + "\n"
                if out1 != expect or out2 != expect or rc1 or rc2:
                    print(f"EXHAUST n={n} s={s} l={l} r={r} got={out1!r}/{out2!r} expect={expect!r}")
                    fails += 1

big = "".join(chr(97 + (i % 26)) for i in range(1000))
for l, r in [(1, 1000), (1, 1), (1000, 1000), (500, 500), (2, 999), (1, 999), (2, 1000)]:
    inp = f"{big}\n{l} {r}\n"
    cases += 1
    rc1, out1, _ = run("solution.exe", inp)
    rc2, out2, _ = run("solution2.exe", inp)
    expect = brute(big, l, r) + "\n"
    if out1 != expect or out2 != expect or rc1 or rc2:
        print(f"BIG l={l} r={r} mismatch")
        fails += 1

print(f"ROUNDS(random)={ROUNDS} total_inputs={cases} fails={fails}")
sys.exit(1 if fails else 0)
