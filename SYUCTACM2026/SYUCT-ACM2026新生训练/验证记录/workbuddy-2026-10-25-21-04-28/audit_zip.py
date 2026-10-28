import os, sys, json, zipfile, hashlib, re
import yaml

ROOT = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04"
PROB = os.path.join(ROOT, "problems")
HYDRO = os.path.join(ROOT, "hydro")

TITLES = ["字符串的头和尾", "空格计数", "元音计数", "大小写互换", "字符替换", "反转字符串",
          "回文判断", "子串在哪里", "截取一段", "数字串求和", "矩阵原样输出", "矩阵加法",
          "每行的和", "每列的和", "最大值的位置", "两条对角线", "每行逆序", "矩阵转置",
          "顺时针旋转", "边框元素之和", "四邻格统计", "子矩阵求和", "回文修补", "棋盘染色",
          "最短循环节"]

FORBIDDEN = ["solution", "tutorial", "generator", "validator", "wrong", "statement.md", "readme.md"]

report = []
pids = {}
for i in range(1, 26):
    pid = "%02d" % i
    zp = os.path.join(HYDRO, pid + ".zip")
    row = {"pid": pid, "zip": os.path.basename(zp), "problems": []}
    if not os.path.isfile(zp):
        row["problems"].append("ZIP MISSING")
        report.append(row); continue

    cfg = json.load(open(os.path.join(PROB, pid, "config.json"), encoding="utf-8"))
    man = json.load(open(os.path.join(PROB, pid, "exported-tests", "manifest.json"), encoding="utf-8"))

    with zipfile.ZipFile(zp) as z:
        names = z.namelist()
        row["entries"] = len(names)
        base = [n for n in names if n.count("/") == 0]
        # find problem root prefix (should be a single top dir)
        tops = sorted({n.split("/")[0] for n in names})
        if len(tops) != 1:
            row["problems"].append("not one top dir: %s" % tops)
            report.append(row); continue
        top = tops[0]

        def need(rel):
            if top + "/" + rel not in names:
                row["problems"].append("missing " + rel)
                return False
            return True

        ok = True
        for rel in ["problem.yaml", "problem_zh.md", "testdata/config.yaml", "testdata/checker.cpp"]:
            ok = need(rel) and ok
        if not ok:
            report.append(row); continue

        py = yaml.safe_load(z.read(top + "/problem.yaml").decode("utf-8"))
        row["title"] = py.get("title")
        row["pid_field"] = py.get("pid")
        if py.get("title") != TITLES[i-1]:
            row["problems"].append("title mismatch: %r" % py.get("title"))
        if py.get("pid") in pids:
            row["problems"].append("pid collision with %s" % pids[py.get("pid")])
        pids[py.get("pid")] = pid

        md = z.read(top + "/problem_zh.md").decode("utf-8")
        row["md_bytes"] = len(md.encode("utf-8"))
        if len(md.strip()) < 200:
            row["problems"].append("problem_zh.md too short")
        if "输入" not in md or "输出" not in md:
            row["problems"].append("problem_zh.md lacks 输入/输出 sections")
        if re.search(r"^#\s+", md, re.M):
            row["problems"].append("problem_zh.md still has Markdown H1 title")

        cy = yaml.safe_load(z.read(top + "/testdata/config.yaml").decode("utf-8"))
        row["checker_type"] = cy.get("checker_type")
        row["checker_file"] = (cy.get("checker") or {}).get("file")
        if cy.get("type") != "default":
            row["problems"].append("type != default: %r" % cy.get("type"))
        if cy.get("checker_type") != "testlib":
            row["problems"].append("checker_type != testlib")
        if (cy.get("checker") or {}).get("file") != "checker.cpp":
            row["problems"].append("checker file != checker.cpp")

        cases = []
        for st in cy.get("subtasks", []):
            for c in st.get("cases", []):
                cases.append(c)
        row["cases_in_zip"] = len(cases)
        row["cases_manifest"] = man["caseCount"]
        if len(cases) != man["caseCount"]:
            row["problems"].append("case count %d != manifest %d" % (len(cases), man["caseCount"]))

        # every case must have both files present, and answers must be non-empty
        listed_in, listed_ans = set(), set()
        empty_ans = 0
        for c in cases:
            fi, fo = c.get("input"), c.get("output")
            listed_in.add(fi); listed_ans.add(fo)
            for rel in [fi, fo]:
                if top + "/testdata/" + rel not in names:
                    row["problems"].append("case file missing: " + rel)
            ap = top + "/testdata/" + fo
            if ap in names and z.getinfo(ap).file_size == 0:
                empty_ans += 1
        if empty_ans:
            row["problems"].append("%d empty .ans" % empty_ans)

        # actual .in/.ans files in zip must match the listed set
        actual_in = {n[len(top) + len("/testdata/"):] for n in names
                     if n.startswith(top + "/testdata/") and n.endswith(".in")}
        actual_ans = {n[len(top) + len("/testdata/"):] for n in names
                      if n.startswith(top + "/testdata/") and n.endswith(".ans")}
        if actual_in != listed_in:
            row["problems"].append("stray/missing .in files")
        if actual_ans != listed_ans:
            row["problems"].append("stray/missing .ans files")

        # no internal material
        low = " ".join(names).lower()
        for bad in FORBIDDEN:
            if bad in low:
                row["problems"].append("leaks internal material: " + bad)

        # sample / secret split from manifest groups
        groups = {}
        for c in man["cases"]:
            groups[c["group"]] = groups.get(c["group"], 0) + 1
        row["groups"] = groups
        if groups.get("sample", 0) < 1:
            row["problems"].append("no sample case")
        if groups.get("secret", 0) < 30:
            row["problems"].append("secret < 30")

        # distinctness of secret inputs
        secret_hashes = set()
        secret_total = 0
        for c in man["cases"]:
            if c["group"] != "secret":
                continue
            secret_total += 1
            src = os.path.join(PROB, pid, "exported-tests", c["input"].replace("/", os.sep))
            if os.path.isfile(src):
                secret_hashes.add(hashlib.md5(open(src, "rb").read()).hexdigest())
        row["secret_distinct"] = len(secret_hashes)
        if secret_total and len(secret_hashes) != secret_total:
            row["problems"].append("duplicate secret inputs: %d/%d distinct" % (len(secret_hashes), secret_total))

        # content equality vs exported-tests
        mism = 0
        for c in man["cases"]:
            src = os.path.join(PROB, pid, "exported-tests", c["input"].replace("/", os.sep))
            dst = top + "/testdata/" + c["input"]
            if top + "/testdata/" + c["input"] not in names:
                continue
            a = open(src, "rb").read()
            b = z.read(dst)
            if a != b:
                mism += 1
        if mism:
            row["problems"].append("%d case contents differ from exported-tests" % mism)

    row["ok"] = not row["problems"]
    report.append(row)

for r in report:
    st = "OK " if r.get("ok") else "BAD"
    print("%s %s title=%r pid=%s cases=%s/%s groups=%s %s" % (
        st, r["pid"], r.get("title"), r.get("pid_field"),
        r.get("cases_in_zip"), r.get("cases_manifest"), r.get("groups"), r["problems"]))
json.dump(report, open(r"C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28\zip_audit.json", "w", encoding="utf-8"),
          ensure_ascii=False, indent=1)
print("\nBAD COUNT:", sum(1 for r in report if not r.get("ok")))
