import random
import string
import subprocess
import sys

BIN = sys.argv[1] if len(sys.argv) > 1 else "bin"
ROUNDS = int(sys.argv[2]) if len(sys.argv) > 2 else 200
SEED = 12345

rng = random.Random(SEED)
mismatches = 0

for round_no in range(1, ROUNDS + 1):
    n = rng.randint(1, 20)
    s = "".join(rng.choice(string.ascii_lowercase) for _ in range(n))
    data = (s + "\n").encode()

    out_main = subprocess.run([f"{BIN}/main.exe"], input=data, capture_output=True).stdout
    out_sol2 = subprocess.run([f"{BIN}/sol2.exe"], input=data, capture_output=True).stdout
    oracle = f"{len(s)} {s[0]} {s[-1]}\n".encode()

    if out_main != out_sol2 or out_main != oracle:
        mismatches += 1
        print(f"[MISMATCH] round={round_no} input={s!r}")
        print(f"  main  = {out_main!r}")
        print(f"  sol2  = {out_sol2!r}")
        print(f"  oracle= {oracle!r}")
        with open(f"{BIN}/counterexample-{round_no}.in", "wb") as f:
            f.write(data)
        break

print(f"stress done: rounds={ROUNDS if mismatches == 0 else round_no} "
      f"seed={SEED} mismatches={mismatches}")
sys.exit(1 if mismatches else 0)
