import os, subprocess, sys, time

BUILD = r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-21"
BIN = os.path.join(BUILD, "bin")
GEN = os.path.join(BUILD, "generated")
CFG = os.path.join(BIN, "checker.exe")

wrongs = ["wrong-diagonal", "wrong-self", "wrong-wrap", "wrong-count-neighbors",
          "wrong-missing-down-right", "wrong-transpose", "wrong-quadratic"]

cases = []
for grp in ("sample", "secret"):
    d = os.path.join(GEN, grp)
    for f in sorted(os.listdir(d)):
        if f.endswith(".in"):
            name = f[:-3]
            cases.append((grp, name, os.path.join(d, f), os.path.join(d, name + ".ans")))

print(f"total cases: {len(cases)}")
for sol in wrongs:
    exe = os.path.join(BIN, sol + ".exe")
    kills = []
    runs = 0
    for grp, name, inp, ans in cases:
        runs += 1
        t0 = time.time()
        try:
            p = subprocess.run([exe], stdin=open(inp, "rb"), capture_output=True, timeout=10)
        except subprocess.TimeoutExpired:
            kills.append((name, "TIMEOUT>10s", time.time() - t0))
            continue
        dt = time.time() - t0
        if p.returncode != 0:
            kills.append((name, f"NONZERO_EXIT({p.returncode})", dt))
            continue
        outpath = os.path.join(os.path.dirname(inp), f"{name}.{sol}.probe.out")
        open(outpath, "wb").write(p.stdout)
        c = subprocess.run([CFG, inp, outpath, ans], capture_output=True)
        if c.returncode != 0:
            msg = c.stdout.decode("utf-8", "replace").strip().splitlines()
            kills.append((name, "CHECKER_WA: " + (msg[-1] if msg else ""), dt))
        os.remove(outpath)
    print(f"\n=== {sol}: killed on {len(kills)}/{runs} cases")
    for k in kills[:4]:
        print(f"   {k[0]:24s} {k[1][:70]:70s} {k[2]:.2f}s")
    if len(kills) > 4:
        print(f"   ... {len(kills)-4} more")
