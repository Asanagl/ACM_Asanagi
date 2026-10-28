import os
import random
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
BIN = os.path.join(HERE, "bin2")
OUT = os.path.join(HERE, "diff-rounds.log")

EXES = {
    "main": os.path.join(BIN, "main.exe"),
    "solution2": os.path.join(BIN, "solution2.exe"),
    "blind3": os.path.join(BIN, "blind3.exe"),
}

ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
VOWELS_LOWER = "aeiou"
VOWELS_UPPER = "AEIOU"
CONSONANTS = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"
TRAP = "yYyYaeiouAEIOUzZ"


def oracle(s):
    """Independent reference: explicit 10-character membership, no folding, no shared code."""
    table = {
        "a": 0, "A": 0,
        "e": 1, "E": 1,
        "i": 2, "I": 2,
        "o": 3, "O": 3,
        "u": 4, "U": 4,
    }
    cnt = [0, 0, 0, 0, 0]
    for ch in s:
        if ch in table:
            cnt[table[ch]] += 1
    return " ".join(str(x) for x in cnt)


def run(exe, data):
    p = subprocess.run([exe], input=data, capture_output=True, timeout=120)
    return p.returncode, p.stdout.decode("utf-8", "replace").strip(), p.stderr.decode("utf-8", "replace")


def gen_case(idx):
    mode = idx % 10
    if mode == 0:
        n = random.randint(1, 3)
        return "".join(random.choice(TRAP) for _ in range(n))
    if mode == 1:
        n = random.randint(1, 12)
        return "".join(random.choice(ALPHABET) for _ in range(n))
    if mode == 2:
        n = random.randint(1, 60)
        return "".join(random.choice(VOWELS_LOWER) for _ in range(n))
    if mode == 3:
        n = random.randint(1, 60)
        return "".join(random.choice(VOWELS_UPPER) for _ in range(n))
    if mode == 4:
        n = random.randint(1, 60)
        return "".join(random.choice(VOWELS_LOWER + VOWELS_UPPER) for _ in range(n))
    if mode == 5:
        n = random.randint(1, 200)
        return "".join(random.choice(CONSONANTS) for _ in range(n))
    if mode == 6:
        n = random.randint(1, 120)
        return "".join(random.choice("yY") for _ in range(n))
    if mode == 7:
        n = random.randint(1, 400)
        return "".join(random.choice("uU" + ALPHABET) for _ in range(n))
    if mode == 8:
        n = random.randint(1, 2000)
        return "".join(random.choice(ALPHABET) for _ in range(n))
    n = random.randint(1, 5000)
    s = "".join(random.choice(ALPHABET) for _ in range(n))
    if idx % 3 == 0 and s:
        cut = random.randint(0, len(s) - 1)
        s = s[:cut] + random.choice("yY") + s[cut + 1:]
    return s


ROUNDS = 120
random.seed(12345)

lines = []
fails = 0
lines.append("seed=12345 rounds=%d" % ROUNDS)
lines.append("oracle = explicit 10-char membership table (no case folding, no shared code)")
lines.append("")

for i in range(ROUNDS):
    s = gen_case(i)
    data = (s + "\n").encode()
    exp = oracle(s)
    got = {}
    ok = True
    for name, exe in EXES.items():
        try:
            rc, out, err = run(exe, data)
        except subprocess.TimeoutExpired:
            rc, out, err = -1, "<timeout>", ""
        got[name] = out
        if rc != 0 or out != exp:
            ok = False
            lines.append("MISMATCH round=%d program=%s rc=%d len=%d" % (i + 1, name, rc, len(s)))
            lines.append("  case_head=%r" % s[:100])
            lines.append("  expected=%r" % exp)
            lines.append("  got     =%r" % out)
            if err:
                lines.append("  stderr  =%r" % err[:200])
    if not ok:
        fails += 1
    if (i + 1) % 20 == 0 or not ok:
        lines.append("round %3d len=%-5d expected=%-32r main=%-32r s2=%-32r blind3=%r %s"
                     % (i + 1, len(s), exp, got["main"], got["solution2"], got["blind3"],
                        "OK" if ok else "FAIL"))

# Directed boundary cases, also cross-checked against the oracle.
directed = [
    ("single-a", "a"),
    ("single-A", "A"),
    ("single-y", "y"),
    ("single-Y", "Y"),
    ("single-z", "z"),
    ("sample1", "HeLloWorld"),
    ("sample2", "AEIOUaeiou"),
    ("sample3", "yes"),
    ("all-consonant", "bcdfghjklmnpqrstvwxyz"),
    ("all-y", "yYyYyY"),
    ("uoiea", "uoiea"),
    ("reverse-order", "uoieaAEIOU"),
    ("max-a", "a" * 1000000),
    ("max-A", "A" * 1000000),
    ("max-u", "u" * 1000000),
    ("max-U", "U" * 1000000),
    ("max-cons", "b" * 1000000),
    ("max-y", "y" * 1000000),
    ("max-mix", "aAeEiIoOuU" * 100000),
    ("near-max", "".join(random.choice(ALPHABET) for _ in range(999999))),
]

lines.append("")
lines.append("=== directed boundary cases ===")
for name, s in directed:
    data = (s + "\n").encode()
    exp = oracle(s)
    row = []
    ok = True
    for pname, exe in EXES.items():
        rc, out, err = run(exe, data)
        row.append(out)
        if rc != 0 or out != exp:
            ok = False
            lines.append("MISMATCH directed=%s program=%s rc=%d" % (name, pname, rc))
            lines.append("  expected=%r got=%r" % (exp, out))
    if not ok:
        fails += 1
    lines.append("%-14s len=%-8d expected=%-30r main=%-30r s2=%-30r blind3=%r %s"
                 % (name, len(s), exp, row[0], row[1], row[2], "OK" if ok else "FAIL"))

lines.append("")
lines.append("TOTAL_ROUNDS=%d (seed 12345, small-data biased) DIRECTED=%d FAILS=%d"
             % (ROUNDS, len(directed), fails))

with open(OUT, "w", encoding="utf-8") as f:
    f.write("\n".join(lines) + "\n")

print("\n".join(lines[-8:]))
print("FAILS", fails)
sys.exit(0 if fails == 0 else 1)
