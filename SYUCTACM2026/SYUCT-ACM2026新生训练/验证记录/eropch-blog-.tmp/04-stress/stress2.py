"""Differential stress for SYUCTOJ 04 (大小写互换).

Fixed seed 12345, >= 100 rounds of small random data.
Each round:
  * build a small string from a rotating pool (minimum / boundary / repeat /
    targeted / random shapes),
  * run the strict validator on it (must accept),
  * run main and solution2 and an independent Python oracle,
  * require all three to agree byte-for-byte.
"""

import os
import random
import subprocess
import sys

BIN = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "04", "bin")
os.environ["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + os.environ["PATH"]

MAIN = os.path.join(BIN, "main.exe")
SOL2 = os.path.join(BIN, "sol2.exe")
VAL = os.path.join(BIN, "val.exe")

SEED = 12345
ROUNDS = 120

FULL = [chr(c) for c in range(32, 127)]
LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
NONLETTER = [c for c in FULL if c not in LETTERS]
BOUNDARY = list("AZaz[\\]^_`@{")


def oracle(s: str) -> str:
    out = []
    for c in s:
        if "A" <= c <= "Z":
            out.append(chr(ord(c) + 32))
        elif "a" <= c <= "z":
            out.append(chr(ord(c) - 32))
        else:
            out.append(c)
    return "".join(out)


def norm(b: bytes) -> bytes:
    return b.replace(b"\r\n", b"\n")


def gen(rng: random.Random, kind: int) -> str:
    if kind == 0:
        n = rng.randint(1, 40)
        return "".join(rng.choice(FULL) for _ in range(n))
    if kind == 1:
        n = rng.randint(1, 40)
        return "".join(rng.choice(LETTERS) for _ in range(n))
    if kind == 2:
        n = rng.randint(1, 40)
        return "".join(rng.choice(NONLETTER) for _ in range(n))
    if kind == 3:
        n = rng.randint(1, 40)
        return "".join(rng.choice(BOUNDARY) for _ in range(n))
    if kind == 4:
        n = rng.randint(1, 40)
        return " " * n
    if kind == 5:
        # repeats
        ch = rng.choice(LETTERS + " ~0")
        return ch * rng.randint(1, 40)
    if kind == 6:
        # alternating
        a, b = rng.choice([("a", "A"), ("A", "a"), ("z", "Z"), ("!", "a")])
        n = rng.randint(1, 40)
        return "".join(a if i % 2 == 0 else b for i in range(n))
    if kind == 7:
        # leading/trailing spaces
        core = "".join(rng.choice(LETTERS + "09!") for _ in range(rng.randint(0, 20)))
        return " " * rng.randint(1, 6) + core + " " * rng.randint(1, 6)
    if kind == 8:
        # full printable sweep, possibly truncated
        n = rng.randint(1, 95)
        start = rng.randint(0, 95 - n)
        return "".join(chr(32 + start + i) for i in range(n))
    # single character edge cases
    return rng.choice("AaZz0 ~[]\\^_`@{")


def main() -> int:
    rng = random.Random(SEED)
    for it in range(1, ROUNDS + 1):
        kind = (it - 1) % 10
        s = gen(rng, kind)
        data = (s + "\n").encode()

        v = subprocess.run([VAL], input=data, capture_output=True)
        if v.returncode != 0:
            print(f"VALIDATOR REJECT round {it} kind {kind} {s!r} rc={v.returncode}")
            print(v.stderr.decode(errors="replace")[:400])
            return 1

        a = subprocess.run([MAIN], input=data, capture_output=True)
        b = subprocess.run([SOL2], input=data, capture_output=True)
        if a.returncode != 0 or b.returncode != 0:
            print(f"RUNTIME ERROR round {it} {s!r} main={a.returncode} sol2={b.returncode}")
            return 1

        want = (oracle(s) + "\n").encode()
        if norm(a.stdout) != want:
            print(f"MAIN != ORACLE round {it} kind {kind} {s!r}")
            print(f"  main={a.stdout!r}")
            print(f"  want={want!r}")
            return 1
        if norm(b.stdout) != want:
            print(f"SOL2 != ORACLE round {it} kind {kind} {s!r}")
            print(f"  sol2={b.stdout!r}")
            print(f"  want={want!r}")
            return 1
        if norm(a.stdout) != norm(b.stdout):
            print(f"MAIN != SOL2 round {it} {s!r}")
            return 1

    print(f"stress passed: {ROUNDS} rounds, seed {SEED}, {ROUNDS} validator-accepted cases")
    return 0


if __name__ == "__main__":
    sys.exit(main())
