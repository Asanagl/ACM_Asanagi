import json
import os
import subprocess
import sys

WS = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04\problems\15"
GEN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-15\generated"
BIN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-15\bin"

cfg = json.load(open(os.path.join(WS, "config.json"), encoding="utf-8"))
cases = cfg["generator"]["cases"]


def path_of(case):
    return os.path.join(GEN, case["group"], case["name"] + ".in")


def run(exe, inp, timeout=5):
    with open(inp, "rb") as f:
        data = f.read()
    try:
        r = subprocess.run([exe], input=data, capture_output=True, timeout=timeout)
    except subprocess.TimeoutExpired:
        return "TLE", b""
    if r.returncode != 0:
        return "RE", r.stdout
    return "OK", r.stdout


def check(inp, out_bytes, ans_path):
    with open(os.path.join(BIN, "checker.exe"), "rb") as f:
        pass
    # checker needs files; write temp output
    tmp = os.path.join(os.path.dirname(inp), "_tmp_check.out")
    with open(tmp, "wb") as f:
        f.write(out_bytes)
    r = subprocess.run([os.path.join(BIN, "checker.exe"), inp, tmp, ans_path],
                       capture_output=True)
    os.remove(tmp)
    return r.returncode


results = {}
for w in cfg["wrongSolutions"]:
    exe = os.path.join(BIN, w["name"] + ".exe")
    verdicts = {}
    for case in cases:
        inp = path_of(case)
        ans = os.path.join(os.path.dirname(inp), case["name"] + ".ans")
        status, out = run(exe, inp)
        if status == "TLE":
            verdict = "TLE"
        elif status == "RE":
            verdict = "RE"
        else:
            rc = check(inp, out, ans)
            verdict = "AC" if rc == 0 else "WA"
        verdicts.setdefault(verdict, []).append(case["name"])
    results[w["name"]] = {k: (len(v), v[:6]) for k, v in verdicts.items()}
    print(w["name"], {k: len(v) for k, v in verdicts.items()})

# check main and solution2 all AC
for name in ["main", "solution2"]:
    exe = os.path.join(BIN, ("solution" if name == "main" else name) + ".exe")
    if not os.path.exists(exe):
        exe = os.path.join(BIN, name + ".exe")
    bad = []
    for case in cases:
        inp = path_of(case)
        ans = os.path.join(os.path.dirname(inp), case["name"] + ".ans")
        status, out = run(exe, inp)
        if status != "OK" or check(inp, out, ans) != 0:
            bad.append(case["name"])
    print(name, "exe=", exe, "bad=", bad)
