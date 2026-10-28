import os, json, sys

ROOTS = [
    ("A_eropch-blog/problemsets", r"C:\Users\Asanagi\eropch-blog\problemsets"),
    ("B_codex-skill", r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator"),
    ("C_workbuddy-temp", r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28"),
]

CATS = ["题目(题面)", "题解", "数据(.in/.ans/testdata)", "标程", "SPJ/checker", "validator/generator",
        "图片素材", "文档(md/pdf/xlsx/html/csv)", "工具链脚本", "编译产物/日志/临时", "其他"]

def classify(rel):
    r = rel.replace("\\", "/").lower()
    base = os.path.basename(r)
    if r.startswith(".codex-test-artifacts") or "/build/" in r or "/bin/" in r:
        return "编译产物/日志/临时"
    if base.endswith((".png", ".jpg", ".jpeg", ".gif", ".webp", ".svg", ".bmp")):
        return "图片素材"
    if base.endswith((".in", ".ans", ".interactor.in")):
        return "数据(.in/.ans/testdata)"
    if "exported-tests" in r or "/testdata/" in r or "/generated/" in r:
        return "数据(.in/.ans/testdata)"
    if "checker.cpp" in r or "interactor" in r or "specialjudge" in r:
        return "SPJ/checker"
    if base in ("solution.cpp", "solution2.cpp", "solution.py") or "/src/solution" in r:
        return "标程"
    if "validator" in r:
        return "validator/generator"
    if "generator" in r:
        return "validator/generator"
    if base == "statement.md" or base == "problem_zh.md" or base == "problem.yaml":
        return "题目(题面)"
    if base == "tutorial.md":
        return "题解"
    if base.endswith((".md", ".pdf", ".docx", ".doc", ".xlsx", ".xls", ".html", ".htm", ".csv", ".txt", ".json")):
        return "文档(md/pdf/xlsx/html/csv)"
    if base.endswith((".ps1", ".py", ".sh")):
        return "工具链脚本"
    if base.endswith((".cpp", ".h", ".hpp")) and "testlib" not in r:
        return "标程"
    if base.endswith((".cpp", ".h")):
        return "工具链脚本"
    if base.endswith((".exe", ".o", ".a", ".obj", ".log", ".out", ".zip", ".7z", ".rar")):
        return "编译产物/日志/临时"
    return "其他"

report = {}
for label, root in ROOTS:
    stats = {c: [0, 0] for c in CATS}   # count, bytes
    top = {}
    if not os.path.isdir(root):
        report[label] = {"missing": True}
        continue
    for dirpath, dirnames, filenames in os.walk(root):
        for fn in filenames:
            p = os.path.join(dirpath, fn)
            try:
                sz = os.path.getsize(p)
            except OSError:
                continue
            rel = os.path.relpath(p, root)
            c = classify(rel)
            stats[c][0] += 1
            stats[c][1] += sz
            parts = rel.replace("\\", "/").split("/")
            key = parts[0] if len(parts) > 1 else "(root files)"
            top.setdefault(key, [0, 0])
            top[key][0] += 1
            top[key][1] += sz
    report[label] = {
        "root": root,
        "total_files": sum(v[0] for v in stats.values()),
        "total_mb": round(sum(v[1] for v in stats.values()) / 1048576, 1),
        "cats": {c: [v[0], round(v[1] / 1048576, 2)] for c, v in stats.items() if v[0]},
        "top": {k: [v[0], round(v[1] / 1048576, 1)] for k, v in
                sorted(top.items(), key=lambda kv: -kv[1][1])[:12]},
    }

json.dump(report, open(r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28\move_inventory.json", "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)

for label, r in report.items():
    if r.get("missing"):
        print(label, "MISSING"); continue
    print("=" * 70)
    print("%s  %s" % (label, r["root"]))
    print("  合计 %d 个文件, %.1f MiB" % (r["total_files"], r["total_mb"]))
    for c, (n, mb) in sorted(r["cats"].items(), key=lambda kv: -kv[1][1]):
        print("    %-26s %5d 个  %8.1f MiB" % (c, n, mb))
    print("  顶层条目：")
    for k, (n, mb) in r["top"].items():
        print("    %-24s %5d 个  %8.1f MiB" % (k, n, mb))
