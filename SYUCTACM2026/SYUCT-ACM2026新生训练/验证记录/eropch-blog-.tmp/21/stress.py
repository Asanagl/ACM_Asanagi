import random, subprocess, sys, os

BIN = os.path.abspath(os.path.join(os.path.dirname(__file__), "bin"))

def brute(n, m, g):
    out = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            c = 0
            for di, dj in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                ni, nj = i + di, j + dj
                if 0 <= ni < n and 0 <= nj < m and g[ni][nj] == "1":
                    c += 1
            out[i][j] = c
    return "\n".join(" ".join(map(str, r)) for r in out) + "\n"

def run(exe, data):
    p = subprocess.run([os.path.join(BIN, exe)], input=data, capture_output=True, text=True, timeout=30)
    if p.returncode != 0:
        raise RuntimeError(f"{exe} exit={p.returncode} err={p.stderr[:400]}")
    return p.stdout

def norm(s):
    return s.split()

def main():
    rounds = int(sys.argv[1]) if len(sys.argv) > 1 else 100
    seed = 12345
    rnd = random.Random(seed)
    fails = 0
    for t in range(1, rounds + 1):
        n = rnd.randint(1, 7)
        m = rnd.randint(1, 7)
        p1 = rnd.choice([0, 5, 30, 50, 70, 95, 100])
        g = ["".join("1" if rnd.randint(1, 100) <= p1 else "0" for _ in range(m)) for _ in range(n)]
        data = f"{n} {m}\n" + "\n".join(g) + "\n"
        expect = norm(brute(n, m, g))
        for exe in ("solution.exe", "solution2.exe"):
            got = norm(run(exe, data))
            if got != expect:
                fails += 1
                print(f"MISMATCH round={t} exe={exe} n={n} m={m}")
                print(data)
                print("expected:", " ".join(expect))
                print("got     :", " ".join(got))
                if fails >= 3:
                    print(f"STRESS FAILED after {t} rounds")
                    return 1
        # validator 必须接受
        pv = subprocess.run([os.path.join(BIN, "validator.exe")], input=data, capture_output=True, text=True)
        if pv.returncode != 0:
            print(f"VALIDATOR REJECT round={t}: {pv.stderr[:300]}")
            return 1
    print(f"STRESS OK: {rounds} rounds, seed={seed}, mismatches={fails}")
    return 0

sys.exit(main())
