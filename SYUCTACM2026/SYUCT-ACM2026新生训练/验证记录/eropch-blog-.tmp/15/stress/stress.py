import random
import subprocess
import sys


def oracle(grid):
    flat = [v for row in grid for v in row]
    best = max(flat)
    idx = flat.index(best)
    m = len(grid[0])
    return best, idx // m + 1, idx % m + 1


def run(prog, data):
    res = subprocess.run([prog], input=data, capture_output=True, text=True, timeout=30)
    if res.returncode != 0:
        raise RuntimeError(f"{prog} exit={res.returncode} stderr={res.stderr[:300]}")
    return tuple(int(t) for t in res.stdout.split())


def make_case(rng, round_index):
    mode = round_index % 5
    if mode == 0:
        n = rng.randint(1, 4)
        m = rng.randint(1, 4)
        lo, hi = -3, 3
    elif mode == 1:
        n = 1
        m = rng.randint(1, 12)
        lo, hi = -5, 5
    elif mode == 2:
        n = rng.randint(1, 12)
        m = 1
        lo, hi = -5, 5
    elif mode == 3:
        n = rng.randint(1, 9)
        m = rng.randint(1, 9)
        lo, hi = -20, 20
    else:
        n = rng.randint(1, 7)
        m = rng.randint(1, 7)
        lo, hi = -10**9, 10**9
    grid = [[rng.randint(lo, hi) for _ in range(m)] for _ in range(n)]
    # bias towards ties: with some probability force several equal maxima
    if rng.random() < 0.5:
        top = rng.randint(lo, hi)
        k = rng.randint(1, max(1, n * m))
        for _ in range(k):
            r = rng.randrange(n)
            c = rng.randrange(m)
            grid[r][c] = top
    # occasionally force all-negative
    if rng.random() < 0.25:
        for r in range(n):
            for c in range(m):
                if grid[r][c] > -1:
                    grid[r][c] = rng.randint(-1000, -1)
    return grid


def main():
    rounds = int(sys.argv[1]) if len(sys.argv) > 1 else 100
    seed = int(sys.argv[2]) if len(sys.argv) > 2 else 12345
    rng = random.Random(seed)
    failures = 0
    for i in range(rounds):
        grid = make_case(rng, i)
        data = f"{len(grid)} {len(grid[0])}\n" + "\n".join(" ".join(map(str, row)) for row in grid) + "\n"
        exp = oracle(grid)
        got_main = run("./sol.exe", data)
        got_ref = run("./sol2.exe", data)
        if got_main != exp or got_ref != exp:
            failures += 1
            print(f"MISMATCH round={i} expected={exp} main={got_main} ref={got_ref}")
            print(data)
            if failures >= 3:
                break
    print(f"rounds={rounds} seed={seed} failures={failures}")
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
