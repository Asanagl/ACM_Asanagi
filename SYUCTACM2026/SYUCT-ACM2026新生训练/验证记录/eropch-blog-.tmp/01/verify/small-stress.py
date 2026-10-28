"""严格小数据差分对拍：|s| <= 20，固定种子 12345，main/solution2 对独立 oracle。"""
import json
import random
import string
import subprocess
import sys
from pathlib import Path

BIN = Path(__file__).resolve().parent
ROUNDS = int(sys.argv[1]) if len(sys.argv) > 1 else 200
SEED = 12345

WRONGS = ["w-reverse", "w-onlylen", "w-offby", "w-char", "w-first2"]


def run(exe, data):
    r = subprocess.run([str(BIN / exe)], input=data, capture_output=True, timeout=5)
    return r.returncode, r.stdout.replace(b"\r\n", b"\n").decode()


rng = random.Random(SEED)
kills = {w: None for w in WRONGS}
failures = []
completed = 0

for rnd_no in range(1, ROUNDS + 1):
    n = rng.randint(1, 20)
    alpha = rng.choice([string.ascii_lowercase, "ab", "a", "z"])
    s = "".join(rng.choice(alpha) for _ in range(n))
    data = (s + "\n").encode()
    oracle = f"{len(s)} {s[0]} {s[-1]}\n"

    rc_m, out_m = run("main.exe", data)
    rc_s, out_s = run("sol2.exe", data)
    if rc_m != 0 or rc_s != 0:
        failures.append({"round": rnd_no, "reason": "runtime_error", "input": s,
                         "rc_main": rc_m, "rc_sol2": rc_s})
    elif out_m != oracle or out_s != oracle:
        failures.append({"round": rnd_no, "reason": "answer_mismatch", "input": s,
                         "oracle": oracle, "main": out_m, "sol2": out_s})
    if failures:
        (BIN / "small-stress-failure.in").write_bytes(data)
        break

    for w in WRONGS:
        if kills[w] is not None:
            continue
        rc, out = run(w + ".exe", data)
        if rc != 0 or out != oracle:
            kills[w] = {"round": rnd_no, "input": s, "exit": rc, "got": out}
    completed = rnd_no

report = {
    "seed": SEED,
    "max_len": 20,
    "rounds_requested": ROUNDS,
    "rounds_completed": completed,
    "status": "passed" if not failures and completed == ROUNDS else "failed",
    "failures": failures,
    "wrong_killed": {w: kills[w] is not None for w in WRONGS},
    "wrong_first_kill": kills,
}
(BIN / "small-stress-report.json").write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
print(json.dumps({k: report[k] for k in ("seed", "max_len", "rounds_requested", "rounds_completed", "status", "wrong_killed")}, ensure_ascii=False))
sys.exit(0 if report["status"] == "passed" else 1)
