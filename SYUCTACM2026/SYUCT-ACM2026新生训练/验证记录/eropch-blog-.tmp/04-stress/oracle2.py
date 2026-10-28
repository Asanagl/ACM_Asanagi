import random, subprocess, os, sys
BIN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-04\bin"
os.environ["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + os.environ["PATH"]
main = BIN + r"\main.exe"; ref = BIN + r"\solution2.exe"

def oracle(s):
    return ''.join(c.lower() if 'A' <= c <= 'Z' else c.upper() if 'a' <= c <= 'z' else c for c in s)

def norm(b):
    return b.decode().replace("\r\n", "\n")

ok = 0
for it in range(150):
    r = random.Random(12345 * 7 + it)
    n = r.randint(1, 60)
    kind = it % 8
    if kind == 0: s = ''.join(chr(r.randint(32, 126)) for _ in range(n))
    elif kind == 1: s = ''.join(r.choice("AZaz") for _ in range(n))
    elif kind == 2: s = ' ' * n
    elif kind == 3: s = ''.join(r.choice("09 !~[]^_`") for _ in range(n))
    elif kind == 4: s = ('aA' * n)[:n]
    elif kind == 5: s = 'Z' * n
    elif kind == 6: s = ''.join(chr(r.randint(91, 96)) for _ in range(n))
    else: s = 'q' * (n - 1) + ' '
    exp = oracle(s) + "\n"
    data = (s + "\n").encode()
    a = subprocess.run([main], input=data, capture_output=True)
    b = subprocess.run([ref], input=data, capture_output=True)
    if a.returncode or b.returncode:
        print("RE", it + 1, repr(s)); sys.exit(1)
    if norm(a.stdout) != exp:
        print("MAIN!=ORACLE", it + 1, repr(s), repr(a.stdout), repr(exp)); sys.exit(1)
    if norm(b.stdout) != exp:
        print("REF!=ORACLE", it + 1, repr(s), repr(b.stdout), repr(exp)); sys.exit(1)
    ok += 1
print("oracle rounds passed:", ok)
