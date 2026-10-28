import json
import subprocess
from collections import defaultdict
from pathlib import Path

BASE = Path(__file__).resolve().parent
REPO = BASE.parents[1]
PROBLEM = REPO / "problemsets/2026syuctacm-weekly-04/problems/25"
BIN = BASE / "bin"
OUT = BASE / "generated"
CONFIG = json.loads((PROBLEM / "config.json").read_text(encoding="utf-8"))


def invoke(name, data=b"", args=(), timeout=20):
    return subprocess.run(
        [str(BIN / f"{name}.exe"), *map(str, args)],
        input=data,
        capture_output=True,
        timeout=timeout,
    )


def verdict(result):
    if result.returncode == 0:
        return "AC"
    if result.returncode in (1, 2):
        return "WA"
    return f"FAIL({result.returncode})"


OUT.mkdir(parents=True, exist_ok=True)
summary = {"cases": [], "wrong": defaultdict(lambda: {"AC": [], "WA": [], "other": []})}
secret_hashes = defaultdict(list)

for case in CONFIG["generator"]["cases"]:
    generated = invoke("generator", args=(case["type"], case["seed"]), timeout=60)
    assert generated.returncode == 0, (case["name"], generated.stderr.decode(errors="replace"))
    data = generated.stdout
    group_dir = OUT / case["group"]
    group_dir.mkdir(parents=True, exist_ok=True)
    input_path = group_dir / f"{case['name']}.in"
    answer_path = group_dir / f"{case['name']}.ans"
    input_path.write_bytes(data)

    validated = invoke("validator", data)
    assert validated.returncode == 0, (case["name"], validated.stderr.decode(errors="replace"))

    main = invoke("solution", data, timeout=10)
    assert main.returncode == 0, (case["name"], main.stderr.decode(errors="replace"))
    main_path = group_dir / f"{case['name']}.main.out"
    main_path.write_bytes(main.stdout)
    answer_path.write_bytes(main.stdout)
    checked = invoke("checker", args=(input_path, main_path, answer_path))
    assert checked.returncode == 0, (case["name"], "main", checked.stderr.decode(errors="replace"))

    for reference in ("solution2", "blind-solution"):
        result = invoke(reference, data, timeout=10)
        assert result.returncode == 0, (case["name"], reference, result.stderr.decode(errors="replace"))
        reference_path = group_dir / f"{case['name']}.{reference}.out"
        reference_path.write_bytes(result.stdout)
        checked = invoke("checker", args=(input_path, reference_path, answer_path))
        assert checked.returncode == 0, (case["name"], reference, checked.stderr.decode(errors="replace"))

    answer_tokens = main.stdout.decode("ascii").split()
    case_info = {
        "name": case["name"],
        "group": case["group"],
        "n": len(data.strip()),
        "answer_length": int(answer_tokens[0]),
    }
    summary["cases"].append(case_info)
    if case["group"] == "secret":
        secret_hashes[data].append(case["name"])

    for wrong in CONFIG["wrongSolutions"]:
        name = wrong["name"]
        result = invoke(name, data, timeout=10)
        if result.returncode != 0:
            summary["wrong"][name]["other"].append([case["name"], f"RE({result.returncode})"])
            continue
        wrong_path = group_dir / f"{case['name']}.{name}.out"
        wrong_path.write_bytes(result.stdout)
        checked = invoke("checker", args=(input_path, wrong_path, answer_path))
        result_verdict = verdict(checked)
        if result_verdict == "WA":
            summary["wrong"][name]["WA"].append(case["name"])
        elif result_verdict == "AC":
            summary["wrong"][name]["AC"].append(case["name"])
        else:
            summary["wrong"][name]["other"].append([case["name"], result_verdict])

summary["sample_count"] = sum(c["group"] == "sample" for c in summary["cases"])
summary["secret_count"] = sum(c["group"] == "secret" for c in summary["cases"])
summary["duplicate_secret_groups"] = [names for names in secret_hashes.values() if len(names) > 1]
assert summary["sample_count"] >= 1
assert summary["secret_count"] >= 30
assert not summary["duplicate_secret_groups"], summary["duplicate_secret_groups"]
for name, results in summary["wrong"].items():
    assert results["WA"], f"{name} has no WA killer"
    assert not results["other"], f"{name} has non-WA failures: {results['other']}"

sample2 = OUT / "sample/sample-2.in"
answer2 = OUT / "sample/sample-2.ans"
probe = BASE / "checker-probe.out"
probe_results = {}
for label, output, expected in (
    ("accept", b"5 abcab\n", "AC"),
    ("non-divisor", b"3 abc\n", "WA"),
    ("extra-token", b"5 abcab extra\n", "WA"),
    ("wrong-length", b"4 abcab\n", "WA"),
):
    probe.write_bytes(output)
    checked = invoke("checker", args=(sample2, probe, answer2))
    actual = verdict(checked)
    probe_results[label] = actual
    assert actual == expected, (label, actual, checked.stderr.decode(errors="replace"))
summary["checker_probes"] = probe_results

validator_probes = {}
for label, data in (
    ("leading-blank", b"\nabcab\n"),
    ("trailing-space", b"abcab \n"),
    ("extra-token", b"abcab\nextra\n"),
    ("uppercase", b"Abcab\n"),
    ("too-long", b"a" * 3001 + b"\n"),
):
    checked = invoke("validator", data)
    validator_probes[label] = checked.returncode
    assert checked.returncode != 0, label
summary["validator_rejection_probes"] = validator_probes

summary["wrong"] = dict(summary["wrong"])
(BASE / "verification-summary.json").write_text(
    json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
)
print(f"cases={len(summary['cases'])} sample={summary['sample_count']} secret={summary['secret_count']}")
print(f"unique_secret={summary['secret_count']} duplicates=0")
for name, results in summary["wrong"].items():
    print(f"{name}: WA={len(results['WA'])} AC={len(results['AC'])} other=0 first_killer={results['WA'][0]}")
print(f"checker_probes={probe_results}")
print("validator_negative_probes=all_rejected")
