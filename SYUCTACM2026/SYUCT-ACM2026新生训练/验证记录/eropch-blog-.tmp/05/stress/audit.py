import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
WS = Path("C:/Users/Asanagi/eropch-blog/problemsets/2026syuctacm-weekly-04/problems/05")
GEN = HERE / "generator.exe"
MAIN = HERE / "main.exe"
REF = HERE / "ref.exe"
CHECKER = HERE / "checker.exe"
VALIDATOR = HERE / "validator.exe"

EOL = b"\r\n"


def run(exe, args, data=b""):
    p = subprocess.run([str(exe), *args], input=data,
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=120)
    return p.returncode, p.stdout, p.stderr


def main():
    cfg = json.loads((WS / "config.json").read_text(encoding="utf-8"))
    cases = cfg["generator"]["cases"]
    wrongs = [w["name"] for w in cfg["wrongSolutions"]]
    print(f"cases={len(cases)} wrongs={wrongs}")

    fails = {w: [] for w in wrongs}
    passes = {w: [] for w in wrongs}
    broken = []
    for c in cases:
        rc, out, err = run(GEN, [c["type"], str(c["seed"])])
        if rc != 0:
            broken.append((c["name"], rc, err.decode(errors="replace")[:200]))
            continue
        inp = HERE / (c["name"] + ".in")
        inp.write_bytes(out)
        vrc, _, verr = run(VALIDATOR, [], out)
        if vrc != 0:
            broken.append((c["name"], "validator", verr.decode(errors="replace")[:200]))
            continue
        mrc, mout, merr = run(MAIN, [], out)
        if mrc != 0:
            broken.append((c["name"], "main", merr.decode(errors="replace")[:200]))
            continue
        rrc, rout, rerr = run(REF, [], out)
        if rrc != 0 or rout.replace(b"\r\n", b"\n") != mout.replace(b"\r\n", b"\n"):
            broken.append((c["name"], "reference-mismatch", rerr.decode(errors="replace")[:200]))
            continue
        ans = HERE / (c["name"] + ".ans")
        ans.write_bytes(mout)
        aout = HERE / (c["name"] + ".main.out")
        aout.write_bytes(mout)
        crc, cout, cerr = run(CHECKER, [str(inp), str(aout), str(ans)])
        if crc != 0:
            broken.append((c["name"], "checker", cout.decode(errors="replace")[:200]))
        for w in wrongs:
            wexe = HERE / (w + ".exe")
            wrc, wout, werr = run(wexe, [], out)
            wpath = HERE / (c["name"] + "." + w + ".out")
            wpath.write_bytes(wout)
            if wrc != 0:
                fails[w].append(c["name"] + "(RE)")
                continue
            jrc, jout, _ = run(CHECKER, [str(inp), str(wpath), str(ans)])
            (fails if jrc != 0 else passes)[w].append(c["name"])

    for w in wrongs:
        print(f"{w}: killed={len(fails[w])} survived={len(passes[w])} first-kill={fails[w][:3]}")
    if broken:
        print("BROKEN:", broken)
        return 1

    def inp(first: bytes, second: bytes) -> bytes:
        return first + EOL + second + EOL

    bad = [
        b"",
        inp(b"", b"a b"),
        inp(b"ABC", b"a b"),
        inp(b"ab1", b"a b"),
        inp(b"abc", b"a"),
        inp(b"abc", b"ab"),
        inp(b"abc", b"a b c"),
        inp(b"abc", b"a  b"),
        inp(b"abc", b"a\tb"),
        inp(b"abc", b"A b"),
        inp(b"abc", b"a B"),
        inp(b"abc", b"a b "),
        inp(b"a" * 100001, b"a b"),
        inp(b"abc", b"ab"),
    ]
    for b in bad:
        vrc, _, verr = run(VALIDATOR, [], b)
        if vrc == 0:
            print("VALIDATOR ACCEPTED BAD INPUT:", b[:40])
            return 1

    good = [
        inp(b"a", b"a a"),
        inp(b"z", b"a b"),
        inp(b"a" * 100000, b"a b"),
        inp(b"abc", b"a b"),
    ]
    for g in good:
        vrc, _, verr = run(VALIDATOR, [], g)
        if vrc != 0:
            print("VALIDATOR REJECTED GOOD INPUT:", g[:40], verr.decode(errors="replace")[:200])
            return 1
    print(f"validator: rejected {len(bad)} malformed, accepted {len(good)} legal edge inputs")
    return 0


if __name__ == "__main__":
    sys.exit(main())
