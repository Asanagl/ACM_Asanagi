import os, random, subprocess, sys

BIN = r"C:\Users\Asanagi\eropch-blog\.tmp\03-verify\bin"
WORK = r"C:\Users\Asanagi\eropch-blog\.tmp\03-verify"

def run(exe, data):
    p = subprocess.run([os.path.join(BIN, exe)], input=data, capture_output=True, text=True, timeout=30)
    return p.returncode, p.stdout, p.stderr

def oracle(s):
    # independent brute force: count by explicit per-vowel substring scans, no shared code
    out = []
    for v in ["a", "e", "i", "o", "u"]:
        n = 0
        for ch in s:
            low = chr(ord(ch) | 0x20)          # ASCII fold via bit trick
            up = low.upper()
            if up == v.upper():
                n += 1
        out.append(n)
    return " ".join(map(str, out))

ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
SPECIAL = "aeiouAEIOUyYzZ"

random.seed(12345)
fails = 0
rounds = 0
for i in range(140):
    mode = i % 6
    if mode == 0:
        n = random.randint(1, 3)
        s = "".join(random.choice(SPECIAL) for _ in range(n))
    elif mode == 1:
        n = random.randint(1, 40)
        s = "".join(random.choice(ALPHABET) for _ in range(n))
    elif mode == 2:
        n = random.randint(1, 200)
        s = "".join(random.choice("aeiou") for _ in range(n))
    elif mode == 3:
        n = random.randint(1, 200)
        s = "".join(random.choice("AEIOU") for _ in range(n))
    elif mode == 4:
        n = random.randint(1, 2000)
        s = "".join(random.choice("bcdfghjklmnpqrstvwxyz") for _ in range(n))
    else:
        n = random.randint(1, 5000)
        s = "".join(random.choice(ALPHABET) for _ in range(n))
    data = s + "\n"
    exp = oracle(s)
    rc1, o1, e1 = run("solution.exe", data)
    rc2, o2, e2 = run("solution2.exe", data)
    rounds += 1
    if rc1 != 0 or rc2 != 0 or o1.strip() != exp or o2.strip() != exp:
        fails += 1
        print("MISMATCH round", rounds, "len", len(s))
        print(" s=", s[:120])
        print(" exp=", exp, " main=", o1.strip(), " ref=", o2.strip(), " rc", rc1, rc2)
        if fails > 3:
            break

# boundary differential
cases = {
    "single-a": "a",
    "single-A": "A",
    "single-y": "y",
    "single-Y": "Y",
    "single-z": "z",
    "emptyvowel": "bcdfg",
    "all": "AEIOUaeiou",
    "max-a": "a" * 1000000,
    "max-A": "A" * 1000000,
    "max-u": "u" * 1000000,
    "max-U": "U" * 1000000,
    "max-cons": "b" * 1000000,
    "max-mix": ("aAeEiIoOuU" * 100000),
}
for name, s in cases.items():
    data = s + "\n"
    exp = oracle(s)
    rc1, o1, _ = run("solution.exe", data)
    rc2, o2, _ = run("solution2.exe", data)
    rounds += 1
    ok = rc1 == 0 and rc2 == 0 and o1.strip() == exp and o2.strip() == exp
    print(("OK   " if ok else "FAIL ") + name, "len", len(s), "->", o1.strip())
    if not ok:
        fails += 1
        print("  exp", exp, "ref", o2.strip(), "rc", rc1, rc2)

print("ROUNDS", rounds, "FAILS", fails)
sys.exit(0 if fails == 0 else 1)
