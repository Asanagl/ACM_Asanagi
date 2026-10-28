import json
import subprocess
import sys
import time
from pathlib import Path

PROBLEM = Path(sys.argv[1]).resolve()
WORK = Path(__file__).resolve().parent / "stress"
BIN = WORK / "bin"
BIN.mkdir(parents=True, exist_ok=True)

sources = {
    "generator": PROBLEM / "src/generator/generator.cpp",
    "validator": PROBLEM / "src/validator/validator.cpp",
    "checker": PROBLEM / "src/checker/checker.cpp",
    "main": PROBLEM / "src/solution.cpp",
    "reference": PROBLEM / "src/solution2.cpp",
}
programs = {}
for name, source in sources.items():
    executable = BIN / f"{name}.exe"
    command = [
        "g++", "-std=gnu++17", "-O2", "-pipe", "-static",
        "-I", str(PROBLEM / "include"), str(source), "-o", str(executable),
    ]
    result = subprocess.run(command, capture_output=True, timeout=120)
    if result.returncode != 0:
        print(result.stderr.decode("utf-8", errors="replace"), file=sys.stderr)
        raise SystemExit(f"compilation failed: {name}")
    programs[name] = executable

master_seed = 12345
rounds_requested = 100
rounds_completed = 0
started = time.monotonic()
report = {
    "master_seed": master_seed,
    "rounds_requested": rounds_requested,
    "rounds_completed": 0,
    "generator_type": "small-random",
    "comparison": "exact main/reference output plus unique-answer checker",
    "validator_passed": 0,
    "ok": False,
    "status": "running",
}

for round_number in range(1, rounds_requested + 1):
    seed = master_seed + round_number - 1
    generated = subprocess.run(
        [str(programs["generator"]), "small-random", str(seed)],
        capture_output=True,
        timeout=10,
    )
    if generated.returncode != 0:
        report.update(status="infrastructure", reason="generator_re", round=round_number, seed=seed)
        break
    input_data = generated.stdout
    validated = subprocess.run(
        [str(programs["validator"])], input=input_data, capture_output=True, timeout=10
    )
    if validated.returncode != 0:
        report.update(status="infrastructure", reason="validator_rejected", round=round_number, seed=seed)
        break
    report["validator_passed"] += 1

    main_result = subprocess.run(
        [str(programs["main"])], input=input_data, capture_output=True, timeout=2
    )
    reference_result = subprocess.run(
        [str(programs["reference"])], input=input_data, capture_output=True, timeout=2
    )
    if main_result.returncode != 0 or reference_result.returncode != 0:
        report.update(
            status="counterexample",
            reason="accepted_re",
            round=round_number,
            seed=seed,
            main_returncode=main_result.returncode,
            reference_returncode=reference_result.returncode,
        )
        break

    current = WORK / "current"
    current.mkdir(exist_ok=True)
    input_path = current / "input.in"
    main_path = current / "main.out"
    reference_path = current / "reference.out"
    input_path.write_bytes(input_data)
    main_path.write_bytes(main_result.stdout)
    reference_path.write_bytes(reference_result.stdout)
    checked = subprocess.run(
        [str(programs["checker"]), str(input_path), str(reference_path), str(main_path)],
        capture_output=True,
        timeout=10,
    )
    if main_result.stdout != reference_result.stdout or checked.returncode != 0:
        failure = WORK / f"counterexample-r{round_number}-s{seed}"
        failure.mkdir(exist_ok=True)
        (failure / "input.in").write_bytes(input_data)
        (failure / "main.out").write_bytes(main_result.stdout)
        (failure / "reference.out").write_bytes(reference_result.stdout)
        report.update(
            status="counterexample",
            reason="output_mismatch" if main_result.stdout != reference_result.stdout else "checker_rejected",
            round=round_number,
            seed=seed,
            checker_returncode=checked.returncode,
            counterexample=str(failure),
        )
        break

    rounds_completed = round_number
    report["rounds_completed"] = rounds_completed
else:
    report.update(ok=True, status="passed")

report["duration_seconds"] = round(time.monotonic() - started, 3)
report_path = Path(__file__).resolve().parent / "stress-report.json"
report_path.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
print(json.dumps(report, ensure_ascii=False))
raise SystemExit(0 if report["ok"] and rounds_completed == rounds_requested else 1)
