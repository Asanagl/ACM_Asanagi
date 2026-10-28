import random
import subprocess
import sys
from pathlib import Path

BASE = Path(__file__).resolve().parent
BIN = Path(r"C:/Users/Asanagi/eropch-blog/.tmp/20-bin")
ROUNDS = 100
SEED = 12345


def run(name, data):
    return subprocess.run([str(BIN / f"{name}.exe")], input=data, capture_output=True, timeout=30)


def oracle(n, m, a):
    total = 0
    for i in range(n):
        for j in range(m):
            if i == 0 or i == n - 1 or j == 0 or j == m - 1:
                total += a[i][j]
    return total


def build_input(n, m, a):
    # The judge harness feeds CRLF-terminated input to validators on Windows,
    # because generator stdout is written in text mode. Mirror that exactly.
    lines = [f"{n} {m}"]
    for row in a:
        lines.append(" ".join(map(str, row)))
    return ("\r\n".join(lines) + "\r\n").encode()


def main():
    rng = random.Random(SEED)
    failures = []
    passed = 0

    for rnd in range(1, ROUNDS + 1):
        shape = rng.choice(["tiny", "tiny", "narrow", "wide", "square", "random"])
        if shape == "tiny":
            n = rng.randint(1, 3)
            m = rng.randint(1, 3)
        elif shape == "narrow":
            n = rng.randint(1, 8)
            m = rng.randint(1, 2)
        elif shape == "wide":
            n = rng.randint(1, 2)
            m = rng.randint(1, 8)
        elif shape == "square":
            n = m = rng.randint(1, 6)
        else:
            n = rng.randint(1, 7)
            m = rng.randint(1, 7)

        mode = rng.choice(["small", "small", "signed", "extreme"])
        if mode == "small":
            lo, hi = -3, 3
        elif mode == "signed":
            lo, hi = -50, 50
        else:
            lo, hi = -10 ** 7, 10 ** 7

        a = [[rng.randint(lo, hi) for _ in range(m)] for _ in range(n)]
        if mode == "extreme" and rng.random() < 0.5:
            for i in range(n):
                for j in range(m):
                    a[i][j] = rng.choice([-10 ** 7, 10 ** 7])

        data = build_input(n, m, a)
        expect = oracle(n, m, a)

        v = run("validator", data)
        if v.returncode != 0:
            failures.append((rnd, "validator", v.stderr.decode(errors="replace")[:200]))
            continue

        main_out = run("solution", data)
        alt_out = run("solution2", data)
        if main_out.returncode != 0:
            failures.append((rnd, "main-re", main_out.stderr.decode(errors="replace")[:200]))
            continue
        if alt_out.returncode != 0:
            failures.append((rnd, "solution2-re", alt_out.stderr.decode(errors="replace")[:200]))
            continue

        got_main = main_out.stdout.decode().strip()
        got_alt = alt_out.stdout.decode().strip()
        if got_main != str(expect):
            failures.append((rnd, f"main {shape} {n}x{m} {mode}", f"got {got_main} want {expect}"))
            continue
        if got_alt != str(expect):
            failures.append((rnd, f"solution2 {shape} {n}x{m} {mode}", f"got {got_alt} want {expect}"))
            continue
        passed += 1

    print(f"seed={SEED} rounds_requested={ROUNDS} rounds_passed={passed} failures={len(failures)}")
    for f in failures[:10]:
        print("FAIL", f)
    return 0 if not failures else 1


if __name__ == "__main__":
    sys.exit(main())
