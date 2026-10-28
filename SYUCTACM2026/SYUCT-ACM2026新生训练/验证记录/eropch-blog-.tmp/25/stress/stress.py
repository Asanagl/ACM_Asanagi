import random
import subprocess
import sys

BIN = r"C:\Users\Asanagi\eropch-blog\.tmp\25\bin"
ROUNDS_CONFIG = [
    # (rounds, maxlen, alphabet, label)
    (100, 30, "ab", "small-binary"),
    (100, 30, "abc", "small-ternary"),
    (100, 300, "abc", "medium-ternary"),
]


def run(exe, data):
    p = subprocess.run([exe], input=data, capture_output=True, text=True, timeout=10)
    if p.returncode != 0:
        raise RuntimeError(f"{exe} exited {p.returncode}: {p.stderr[:400]}")
    return p.stdout.split()


def brute(s):
    n = len(s)
    for ln in range(1, n + 1):
        if n % ln != 0:
            continue
        if all(s[i] == s[i % ln] for i in range(ln, n)):
            return [str(ln), s[:ln]]
    raise AssertionError("unreachable")


def gen_case(rng, maxlen, alphabet):
    kind = rng.randrange(6)
    n = rng.randrange(1, maxlen + 1)
    if kind == 0:
        # 完全随机
        return "".join(rng.choice(alphabet) for _ in range(n))
    if kind == 1:
        # 整次重复：t^k
        ln = rng.randrange(1, n + 1)
        t = "".join(rng.choice(alphabet) for _ in range(ln))
        k = max(1, n // ln)
        return t * k
    if kind == 2:
        # 末尾多出不完整周期
        ln = rng.randrange(2, max(3, n // 2 + 1))
        t = "".join(rng.choice(alphabet) for _ in range(ln))
        k = max(1, n // ln)
        r = rng.randrange(1, ln)
        return t * k + t[:r]
    if kind == 3:
        # 全相同
        return rng.choice(alphabet) * n
    if kind == 4:
        # 前后缀结构 p + x + p
        plen = rng.randrange(1, max(2, n // 2))
        p = "".join(rng.choice(alphabet) for _ in range(plen))
        x = "".join(rng.choice(alphabet) for _ in range(max(1, n - 2 * plen)))
        return p + x + p
    # 近全同：只改一个字符
    s = [rng.choice(alphabet)] * n
    if n >= 2:
        i = rng.randrange(n)
        s[i] = rng.choice([c for c in alphabet if c != s[i]])
    return "".join(s)


def main():
    rng = random.Random(12345)
    total = 0
    for rounds, maxlen, alphabet, label in ROUNDS_CONFIG:
        for r in range(rounds):
            s = gen_case(rng, maxlen, alphabet)
            data = s + "\n"
            expected = brute(s)
            for name in ("solution", "solution2", "blind-solution"):
                got = run(BIN + "\\" + name + ".exe", data)
                if got != expected:
                    print(f"[MISMATCH] round={total} label={label} solver={name}")
                    print(f"  input: {s!r}")
                    print(f"  brute: {expected}")
                    print(f"  {name}: {got}")
                    with open(r"stress-counterexample.txt", "w") as fh:
                        fh.write(data)
                    sys.exit(1)
            total += 1
        print(f"[PASS] {label}: {rounds} rounds")
    print(f"[OK] stress passed: {total} rounds total (seed=12345)")


if __name__ == "__main__":
    main()
