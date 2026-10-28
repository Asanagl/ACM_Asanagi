import argparse
import json
import random
import string
import subprocess
from pathlib import Path


def run_program(executable, data):
    try:
        result = subprocess.run(
            [str(executable)],
            input=data,
            capture_output=True,
            timeout=2,
            check=False,
        )
    except subprocess.TimeoutExpired as error:
        return {
            "status": "TLE",
            "returncode": None,
            "stdout": (error.stdout or b"").decode("utf-8", "backslashreplace"),
            "stderr": (error.stderr or b"").decode("utf-8", "backslashreplace"),
        }
    return {
        "status": "OK" if result.returncode == 0 else "RE",
        "returncode": result.returncode,
        "stdout": result.stdout.decode("utf-8", "backslashreplace"),
        "stderr": result.stderr.decode("utf-8", "backslashreplace"),
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("bin", type=Path)
    parser.add_argument("--rounds", type=int, default=100)
    parser.add_argument("--seed", type=int, default=12345)
    parser.add_argument("--result", type=Path, required=True)
    args = parser.parse_args()
    if args.rounds < 1:
        raise SystemExit("rounds must be positive")

    rng = random.Random(args.seed)
    completed = 0
    failure = None
    for round_no in range(1, args.rounds + 1):
        n = rng.randint(1, 20)
        s = "".join(rng.choice(string.ascii_lowercase) for _ in range(n))
        data = (s + "\n").encode("ascii")
        expected = f"{len(s)} {s[0]} {s[-1]}\n"
        runs = {
            "main": run_program(args.bin / "main.exe", data),
            "solution2": run_program(args.bin / "sol2.exe", data),
        }
        if any(run["status"] != "OK" for run in runs.values()):
            failure = {
                "status": "infrastructure",
                "reason": "program_failed",
                "round": round_no,
                "input": s,
                "expected": expected,
                "runs": runs,
            }
        elif runs["main"]["stdout"] != expected or runs["solution2"]["stdout"] != expected:
            failure = {
                "status": "counterexample",
                "reason": "output_mismatch",
                "round": round_no,
                "input": s,
                "expected": expected,
                "runs": runs,
            }
        if failure is not None:
            failure_path = args.result.parent / "stress-failure.in"
            failure_path.write_bytes(data)
            failure["artifact"] = str(failure_path)
            break
        completed = round_no

    report = {
        "seed": args.seed,
        "rounds_requested": args.rounds,
        "rounds_completed": completed,
        "status": "passed" if failure is None and completed == args.rounds else "failed",
        "failure": failure,
    }
    args.result.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False))
    raise SystemExit(0 if report["status"] == "passed" else 1)


if __name__ == "__main__":
    main()
