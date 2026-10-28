import os
import random
import subprocess
import sys

WORK = os.path.dirname(os.path.abspath(__file__))
WORK = os.path.join(os.path.dirname(WORK), "work")
ALE = "abcdefghijklmnopqrstuvwxyz0123456789"

ENV = dict(os.environ)
ENV["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + ENV.get("PATH", "")


def run(exe, inp):
    p = subprocess.run([os.path.join(WORK, exe)], input=inp.encode(),
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                       timeout=30, env=ENV)
    return p.returncode, p.stdout.decode(errors="replace").strip()


def main():
    seed = 12345
    rounds = 150
    rng = random.Random(seed)
    bad = 0
    for r in range(rounds):
        mode = r % 5
        n = rng.randint(1, 60)
        if mode == 0:
            s = "".join(rng.choice(ALE) for _ in range(n))
        elif mode == 1:
            s = "".join(rng.choice("ab") for _ in range(n))
        elif mode == 2:
            s = rng.choice(ALE) * n
        elif mode == 3:
            half = "".join(rng.choice(ALE) for _ in range((n + 1) // 2))
            s = (half + half[::-1])[:n]
        else:
            s = "".join(rng.choice("0123456789") for _ in range(n))

        inp = s + ("\n" if rng.random() < 0.5 else "")
        expect = s[::-1]

        rc1, got1 = run("solution.exe", inp)
        rc2, got2 = run("solution2.exe", inp)
        if rc1 != 0 or rc2 != 0 or got1 != expect or got2 != expect:
            bad += 1
            print(f"MISMATCH round={r} s={s!r} expect={expect!r} "
                  f"main={got1!r} ref={got2!r} rc=({rc1},{rc2})")

    print(f"rounds={rounds} seed={seed} mismatches={bad}")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
