import re, subprocess, sys, pathlib

md = pathlib.Path("../../source/_posts/xcpc-cpp-guide-ch3-arrays.md", ).read_text(encoding="utf-8")
blocks = re.findall(r"```cpp\n(.*?)```", md, re.S)
mains = [b for b in blocks if "int main" in b]
print(f"total cpp blocks: {len(blocks)}, full programs: {len(mains)}")

cases = [
    ("snippets", None, "1 2 0 0 0\n0 0 0 0 0\n3\n"),
    ("p1_sum", "5\n7 -2 7 -5 3\n", "10\n"),
    ("p2_stats", "6\n7 -2 7 -5 0 3\n",
     "maximum = 7\nmaximum index = 0\nminimum = -5\nnegative count = 2\n"),
    ("p3_find_reverse", "6\n1 2 3 2 5 2\n2\n", "first index = 1\n2 5 2 3 2 1\n"),
    ("p4_count", "8\n75 90 75 60 90 100 60 75\n",
     "60: 2\n75: 3\n90: 2\n100: 1\n"),
    ("p5_multicase", "3\n5\n1 2 1 0 0\n4\n9 9 9 9\n3\n0 1 2\n",
     "2 2 1 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 4\n1 1 1 0 0 0 0 0 0 0\n"),
    ("p6_segments", "10\n1 0 0 3 4 0 5 0 0 2\n", "4\n"),
    ("p7_subarray", "5\n-2 11 -4 13 -5\n", "20\n"),
    ("p8_prefix", "6\n1 2 3 4 5 6\n3\n0 2\n1 4\n3 5\n", "6\n14\n15\n"),
    ("p9_matrix", "2 3\n1 2 3\n4 5 6\n",
     "1 2 3\n4 5 6\n6 15\n"),
    ("p10_bubble", "5\n3 5 1 4 2\n", "1 2 3 4 5\n"),
    ("p11_sort", "6\n3 1 4 1 5 9\n", "1 1 3 4 5 9\n9 5 4 3 1 1\n"),
    ("p12_cmp", "6\n-3 1 -1 2 -2 3\n", "-1 1 -2 2 -3 3\n"),
    ("p13_mex", "5\n0 1 2 4 5\n", "3\n"),
    ("p14_window", "6 15\n1 2 3 4 5 6\n", "3\n"),
]

assert len(mains) == len(cases), f"count mismatch: {len(mains)} vs {len(cases)}"

fail = 0
for (name, inp, expected), code in zip(cases, mains):
    src = pathlib.Path(f"check_{name}.cpp")
    src.write_text(code, encoding="utf-8")
    # exact article command: -std=c++17 -O2 -Wall (no -static)
    r1 = subprocess.run(["g++", "-std=c++17", "-O2", "-Wall", str(src), "-o", f"{name}.exe"],
                        capture_output=True, text=True)
    if r1.returncode != 0 or r1.stderr:
        print(f"[FAIL compile] {name}\n{r1.stderr}")
        fail += 1
        continue
    r2 = subprocess.run(["g++", "-std=c++17", "-O2", "-Wall", "-static", str(src), "-o", f"{name}_s.exe"],
                        capture_output=True, text=True)
    if r2.returncode != 0:
        print(f"[FAIL static compile] {name}\n{r2.stderr}")
        fail += 1
        continue
    r3 = subprocess.run([f"./{name}_s.exe"], input=inp, capture_output=True, text=True, timeout=10)
    actual = r3.stdout.replace("\r\n", "\n")
    if r3.returncode != 0:
        print(f"[FAIL run rc={r3.returncode}] {name}")
        fail += 1
    elif actual != expected:
        print(f"[FAIL output] {name}\n  expected: {expected!r}\n  actual:   {actual!r}")
        fail += 1
    else:
        print(f"[OK] {name}")

print("ALL PASS" if fail == 0 else f"{fail} FAILURES")
sys.exit(1 if fail else 0)
