import random
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
MAIN = HERE / "main.exe"
REF = HERE / "ref.exe"


def run(exe: Path, data: bytes) -> str:
    p = subprocess.run([str(exe)], input=data, stdout=subprocess.PIPE,
                       stderr=subprocess.PIPE, timeout=60)
    if p.returncode != 0:
        raise RuntimeError(f"{exe.name} exit {p.returncode}")
    return p.stdout.decode().replace("\r\n", "\n").rstrip("\n")


def main() -> int:
    seed = int(sys.argv[1]) if len(sys.argv) > 1 else 12345
    rounds = int(sys.argv[2]) if len(sys.argv) > 2 else 60
    rng = random.Random(seed)
    for i in range(rounds):
        n = rng.choice([1, 2, 3, 4095, 4096, 99999, 100000])
        alpha = rng.choice(["a", "ab", "abc", "abcdefghijklmnopqrstuvwxyz"])
        s = "".join(rng.choice(alpha) for _ in range(n))
        x = rng.choice(alpha + "z")
        y = x if rng.random() < 0.2 else rng.choice("abcdefghijklmnopqrstuvwxyz")
        expected = "".join(y if c == x else c for c in s)
        eol = "\r\n" if i % 2 == 0 else "\n"
        data = (s + eol + x + " " + y + eol).encode()
        got_main = run(MAIN, data)
        got_ref = run(REF, data)
        if got_main != expected or got_ref != expected:
            print(f"FAIL round={i+1} n={n} x={x!r} y={y!r} eol={eol!r}")
            print(f" main_ok={got_main == expected} ref_ok={got_ref == expected}")
            return 1
    print(f"OK rounds={rounds} seed={seed} (mixed LF/CRLF, lengths up to 100000)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
