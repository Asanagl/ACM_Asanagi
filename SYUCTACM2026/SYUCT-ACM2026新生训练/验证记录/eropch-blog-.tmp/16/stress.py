import io
import os
import random
import subprocess
import sys

ROOT = os.path.dirname(os.path.abspath(__file__))
PROBLEM = os.path.join(
    ROOT, "..", "..",
    "problemsets", "2026syuctacm-weekly-04", "problems", "16",
)
MAIN = os.path.join(ROOT, "solution.exe")
REF = os.path.join(ROOT, "solution2.exe")

SEED = 12345
ROUNDS = 150


def oracle(n, a):
    main_sum = 0
    anti_sum = 0
    for i in range(n):
        for j in range(n):
            if i == j:
                main_sum += a[i][j]
            if i + j == n - 1:
                anti_sum += a[i][j]
    return main_sum, anti_sum


def run(exe, text):
    p = subprocess.run(
        [exe], input=text.encode(), stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )
    if p.returncode != 0:
        raise RuntimeError("%s exited %d: %s" % (exe, p.returncode, p.stderr.decode(errors="replace")))
    return p.stdout.decode()


def parse(out):
    toks = out.split()
    if len(toks) != 2:
        raise ValueError("expected 2 tokens, got %r" % out)
    return int(toks[0]), int(toks[1])


def main():
    rng = random.Random(SEED)
    same = 0
    for r in range(1, ROUNDS + 1):
        n = rng.choice([1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8])

        # 元素取值形态轮换：全范围 / 小范围 / 含极值 / 全零
        mode = r % 4
        if mode == 0:
            lo, hi = -1000000000, 1000000000
        elif mode == 1:
            lo, hi = -9, 9
        elif mode == 2:
            lo, hi = -10, 10
        else:
            lo, hi = 0, 0

        a = [[rng.randint(lo, hi) for _ in range(n)] for _ in range(n)]
        if mode == 2:
            # 把部分位置压到取值边界
            for _ in range(2):
                a[rng.randrange(n)][rng.randrange(n)] = rng.choice([-1000000000, 1000000000])

        lines = [str(n)]
        for row in a:
            lines.append(" ".join(str(x) for x in row))
        text = "\n".join(lines) + "\n"

        exp = oracle(n, a)
        got_main = parse(run(MAIN, text))
        got_ref = parse(run(REF, text))

        if got_main != exp:
            print("MISMATCH main round=%d n=%d" % (r, n))
            print(text)
            print("expected", exp, "got", got_main)
            return 1
        if got_ref != exp:
            print("MISMATCH ref round=%d n=%d" % (r, n))
            print(text)
            print("expected", exp, "got", got_ref)
            return 1
        same += 1

    print("stress OK: seed=%d rounds=%d agreed=%d" % (SEED, ROUNDS, same))
    return 0


if __name__ == "__main__":
    sys.exit(main())
