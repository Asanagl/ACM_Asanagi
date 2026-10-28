import os, sys, json, shutil, hashlib, time

SRC = [
    ("eropch-blog/problemsets", r"C:\Users\Asanagi\eropch-blog\problemsets"),
    ("eropch-blog/.tmp", r"C:\Users\Asanagi\eropch-blog\.tmp"),
    ("icpc-problem-creator", r"C:\Users\Asanagi\.codex\skills\icpc-problem-creator"),
    ("workbuddy-验证工作区", r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28"),
]

DOWNLOADS_PICK = [
    "03_357号样本_命题备注.md",
    "03_357号样本_最后一刀.md",
    "03_357号样本_最后一刀_题解.md",
    "最少转跳.md",
    "暑假恢复训练赛题解.pdf",
    "萌新向典题收集 v0.21.pdf",
    "2026级SYUCT-ACM新生第一次训练.html",
    "2026级SYUCT-ACM新生第二次训练.html",
    "第十三届校赛(重现赛+改题)暨2026级SYUCT-ACM新生第三次部分训练暨SYUCTACM周赛#1.html",
    "SYUCT标签过题榜单_2026-10-17.csv",
    "牛客竞赛标签过题榜单_2026-10-17.csv",
    "实验1、2实验报告模版及实验题目.rar",
]

DST_ROOT = r"C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练"

CAT_题目, CAT_题解, CAT_数据, CAT_标程, CAT_错解 = "题目", "题解", "数据", "标程", "错解"
CAT_SPJ, CAT_校验, CAT_图片, CAT_文档 = "SPJ", "校验与生成", "图片", "文档"
CAT_工具, CAT_编译, CAT_验证, CAT_交付 = "工具链", "编译产物", "验证记录", "交付包"

IMG = (".png", ".jpg", ".jpeg", ".gif", ".webp", ".svg", ".bmp", ".ico")
DOC = (".md", ".pdf", ".docx", ".doc", ".xlsx", ".xls", ".html", ".htm", ".csv",
       ".txt", ".pptx", ".ppt")
BUILD = (".exe", ".o", ".a", ".obj", ".log", ".out", ".zip", ".7z", ".rar", ".dll")

SKIP_DIRS = {".workbuddy", ".git", "node_modules"}


def classify(label, rel):
    r = rel.replace("\\", "/")
    low = r.lower()
    base = os.path.basename(low)
    top = low.split("/")[0]

    # 来源 C：验证工作区
    if label.startswith("workbuddy"):
        if top == "bin":
            return CAT_编译
        if top in ("logs", "diffs") or low.endswith(".log"):
            return CAT_验证
        if top == "blind":
            return CAT_验证
        if low.endswith((".json",)) and ("summary" in low or "audit" in low or "inventory" in low):
            return CAT_验证
        if top in ("dbg", "tmp24"):
            return CAT_编译
        if base.endswith((".py", ".ps1", ".sh")):
            return CAT_工具
        return CAT_编译

    # 来源 D：仓库根 .tmp（历轮盲审 / 压测 / 验证记录）
    if label == "eropch-blog/.tmp":
        if base.endswith((".exe", ".out", ".err", ".ref", ".cmd", ".o", ".a", ".dll")):
            return CAT_编译
        if base.endswith((".in", ".ans")):
            return CAT_数据
        return CAT_验证

    # 来源 B：skill
    if label == "icpc-problem-creator":
        if top == ".codex-test-artifacts":
            return CAT_编译
        if base.endswith(BUILD):
            return CAT_编译
        if base.endswith((".ps1", ".py", ".sh", ".h", ".hpp")):
            return CAT_工具
        return CAT_工具

    # 来源 A：题集
    if "/docs/statement.md" in low or base in ("problem_zh.md", "problem.yaml", "config.json"):
        return CAT_题目
    if "/docs/tutorial.md" in low:
        return CAT_题解
    if "/src/solution" in low or base.startswith("solution"):
        return CAT_标程
    if "/src/wrong/" in low:
        return CAT_错解
    if "/src/checker/" in low or "interactor" in low or "specialjudge" in low:
        return CAT_SPJ
    if "/src/validator/" in low:
        return CAT_校验
    if "/src/generator/" in low:
        return CAT_校验
    if "testlib" in low:
        return CAT_校验
    if "/exported-tests/" in low or "/testdata/" in low or "/generated/" in low:
        return CAT_数据
    if base.endswith((".in", ".ans")):
        return CAT_数据
    if base.endswith(".zip"):
        return CAT_交付
    if base.endswith(IMG):
        return CAT_图片
    if base.endswith(BUILD):
        return CAT_编译
    if base.endswith(DOC):
        return CAT_文档
    if base.endswith((".cpp", ".h", ".hpp")):
        return CAT_标程
    return CAT_文档


def dest_prefix(label, rel):
    """目标子目录内的第二级：保留来源与原始相对路径，保证可追溯。"""
    r = rel.replace("\\", "/")
    if label.startswith("workbuddy"):
        return "workbuddy-验证工作区/" + r
    if label == "icpc-problem-creator":
        return "icpc-problem-creator/" + r
    if label == "eropch-blog/.tmp":
        return "eropch-blog/.tmp/" + r
    return r  # 题集：本身就以题集名开头


plan = []
for label, root in SRC:
    if not os.path.isdir(root):
        print("跳过（不存在）:", root)
        continue
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d not in SKIP_DIRS]
        for fn in filenames:
            p = os.path.join(dirpath, fn)
            if not os.path.isfile(p):
                continue
            rel = os.path.relpath(p, root)
            cat = classify(label, rel)
            dst = os.path.join(DST_ROOT, cat, dest_prefix(label, rel))
            plan.append({"src": p, "dst": dst, "cat": cat, "size": os.path.getsize(p)})

# Downloads 零散文件
for fn in DOWNLOADS_PICK:
    p = os.path.join(r"C:\Users\Asanagi\Downloads", fn)
    if os.path.isfile(p):
        plan.append({"src": p, "dst": os.path.join(DST_ROOT, CAT_文档, "downloads-零散命题文件", fn),
                     "cat": CAT_文档, "size": os.path.getsize(p)})
    else:
        print("Downloads 中未找到:", fn)

# 目标已存在内容（不得覆盖）
existing = set()
for dp, dn, fnames in os.walk(DST_ROOT):
    for f in fnames:
        existing.add(os.path.normcase(os.path.join(dp, f)))

# 重名处理
seen = {}
renamed = 0
for item in plan:
    dst = item["dst"]
    key = os.path.normcase(dst)
    if key in seen or key in existing:
        stem, ext = os.path.splitext(dst)
        n = seen.get(key, 0) + 1
        while True:
            cand = "%s_%d%s" % (stem, n, ext)
            if os.path.normcase(cand) not in seen and os.path.normcase(cand) not in existing:
                break
            n += 1
        seen[key] = n
        item["dst"] = cand
        item["renamed_from"] = dst
        renamed += 1
    seen[os.path.normcase(item["dst"])] = 1

total_bytes = sum(i["size"] for i in plan)
print("=" * 78)
print("迁移清单：%d 个文件, %.1f MiB, 重名自动改名 %d 个" % (len(plan), total_bytes / 1048576, renamed))
from collections import Counter
c = Counter(i["cat"] for i in plan)
for cat, n in sorted(c.items(), key=lambda kv: -kv[1]):
    b = sum(i["size"] for i in plan if i["cat"] == cat)
    print("   %-10s %5d 个  %9.1f MiB" % (cat, n, b / 1048576))

# 落盘清单
os.makedirs(DST_ROOT, exist_ok=True)
manifest_json = os.path.join(DST_ROOT, "_迁移清单.json")
with open(manifest_json, "w", encoding="utf-8") as f:
    json.dump({"generatedAt": time.strftime("%Y-%m-%d %H:%M:%S"),
               "count": len(plan), "totalBytes": total_bytes,
               "items": plan}, f, ensure_ascii=False, indent=1)

with open(os.path.join(DST_ROOT, "_迁移清单.txt"), "w", encoding="utf-8") as f:
    f.write("SYUCT-ACM2026新生训练 出题材料迁移清单\n")
    f.write("生成时间: %s\n" % time.strftime("%Y-%m-%d %H:%M:%S"))
    f.write("文件数: %d   合计: %.1f MiB   自动改名: %d\n\n" % (len(plan), total_bytes / 1048576, renamed))
    for cat in sorted(c, key=lambda k: -c[k]):
        f.write("\n### %s (%d)\n" % (cat, c[cat]))
        for i in plan:
            if i["cat"] == cat:
                tag = "  [重名->%s]" % os.path.basename(i["dst"]) if "renamed_from" in i else ""
                f.write("  %s\n    -> %s%s\n" % (i["src"], i["dst"], tag))

print("\n清单已写入:")
print("  " + manifest_json)
print("  " + os.path.join(DST_ROOT, "_迁移清单.txt"))

if "--dry-run" in sys.argv:
    print("\n[dry-run] 未执行移动。")
    sys.exit(0)

# 执行移动
print("\n开始移动 ...")
moved, failed = 0, []
t0 = time.time()
for i, item in enumerate(plan):
    src, dst = item["src"], item["dst"]
    try:
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        if os.path.normcase(src) == os.path.normcase(dst):
            continue
        try:
            os.rename(src, dst)          # 同卷：瞬间完成
        except OSError:
            shutil.copy2(src, dst)
            if os.path.getsize(src) != os.path.getsize(dst):
                raise IOError("size mismatch after copy")
            os.remove(src)
        moved += 1
    except Exception as e:
        failed.append({"src": src, "dst": dst, "err": str(e)})
    if (i + 1) % 1000 == 0:
        print("   ... %d/%d (%.0fs)" % (i + 1, len(plan), time.time() - t0))

print("\n移动完成：成功 %d，失败 %d，耗时 %.1fs" % (moved, len(failed), time.time() - t0))
for f_ in failed[:20]:
    print("  失败:", f_["src"], "->", f_["err"][:120])

# 校验：目标文件数与总字节
got_n, got_b = 0, 0
for dp, dn, fnames in os.walk(DST_ROOT):
    for f in fnames:
        got_n += 1
        got_b += os.path.getsize(os.path.join(dp, f))
print("\n目标目录当前：%d 个文件, %.1f MiB" % (got_n, got_b / 1048576))
print("（含原有 5 个 xlsx 与 2 个清单文件）")

json.dump({"moved": moved, "failed": failed}, open(
    r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28\move_result.json", "w", encoding="utf-8"),
    ensure_ascii=False, indent=1)
