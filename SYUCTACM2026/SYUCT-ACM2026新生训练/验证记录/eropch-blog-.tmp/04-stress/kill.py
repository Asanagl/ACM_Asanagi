import subprocess, os, glob, sys
BIN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-04\bin"
GEN = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-04\generated"
os.environ["PATH"] = r"C:\Algo Bootstrap\mingw64\bin;" + os.environ["PATH"]
checker = BIN + r"\checker.exe"
wrongs = [f for f in os.listdir(BIN) if f.startswith("wrong-") and f.endswith(".exe")]
cases = sorted(glob.glob(GEN + r"\*\*.in"))
for w in sorted(wrongs):
    firstfail = None; passed = 0; ree = 0
    for c in cases:
        ans = c[:-3] + ".ans"
        r = subprocess.run([os.path.join(BIN, w)], stdin=open(c, "rb"), capture_output=True)
        if r.returncode != 0:
            ree += 1; continue
        out = c[:-3] + ".tmpout"
        open(out, "wb").write(r.stdout)
        j = subprocess.run([checker, c, out, ans], capture_output=True)
        os.remove(out)
        if j.returncode != 0:
            if firstfail is None:
                firstfail = (os.path.basename(c), j.stderr.decode(errors="replace").strip()[:60])
        else:
            passed += 1
    print(f"{w:28s} passed={passed:3d} re={ree} firstWA={firstfail}")
