import os
import random
import subprocess
import sys

WORK = os.path.dirname(os.path.abspath(__file__))
ENV = dict(os.environ)
ENV["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + ENV["PATH"]

MAIN = os.path.join(WORK, "main.exe")
SOL2 = os.path.join(WORK, "solution2.exe")

ROUNDS = int(sys.argv[1]) if len(sys.argv) > 1 else 120
SEED = 12345
random.seed(SEED)


def oracle(text):
    return text.count(" ")


def gen_case(rng):
    kind = rng.randrange(10)
    if kind == 0:
        n = rng.randrange(0, 4)
    elif kind == 1:
        n = rng.randrange(0, 12)
    elif kind == 2:
        n = rng.randrange(0, 60)
    else:
        n = rng.randrange(0, 200)
    style = rng.randrange(7)
    if style == 0:
        s = " " * n
    elif style == 1:
        s = "".join(rng.choice("ab ") for _ in range(n))
    elif style == 2:
        s = "".join(rng.choice(" \t" if False else " ab") for _ in range(n))
    elif style == 3:
        s = ("a  b   " * (n // 7 + 1))[:n]
    elif style == 4:
        s = "".join(chr(rng.randrange(32, 127)) for _ in range(n))
    elif style == 5:
        s = " " * (n // 2) + "a" * (n - n // 2)
    else:
        s = "a" * (n // 2) + " " * (n - n // 2)
    trailing_newline = rng.random() < 0.8
    return s, trailing_newline


def run(exe, payload):
    return subprocess.run(
        [exe], input=payload, capture_output=True, env=ENV, timeout=60
    )


fails = 0
checked = 0
for r in range(ROUNDS):
    s, nl = gen_case(random)
    payload = (s + ("\n" if nl else "")).encode()
    expect = str(oracle(s)).encode()
    outs = []
    for exe in (MAIN, SOL2):
        res = run(exe, payload)
        out = res.stdout.replace(b"\r\n", b"\n").strip()
        outs.append((exe, res.returncode, out))
        checked += 1
    for exe, rc, out in outs:
        if rc != 0 or out != expect:
            fails += 1
            print(f"FAIL round={r} exe={os.path.basename(exe)} rc={rc} "
                  f"got={out!r} expect={expect!r} input={payload!r}")
print(f"rounds={ROUNDS} comparisons={checked} fails={fails}")
sys.exit(1 if fails else 0)
