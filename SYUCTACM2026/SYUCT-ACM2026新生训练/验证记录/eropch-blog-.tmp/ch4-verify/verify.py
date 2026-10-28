import re
import subprocess
import sys
from pathlib import Path

MD = Path("source/_posts/xcpc-cpp-guide-ch4-strings.md")
WORK = Path(".tmp/ch4-verify")
WORK.mkdir(parents=True, exist_ok=True)

text = MD.read_text(encoding="utf-8")
blocks = re.findall(r"```cpp\n(.*?)```", text, flags=re.S)
print(f"extracted {len(blocks)} cpp blocks")

M3 = "1 2 3\n4 5 6\n7 8 9\n"
M34 = "1 2 3 4\n5 6 7 8\n9 10 11 12\n"

expected = {
    0: (None, "h o\nhello\n"),                                             # 4.1
    1: ("hello world\n", "[hello] size = 5\n"),                           # 4.2.1
    2: ("hello world\n", "[hello world] size = 11\n"),                    # 4.2.2
    3: ("3\nAlice\n", "3 []\n"),                                           # 4.2.3 broken
    4: ("2\nhello world\ngood morning\n", "0: [hello world]\n1: [good morning]\n"),
    5: ("code\n", "4\n"),                                                 # 4.3.1 len snippet
    6: ("code\n", "0: c\n1: o\n2: d\n3: e\nAode\n"),                      # 4.3.2
    7: ("code\n", "c o d e \n"),                                          # 4.3 range-for snippet
    8: (None, "abcxyz\nabcxyz\n"),                                        # 4.4.1
    9: ("apple apply\n", "apple < apply\n"),                              # 4.4.2
    10: ("Hello_World\n", "HELLO_WORLD\n"),                               # 4.4.3
    11: ("abcdef\n", "fedcba\n"),                                         # 4.5.1
    12: ("level\n", "yes\n"),                                             # 4.5.2
    13: ("abracadabra cad\n", "found at 4\n"),                            # 4.6.1
    14: ("abcdefg\n2 3\n", "cde\n"),                                      # 4.6.2
    15: ("20241024\n", "15\n"),                                           # 4.7
    16: ("3\napple banana cat\n", "apple 5\nbanana 6\ncat 3\n"),          # 4.8.1
    17: ("3 4\n.*..\n..*.\n*...\n", "3\n"),                                # 4.8.2
    19: (None, "5\n0\nhelloworld\n-1\n"),                                 # 4.9 char[]
    21: ("3 4\n" + M34, M34),                                             # 4.10.2 echo
    22: ("3 3\n" + M3 + "9 8 7\n6 5 4\n3 2 1\n",
         "10 10 10\n10 10 10\n10 10 10\n"),                                # 4.11
    23: ("3 3\n" + M3, "row sums: 6 15 24\ncolumn sums: 12 15 18\n"),      # 4.12.1
    24: ("3 3\n3 8 1\n5 9 2\n7 4 6\n", "maximum = 9\nat row 2, column 2\n"),
    25: ("3\n" + M3, "main diagonal = 15\nanti diagonal = 15\n"),         # 4.13.1
    26: ("3 4\n" + M34, "4 3 2 1\n8 7 6 5\n12 11 10 9\n"),                 # 4.13.2
    27: ("3 4\n" + M34, "1 5 9\n2 6 10\n3 7 11\n4 8 12\n"),                # 4.14.1
    28: ("3 4\n" + M34, "9 5 1\n10 6 2\n11 7 3\n12 8 4\n"),                # 4.14.2
    29: ("3 4\n" + M34, "65\n"),                                          # 4.15.1
    30: ("3 3\n" + M3 + "1 1\n", "20\n"),                                  # 4.15.2
    31: (None, "20\n"),                                                   # 4.15.2 dir-array snippet
    32: ("3 4\n" + M34 + "0 1 1 2\n", "18\n"),                             # 4.15.3
    33: ("abca\n", "1\n"),                                                # 4.16
    34: ("3 4\n", "BWBW\nWBWB\nBWBW\n"),                                   # 4.17
    35: ("abcabcabc\n", "3\n"),                                           # 4.18
}

SNIPPETS = {5, 7, 31}
SKIP = {18, 20}  # declaration fragments verified inside their full programs


def wrap_snippet(code: str, idx: int) -> str:
    head = "#include <iostream>\n#include <string>\nusing namespace std;\n"
    if idx == 5:
        return (head + "int main()\n{\n    string s;\n    cin >> s;\n"
                + code + "    cout << len << '\\n';\n    return 0;\n}\n")
    if idx == 7:
        return (head + "int main()\n{\n    string s;\n    cin >> s;\n"
                + code + "    return 0;\n}\n")
    if idx == 31:
        return (
            "#include <iostream>\nusing namespace std;\n"
            "int main()\n{\n"
            "    int n = 3, m = 3;\n"
            "    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};\n"
            "    int x = 1, y = 1;\n"
            "    long long neighborSum = 0;\n"
            + code
            + "    cout << neighborSum << '\\n';\n    return 0;\n}\n"
        )
    raise SystemExit(f"unexpected snippet at index {idx}")


failures = 0
for i, block in enumerate(blocks):
    if i in SKIP:
        print(f"[{i:02d}] SKIP (declaration fragment, covered by a full program)")
        continue
    code = block
    if "int main" not in code:
        if i not in SNIPPETS:
            print(f"[{i:02d}] UNEXPECTED SNIPPEN")
            failures += 1
            continue
        code = wrap_snippet(code, i)
    src = WORK / f"p{i:02d}.cpp"
    exe = WORK / f"p{i:02d}.exe"
    src.write_text(code, encoding="utf-8")
    compile_result = subprocess.run(
        ["g++", "-std=c++17", "-O2", "-Wall", "-static", str(src), "-o", str(exe)],
        capture_output=True, text=True,
    )
    if compile_result.returncode != 0:
        failures += 1
        print(f"[{i:02d}] COMPILE FAIL\n{compile_result.stderr[:800]}")
        continue
    if compile_result.stderr.strip():
        print(f"[{i:02d}] COMPILE WARNINGS:\n{compile_result.stderr[:400]}")

    if i not in expected:
        print(f"[{i:02d}] compiled OK (no run expectation defined)")
        continue
    stdin_data, want = expected[i]
    run_result = subprocess.run(
        [str(exe)], input=stdin_data, capture_output=True, text=True, timeout=10
    )
    got = run_result.stdout
    if got == want and run_result.returncode == 0:
        print(f"[{i:02d}] PASS")
    else:
        failures += 1
        print(f"[{i:02d}] OUTPUT MISMATCH (rc={run_result.returncode})")
        print(f"    want: {want!r}")
        print(f"    got : {got!r}")
        if run_result.stderr:
            print(f"    err : {run_result.stderr[:300]!r}")

print(f"\n{len(blocks)} blocks, failures = {failures}")
sys.exit(1 if failures else 0)
