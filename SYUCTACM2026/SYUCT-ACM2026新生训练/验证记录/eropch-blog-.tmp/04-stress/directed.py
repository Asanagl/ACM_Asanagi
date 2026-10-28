import subprocess, os
BIN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-04\bin"
GEN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-04\generated\secret"
os.environ["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + os.environ["PATH"]
pairs = [("kill-oneway","wrong-oneway"),("kill-position","wrong-position"),
         ("kill-token","wrong-token"),("kill-xor","wrong-xor"),
         ("kill-last","wrong-skip-last"),("kill-range","wrong-range")]
for case, wrong in pairs:
    c = os.path.join(GEN, case + ".in"); ans = os.path.join(GEN, case + ".ans")
    r = subprocess.run([os.path.join(BIN, wrong + ".exe")], stdin=open(c,"rb"), capture_output=True)
    out = os.path.join(GEN, case + ".chk.tmp")
    open(out,"wb").write(r.stdout)
    j = subprocess.run([BIN + r"\checker.exe", c, out, ans], capture_output=True)
    os.remove(out)
    print(f"{case:14s} vs {wrong:16s} exit={r.returncode} checker_exit={j.returncode} verdict={'WA(killed)' if j.returncode else 'AC(!)'}")
