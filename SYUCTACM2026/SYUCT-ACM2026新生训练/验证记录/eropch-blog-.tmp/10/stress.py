import random
import subprocess
import sys

TMP = r"C:/Users/Asanagi/eropch-blog/.tmp/10"
ROUNDS = 200
SEED = 12345


def run(exe, data):
    p = subprocess.run([exe], input=data, capture_output=True, text=True, timeout=10)
    return p.stdout.strip()


def oracle(s):
    # 独立第三方 oracle：直接用 int 映射每个字符。
    return str(sum(int(c) for c in s))


random.seed(SEED)
for i in range(ROUNDS):
    shape = i % 5
    if shape == 0:
        n = random.randint(1, 50)
        s = "".join(random.choice("0123456789") for _ in range(n))
    elif shape == 1:
        n = random.randint(1, 20)
        s = "0" * random.randint(0, n - 1) + "".join(
            random.choice("0123456789") for _ in range(n)
        )
        if set(s) == {"0"}:
            s = s[:-1] + "7"
    elif shape == 2:
        s = random.choice(["0", "9", "0000", "999999999999999999"])
    elif shape == 3:
        n = random.randint(2, 40)
        pat = "".join(random.choice("0123456789") for _ in range(n))
        s = (pat * random.randint(1, 3))[: 80]
    else:
        n = random.randint(1, 10)
        s = "".join(random.choice("019") for _ in range(n))
    data = s + "\n"
    a = run(TMP + "/sol1.exe", data)
    b = run(TMP + "/sol2.exe", data)
    c = oracle(s)
    if not (a == b == c):
        print(f"MISMATCH round {i}: s={s!r} main={a} ref={b} oracle={c}")
        sys.exit(1)
print(f"stress OK: {ROUNDS} rounds, seed {SEED}, main == reference == oracle on all rounds")
