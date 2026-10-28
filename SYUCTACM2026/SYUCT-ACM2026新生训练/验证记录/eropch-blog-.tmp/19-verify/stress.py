import random, subprocess, sys

SEED = 12345
ROUNDS = 150
rng = random.Random(SEED)

def oracle(A):
    # clockwise 90 = transpose, then reverse each row
    return [list(r)[::-1] for r in zip(*A)]

def fmt(A):
    n = len(A); m = len(A[0])
    out = [f"{n} {m}"]
    for row in A:
        out.append(" ".join(str(v) for v in row))
    return ("\n".join(out) + "\n").encode()

def run(exe, data):
    p = subprocess.run([exe], input=data, capture_output=True, timeout=120)
    if p.returncode != 0:
        raise RuntimeError(f"{exe} exit {p.returncode}: {p.stderr[:200]}")
    return p.stdout

def norm(b):
    return b.decode().split()

fails = 0
shapes = set()
for t in range(1, ROUNDS + 1):
    mode = t % 6
    if mode == 0:
        n = 1; m = rng.randint(1, 8)
    elif mode == 1:
        n = rng.randint(1, 8); m = 1
    elif mode == 2:
        n = rng.randint(1, 12); m = rng.randint(1, 12)
    elif mode == 3:
        n = rng.randint(1, 30); m = rng.randint(1, 30)
    elif mode == 4:
        n = rng.randint(40, 60); m = rng.randint(1, 6)
    else:
        n = rng.randint(1, 6); m = rng.randint(40, 60)
    shapes.add((n, m))
    vals = rng.choice([[-10**9, 10**9], [0, 0], [0, 1], [-3, 3], [-10**9, 10**9]])
    A = [[rng.randint(vals[0], vals[1]) for _ in range(m)] for _ in range(n)]
    data = fmt(A)
    exp = oracle(A)
    exp_tokens = [str(v) for row in exp for v in row]
    o1 = run("./solution.exe", data)
    o2 = run("./solution2.exe", data)
    if norm(o1) != exp_tokens:
        print(f"ROUND {t}: MAIN MISMATCH n={n} m={m}"); fails += 1; break
    if norm(o2) != exp_tokens:
        print(f"ROUND {t}: SOLUTION2 MISMATCH n={n} m={m}"); fails += 1; break
    # also check line structure: main must emit m lines of n tokens
    lines = [ln for ln in o1.decode().split("\n") if ln.strip() != ""]
    if len(lines) != m or any(len(ln.split()) != n for ln in lines):
        print(f"ROUND {t}: SHAPE MISMATCH n={n} m={m}"); fails += 1; break

print(f"seed={SEED} rounds={ROUNDS} distinct_shapes={len(shapes)} failures={fails}")
sys.exit(1 if fails else 0)
