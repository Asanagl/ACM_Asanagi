import random, subprocess, sys, os
BIN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-04\bin"
os.environ["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + os.environ["PATH"]
main, ref, val = (BIN + r"\main.exe", BIN + r"\solution2.exe", BIN + r"\validator.exe")

pool_full = [chr(c) for c in range(32,127)]
letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
nonletter = [c for c in pool_full if not (c.isalpha() and c.isascii())]
pools = [pool_full, list(letters), nonletter, list("aA 0!"), list("Z[]^_`a"), list(" "), list("09~!")]
ok = 0
for it in range(140):
    r = random.Random(12345 + it)
    n = r.randint(1, 40)
    s = ''.join(r.choice(pools[it % len(pools)]) for _ in range(n))
    lf = (s + "\n").encode()
    v = subprocess.run([val], input=(s + "\r\n").encode(), capture_output=True)
    if v.returncode != 0:
        print("VALIDATOR FAIL round", it+1, repr(s), v.stderr.decode(errors='replace')); sys.exit(1)
    a = subprocess.run([main], input=lf, capture_output=True)
    b = subprocess.run([ref], input=lf, capture_output=True)
    if a.returncode or b.returncode:
        print("RE round", it+1, repr(s)); sys.exit(1)
    if a.stdout != b.stdout:
        print("DIFF round", it+1, repr(s), repr(a.stdout), repr(b.stdout)); sys.exit(1)
    ok += 1
print("stress rounds passed:", ok)
