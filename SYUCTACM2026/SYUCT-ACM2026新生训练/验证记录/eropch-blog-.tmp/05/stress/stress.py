import random
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
MAIN = HERE / "main.exe"
REF = HERE / "ref.exe"


def oracle(s: str, x: str, y: str) -> str:
    out = []
    for c in s:
        out.append(y if c == x else c)
    return "".join(out)


def run(exe: Path, data: str) -> str:
    proc = subprocess.run(
        [str(exe)],
        input=data.encode(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=20,
    )
    if proc.returncode != 0:
        raise RuntimeError(f"{exe.name} exit {proc.returncode}: {proc.stderr.decode(errors='replace')}")
    return proc.stdout.decode().replace("\r\n", "\n")


def make_case(rng: random.Random):
    mode = rng.randrange(6)
    if mode == 0:
        n = rng.randint(1, 4)
        alpha = "ab"
    elif mode == 1:
        n = rng.randint(1, 20)
        alpha = "abc"
    elif mode == 2:
        n = rng.randint(1, 200)
        alpha = "abcdefghijklmnopqrstuvwxyz"
    elif mode == 3:
        n = rng.randint(1, 50)
        alpha = "ab"
    elif mode == 4:
        n = rng.choice([1, 2, 3, 99, 100, 1000])
        alpha = "q"
    else:
        n = rng.randint(1, 500)
        alpha = "".join(rng.sample("abcdefghijklmnopqrstuvwxyz", rng.randint(1, 4)))
    s = "".join(rng.choice(alpha) for _ in range(n))
    if rng.random() < 0.5:
        x = rng.choice(alpha)
    else:
        x = rng.choice("abcdefghijklmnopqrstuvwxyz")
    if rng.random() < 0.25:
        y = x
    else:
        y = rng.choice("abcdefghijklmnopqrstuvwxyz")
    return s, x, y, mode


def main() -> int:
    seed = int(sys.argv[1]) if len(sys.argv) > 1 else 12345
    rounds = int(sys.argv[2]) if len(sys.argv) > 2 else 100
    rng = random.Random(seed)
    stats = {}
    for i in range(rounds):
        s, x, y, mode = make_case(rng)
        data = f"{s}\n{x} {y}\n"
        expected = oracle(s, x, y)
        got_main = run(MAIN, data).rstrip("\n")
        got_ref = run(REF, data).rstrip("\n")
        if got_main != expected:
            HERE.joinpath("counterexample-main.in").write_text(data)
            print(f"FAIL main at round {i+1}: s={s!r} x={x!r} y={y!r}")
            print(f"  expected={expected!r} got={got_main!r}")
            return 1
        if got_ref != expected:
            HERE.joinpath("counterexample-ref.in").write_text(data)
            print(f"FAIL ref at round {i+1}: s={s!r} x={x!r} y={y!r}")
            print(f"  expected={expected!r} got={got_ref!r}")
            return 1
        stats[mode] = stats.get(mode, 0) + 1
    print(f"OK rounds={rounds} seed={seed} modes={stats}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
