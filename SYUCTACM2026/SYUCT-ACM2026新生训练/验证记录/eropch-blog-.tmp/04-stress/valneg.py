import subprocess, os
BIN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-04\bin\validator.exe"
os.environ["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + os.environ["PATH"]
cases = [
    ("empty line", b"\r\n", 1),
    ("1001 chars", (b"a"*1001) + b"\r\n", 1),
    ("tab in line", b"ab\tcd\r\n", 1),
    ("non-ascii latin1", b"ab\xe9cd\r\n", 1),
    ("NUL char", b"ab\x00cd\r\n", 1),
    ("CR alone in middle", b"ab\rcd\r\n", 1),
    ("ctrl char 127", b"ab\x7f\r\n", 1),
    ("min 1 char", b"A\r\n", 0),
    ("space only", b" \r\n", 0),
    ("1000 chars", (b"a"*1000) + b"\r\n", 0),
    ("all printable", bytes(range(32,127)) + b"\r\n", 0),
]
bad = 0
for name, data, expect_fail in cases:
    r = subprocess.run([BIN], input=data, capture_output=True)
    got_fail = r.returncode != 0
    mark = "OK " if got_fail == bool(expect_fail) else "BAD"
    if mark == "BAD": bad += 1
    print(f"{mark} {name:22s} exit={r.returncode} msg={r.stderr.decode(errors='replace').strip()[:55]}")
print("validator negative tests mismatched:", bad)
