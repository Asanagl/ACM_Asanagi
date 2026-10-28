import random, subprocess, sys

BIN = 'bin/'

def run(prog, inp):
    p = subprocess.run([BIN + prog], input=inp, capture_output=True, text=True)
    return p.stdout.strip(), p.returncode

def oracle(s, t):
    n, m = len(s), len(t)
    for i in range(n - m + 1):
        if s[i:i + m] == t:
            return str(i)
    return "-1"

random.seed(12345)
ROUNDS = 100
edge_fail = []
ok = 0

# Fixed edge cases always executed first, then randomized rounds to fill the 100.
edge = [
    ("a", "a"), ("a", "b"), ("ab", "ab"), ("ab", "ba"), ("aa", "aa"),
    ("aaaa", "aa"), ("aaaa", "aab"), ("aaaaa", "aaa"), ("abc", "c"),
    ("abc", "abc"), ("abababab", "abab"), ("mississippi", "issip"),
    ("abab", "bab"), ("aaaaaaa", "aaaaaa"), ("zyx", "xyz"),
    ("aaaab", "aaaab"), ("baaa", "aa"), ("abcabcabd", "abcabd"),
]

records = []
for s, t in edge:
    inp = s + "\n" + t + "\n"
    exp = oracle(s, t)
    o1, rc1 = run("main.exe", inp)
    o2, rc2 = run("sol2.exe", inp)
    good = rc1 == 0 and rc2 == 0 and o1 == exp and o2 == exp
    records.append((s, t, exp, o1, o2, good))
    if good:
        ok += 1
    else:
        edge_fail.append((s, t, exp, o1, rc1, o2, rc2))

while len(records) < ROUNDS:
    r = len(records)
    kind = r % 6
    if kind == 0:                       # tiny alphabet, tiny length
        n = random.randint(1, 12)
        m = random.randint(1, n)
        al = random.choice(["a", "ab"])
        s = "".join(random.choice(al) for _ in range(n))
        t = "".join(random.choice(al) for _ in range(m))
    elif kind == 1:                     # three-letter alphabet
        n = random.randint(1, 60)
        m = random.randint(1, n)
        s = "".join(random.choice("abc") for _ in range(n))
        t = "".join(random.choice("abc") for _ in range(m))
    elif kind == 2:                     # periodic shapes, overlap heavy
        n = random.randint(1, 80)
        m = random.randint(1, n)
        unit = "".join(random.choice("ab") for _ in range(random.randint(1, 3)))
        s = (unit * (n // len(unit) + 1))[:n]
        t = (unit * (m // len(unit) + 1))[:m]
    elif kind == 3:                     # guaranteed occurrence (embedded substring)
        n = random.randint(1, 200)
        m = random.randint(1, n)
        s = "".join(random.choice("ab") for _ in range(n))
        p = random.randint(0, n - m)
        t = s[p:p + m]
    elif kind == 4:                     # guaranteed absent (flip the tail)
        n = random.randint(2, 300)
        m = random.randint(1, n)
        s = "".join(random.choice("ab") for _ in range(n))
        t = "".join(random.choice("ab") for _ in range(m))
        t = ("a" if t[-1] == "b" else "b") + t[1:]
    else:                               # full alphabet mix
        n = random.randint(1, 500)
        m = random.randint(1, n)
        s = "".join(chr(97 + random.randint(0, 25)) for _ in range(n))
        if random.random() < 0.5:
            p = random.randint(0, n - m)
            t = s[p:p + m]
        else:
            t = "".join(chr(97 + random.randint(0, 25)) for _ in range(m))
    inp = s + "\n" + t + "\n"
    exp = oracle(s, t)
    o1, rc1 = run("main.exe", inp)
    o2, rc2 = run("sol2.exe", inp)
    good = rc1 == 0 and rc2 == 0 and o1 == exp and o2 == exp
    records.append((s, t, exp, o1, o2, good))
    if good:
        ok += 1
    else:
        edge_fail.append((s, t, exp, o1, rc1, o2, rc2))

print(f"seed=12345 rounds={len(records)} pass={ok} fail={len(edge_fail)}")
for x in edge_fail[:5]:
    print("FAIL", repr(x))
sys.exit(1 if edge_fail else 0)
