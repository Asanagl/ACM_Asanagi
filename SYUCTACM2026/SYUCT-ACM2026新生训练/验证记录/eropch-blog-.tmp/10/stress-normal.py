import random
import subprocess
import sys

TMP = r"C:/Users/Asanagi/eropch-blog/.tmp/10"
ROUNDS = 120
SEED = 12345


def run(exe, data):
    p = subprocess.run([exe], input=data, capture_output=True, text=True, timeout=10)
    return p.stdout.strip()


def oracle(s):
    # 独立第三方 oracle：用 Python 内置的 int 映射构造数字和，
    # 与两份 C++ 的解法和遍历方式均无关。
    return str(sum(int(c) for c in s))


random.seed(SEED)
mismatches = 0
for i in range(ROUNDS):
    shape = i % 6
    if shape == 0:
        n = random.randint(1, 4)
        s = "".join(random.choice("0123456789") for _ in range(n))
    elif shape == 1:
        n = random.randint(1, 40)
        s = "".join(random.choice("0123456789") for _ in range(n))
    elif shape == 2:
        n = random.randint(2, 30)
        s = "0" * random.randint(1, n - 1) + "".join(
            random.choice("0123456789") for _ in range(n)
        )
    elif shape == 3:
        s = random.choice(["0", "9", "00", "0000", "9" * 5, "1" + "0" * 20])
    elif shape == 4:
        pat = "".join(random.choice("0123456789") for _ in range(random.randint(1, 6)))
        s = (pat * 30)[: random.randint(len(pat), 60)]
    else:
        n = random.randint(1, 12)
        s = "".join(random.choice("019") for _ in range(n))
    data = s + "\n"
    a = run(TMP + "/bin/solution.exe", data)
    b = run(TMP + "/bin/solution2.exe", data)
    c = oracle(s)
    if not (a == b == c):
        mismatches += 1
        print(f"MISMATCH round {i}: s={s!r} main={a!r} ref={b!r} oracle={c!r}")
        if mismatches >= 5:
            print("ABORT after 5 mismatches")
            sys.exit(1)

if mismatches:
    sys.exit(1)
print(f"stress OK: {ROUNDS} rounds, seed {SEED}, main == reference == oracle on all rounds")
