#!/usr/bin/env python3
"""Fixed-seed differential stress for problem 04-11 (matrix echo).

Two lanes:
  1. script-generated small matrices compared against a plain-text oracle
  2. generator(type=stress) inputs fed through validator, then checked by checker
"""

import io
import random
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PROBLEM = ROOT / "problemsets/2026syuctacm-weekly-04/problems/11"
BIN = ROOT / ".tmp/11/bin"
WORK = ROOT / ".tmp/11/stress-out"
SEED = 12345
ROUNDS = 120


def build_oracle(n, m, values):
    rows = []
    for i in range(n):
        rows.append(" ".join(str(values[i * m + j]) for j in range(m)))
    return "\n".join(rows) + "\n"


def run(exe, data, args=None):
    return subprocess.run(
        [str(exe)] + (args or []),
        input=data,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=30,
    )


def normalize(raw):
    return raw.decode().replace("\r\n", "\n")


def lane_script(rng, index):
    bucket = rng.randrange(10)
    if bucket == 0:
        n, m = 1, 1
    elif bucket == 1:
        n, m = 1, rng.randint(1, 12)
    elif bucket == 2:
        n, m = rng.randint(1, 12), 1
    elif bucket == 3:
        n, m = rng.randint(1, 3), rng.randint(1, 3)
    elif bucket == 4:
        n, m = rng.randint(2, 4), rng.randint(2, 4)
    elif bucket == 5:
        n, m = rng.randint(1, 8), rng.randint(1, 8)
    elif bucket == 6:
        n, m = rng.randint(1, 5), rng.randint(1, 20)
    elif bucket == 7:
        n, m = rng.randint(1, 20), rng.randint(1, 5)
    elif bucket == 8:
        n, m = rng.randint(1, 100), rng.randint(1, 3)
    else:
        n, m = rng.randint(1, 6), rng.randint(1, 100)

    total = n * m
    mode = rng.randrange(4)
    if mode == 0:
        values = [rng.randint(-1000, 1000) for _ in range(total)]
    elif mode == 1:
        values = [rng.choice([-1000, 1000, 0, -1, 1]) for _ in range(total)]
    elif mode == 2:
        values = [rng.choice([-1000, -1, 0, 1, 1000])] * total
    else:
        values = [rng.randint(-3, 3) for _ in range(total)]

    lines = [f"{n} {m}"]
    for i in range(n):
        lines.append(" ".join(str(values[i * m + j]) for j in range(m)))
    data = ("\n".join(lines) + "\n").encode()

    expected = build_oracle(n, m, values)
    main_out = run(BIN / "solution.exe", data)
    ref_out = run(BIN / "solution2.exe", data)
    if main_out.returncode != 0 or ref_out.returncode != 0:
        return (n, m, "nonzero exit", main_out.returncode, ref_out.returncode)
    if normalize(main_out.stdout) != expected:
        return (n, m, "main vs oracle")
    if normalize(ref_out.stdout) != expected:
        return (n, m, "reference vs oracle")

    source = WORK / f"script-{index}.in"
    source.write_bytes(data)
    answer = WORK / f"script-{index}.out"
    answer.write_bytes(main_out.stdout)
    checked = subprocess.run(
        [str(BIN / "checker.exe"), str(source), str(answer), str(answer)],
        capture_output=True,
    )
    if checked.returncode != 0:
        return (n, m, "checker rejected main", checked.stderr[:120])
    return None


def lane_generator(index):
    generated = subprocess.run(
        [str(BIN / "generator.exe"), "stress", str(SEED + index)],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=60,
    )
    if generated.returncode != 0:
        return (0, 0, "generator failed", generated.returncode)
    data = generated.stdout

    source = WORK / f"gen-{index}.in"
    source.write_bytes(data)
    script = WORK / f"gen-{index}.cmd"
    script.write_text(
        "@echo off\r\ntype \"" + str(source) + "\" | \"" + str(BIN / "validator.exe") + "\"\r\nexit /b %errorlevel%\r\n",
        encoding="ascii",
    )
    validated = subprocess.run(["cmd.exe", "/d", "/c", str(script)], capture_output=True)
    if validated.returncode != 0:
        return (0, 0, "validator rejected generated input", validated.stderr[:160])

    main_out = run(BIN / "solution.exe", data)
    ref_out = run(BIN / "solution2.exe", data)
    if main_out.returncode != 0 or ref_out.returncode != 0:
        return (0, 0, "nonzero exit", main_out.returncode, ref_out.returncode)
    if normalize(main_out.stdout) != normalize(ref_out.stdout):
        return (0, 0, "main vs reference")

    header = normalize(data).split("\n")[0].split()
    n, m = int(header[0]), int(header[1])
    answer = WORK / f"gen-{index}.out"
    answer.write_bytes(main_out.stdout)
    checked = subprocess.run(
        [str(BIN / "checker.exe"), str(source), str(answer), str(answer)],
        capture_output=True,
    )
    if checked.returncode != 0:
        return (n, m, "checker rejected main", checked.stderr[:120])
    return None


def main():
    WORK.mkdir(parents=True, exist_ok=True)
    for stale in WORK.glob("*"):
        stale.unlink()

    rng = random.Random(SEED)
    failures = []
    shapes = []
    for index in range(ROUNDS):
        result = lane_script(rng, index)
        if result:
            failures.append(result)
        else:
            header = (WORK / f"script-{index}.in").read_text(encoding="utf-8").split("\n")[0].split()
            shapes.append((int(header[0]), int(header[1])))

    for index in range(ROUNDS):
        result = lane_generator(index)
        if result:
            failures.append(result)

    generator_shapes = []
    for index in range(ROUNDS):
        path = WORK / f"gen-{index}.in"
        if path.exists():
            header = path.read_text(encoding="utf-8").split("\n")[0].split()
            generator_shapes.append((int(header[0]), int(header[1])))

    (ROOT / ".tmp/11/stress-shapes.txt").write_text(
        "\n".join(f"{n} {m}" for n, m in shapes) + "\n", encoding="utf-8"
    )
    (ROOT / ".tmp/11/stress-generator-shapes.txt").write_text(
        "\n".join(f"{n} {m}" for n, m in generator_shapes) + "\n", encoding="utf-8"
    )
    print(f"rounds_requested={2 * ROUNDS} rounds_passed={2 * ROUNDS - len(failures)} failures={len(failures)}")
    for failure in failures[:5]:
        print("FAIL", failure)
    return 0 if not failures else 1


if __name__ == "__main__":
    sys.exit(main())
