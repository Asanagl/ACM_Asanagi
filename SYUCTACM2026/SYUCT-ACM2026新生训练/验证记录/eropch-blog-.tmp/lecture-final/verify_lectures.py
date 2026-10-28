import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path.cwd()
WORK = ROOT / ".tmp" / "lecture-final"
WORK.mkdir(parents=True, exist_ok=True)
CHAPTERS = {
    "ch1": "source/_posts/xcpc-cpp-guide-ch1-variables.md",
    "ch2": "source/_posts/xcpc-cpp-guide-ch2-loops.md",
    "ch3": "source/_posts/xcpc-cpp-guide-ch3-arrays.md",
    "ch4": "source/_posts/xcpc-cpp-guide-ch4-strings.md",
}
blocks = {}
for chapter, relative in CHAPTERS.items():
    text = (ROOT / relative).read_text(encoding="utf-8")
    blocks[chapter] = re.findall(r"```cpp\n(.*?)```", text, flags=re.S)


def compile_code(code, name, static=False):
    source = WORK / f"{name}.cpp"
    executable = WORK / f"{name}.exe"
    source.write_text(code, encoding="utf-8")
    command = ["g++", "-std=c++17", "-O2", "-Wall"]
    if static:
        command.append("-static")
    command += [str(source), "-o", str(executable)]
    result = subprocess.run(command, capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=90)
    return result, executable


jobs = []
for chapter, chapter_blocks in blocks.items():
    for index, code in enumerate(chapter_blocks):
        if "int main" not in code:
            continue
        if chapter == "ch1" and "int a = 1；" in code:
            print(f"[expected-ce] {chapter}/{index:02d} 全角分号示例")
            continue
        jobs.append((chapter, index, code))

failures = []
warnings = []
with ThreadPoolExecutor(max_workers=4) as executor:
    futures = {
        executor.submit(compile_code, code, f"{chapter}-{index:02d}"): (chapter, index)
        for chapter, index, code in jobs
    }
    for future, (chapter, index) in futures.items():
        result, _ = future.result()
        if result.returncode != 0:
            failures.append(f"{chapter}/{index:02d}: {result.stderr[:1000]}")
        elif result.stderr.strip():
            warnings.append(f"{chapter}/{index:02d}: {result.stderr.strip()[:300]}")

print(f"compiled {len(jobs)} complete programs; unexpected failures={len(failures)}; warnings={len(warnings)}")
for warning in warnings:
    print(f"[warning] {warning}")
for failure in failures:
    print(f"[compile-failure] {failure}")

ch4 = blocks["ch4"]


def find_block(marker):
    matches = [code for code in ch4 if marker in code]
    if len(matches) != 1:
        raise RuntimeError(f"marker {marker!r} matched {len(matches)} blocks")
    return matches[0]


def check(name, code, stdin, expected):
    result, executable = compile_code(code, f"run-{name}", static=True)
    if result.returncode != 0:
        failures.append(f"{name} compile: {result.stderr[:1000]}")
        print(f"[run-fail] {name} compile")
        return
    if result.stderr.strip():
        failures.append(f"{name} warnings: {result.stderr.strip()[:500]}")
        print(f"[run-fail] {name} warnings")
        return
    run = subprocess.run([str(executable)], input=stdin, capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=15)
    actual = run.stdout.replace("\r\n", "\n")
    if run.returncode != 0 or actual != expected:
        failures.append(f"{name}: rc={run.returncode}, expected={expected!r}, actual={actual!r}, stderr={run.stderr[:300]!r}")
        print(f"[run-fail] {name}: expected={expected!r}, actual={actual!r}")
    else:
        print(f"[run-pass] {name}")


m3 = "1 2 3\n4 5 6\n7 8 9\n"
m34 = "1 2 3 4\n5 6 7 8\n9 10 11 12\n"

check("case-toggle", find_block("else if (s[i] >= 'A' && s[i] <= 'Z')"),
      "SyuctOJ 04: AbZ-z!\n", "sYUCToj 04: aBz-Z!\n")
check("palindrome", find_block("bool palindrome = true"), "level\n", "YES\n")
check("find", find_block("size_t position = text.find(word);"), "abracadabra cad\n", "4\n")
check("matrix-echo", find_block("cout << a[row][column] << (column + 1 == m ? '\\n' : ' ');"),
      "3 4\n" + m34, m34)
check("matrix-add", find_block("int sum = a[row][column] + b[row][column];"),
      "3 3\n" + m3 + "9 8 7\n6 5 4\n3 2 1\n", "10 10 10\n10 10 10\n10 10 10\n")
check("row-column-sums", find_block("rowSum[row] += a[row][column];"),
      "3 3\n" + m3, "6\n15\n24\n12 15 18\n")
check("diagonals", find_block("antiSum += a[row][n - 1 - row];"),
      "3\n" + m3, "15\n15\n")
check("transpose", find_block("transposed[column][row] = a[row][column];"),
      "3 4\n" + m34, "1 5 9\n2 6 10\n3 7 11\n4 8 12\n")
check("neighbors", find_block("counts[row][column] = count;"),
      "3 3\n010\n101\n110\n", "2 0 2\n1 4 0\n2 1 2\n")
check("palindrome-repair", find_block("int right = n - 1;"), "4\nabca\n", "1\n")
check("checkerboard", find_block("cout << 'A';"), "3 4\n", "ABAB\nBABA\nABAB\n")
check("minimum-period", find_block("cout << answer << ' ' << s.substr(0, answer)"),
      "abcabcabc\n", "3 abc\n")

base = find_block("cout << a[row][column] << (column + 1 == m ? '\\n' : ' ');")
output_loop = """    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cout << a[row][column] << (column + 1 == m ? '\\n' : ' ');
        }
    }
"""
if output_loop not in base:
    raise RuntimeError("base output loop not found")

maximum = find_block("int maximum = a[0][0];")
check("maximum-position", base.replace(output_loop, maximum),
      "3 3\n3 8 1\n5 9 2\n7 4 6\n", "9 2 2\n")

reverse_rows = find_block("for (int left = 0, right = m - 1; left < right; left++, right--)")
check("reverse-rows", base.replace(output_loop, reverse_rows + "\n\n" + output_loop),
      "3 4\n" + m34, "4 3 2 1\n8 7 6 5\n12 11 10 9\n")

rotate = find_block("rotated[column][n - 1 - row] = a[row][column];")
rotate_program = base.replace("int a[MAXN][MAXN];", "int a[MAXN][MAXN];\nint rotated[MAXN][MAXN];")
check("rotate", rotate_program.replace(output_loop, rotate),
      "3 4\n" + m34, "9 5 1\n10 6 2\n11 7 3\n12 8 4\n")

border = find_block("long long borderSum = 0;")
check("border", base.replace(output_loop, border), "3 4\n" + m34, "65\n")

submatrix = find_block("long long subSum = 0;")
submatrix_program = base.replace("int n, m;", "int n, m, q;").replace("cin >> n >> m;", "cin >> n >> m >> q;")
check("submatrix", submatrix_program.replace(output_loop, submatrix),
      "3 4 2\n" + m34 + "1 2 2 3\n1 1 3 4\n", "18\n78\n")


def wrap(body, declarations):
    return ("#include <iostream>\n#include <string>\nusing namespace std;\n"
            "int main()\n{\n" + declarations + body + "    return 0;\n}\n")


vowels = find_block("int counts[5] = {};")
check("vowels", wrap(vowels, "    string s;\n    getline(cin, s);\n"),
      "HeLloWorld\n", "0 1 0 2 0\n")

replace = find_block("if (s[i] == x)")
check("character-replace", wrap(replace, "    string s;\n    cin >> s;\n    int len = s.size();\n"),
      "banana\na o\n", "bonono\n")

substring = find_block("cout << s.substr(l - 1, r - l + 1) << '\\n';")
check("substring", wrap(substring, "    string s;\n    int l, r;\n    cin >> s >> l >> r;\n"),
      "helloworld\n4 7\n", "lowo\n")

print(f"verification complete: unexpected failures={len(failures)}")
for failure in failures:
    print(f"[failure] {failure}")
sys.exit(1 if failures else 0)
