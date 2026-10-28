import json, os, sys, glob

ROOT = r"C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04"
P = os.path.join(ROOT, "problems")

req = [
    "config.json",
    "docs/statement.md",
    "docs/tutorial.md",
    "src/solution.cpp",
    "src/solution2.cpp",
    "src/validator/validator.cpp",
    "src/generator/generator.cpp",
    "src/checker/checker.cpp",
    "include/testlib.h",
]

rows = []
for i in range(1, 26):
    pid = "%02d" % i
    d = os.path.join(P, pid)
    row = {"pid": pid}
    miss = []
    for f in req:
        ok = os.path.isfile(os.path.join(d, f.replace("/", os.sep)))
        row[f] = ok
        if not ok:
            miss.append(f)
    wrong = sorted(glob.glob(os.path.join(d, "src", "wrong", "*.cpp")))
    row["wrong"] = [os.path.basename(w) for w in wrong]
    # manifest
    mf = os.path.join(d, "exported-tests", "manifest.json")
    row["manifest"] = os.path.isfile(mf)
    if row["manifest"]:
        try:
            m = json.load(open(mf, encoding="utf-8"))
            row["manifest_n"] = len(m.get("tests", m.get("cases", []))) if isinstance(m, dict) else len(m)
        except Exception as e:
            row["manifest_n"] = "ERR:%s" % e
    else:
        row["manifest_n"] = None
    # config sample/secret
    cf = os.path.join(d, "config.json")
    row["sample"] = None
    row["secret"] = None
    row["cfg_err"] = None
    if os.path.isfile(cf):
        try:
            c = json.load(open(cf, encoding="utf-8"))
            cases = c.get("cases") or c.get("generator", {}).get("cases") or []
            if isinstance(cases, dict):
                cases = cases.get("cases", [])
            s = sum(1 for x in cases if isinstance(x, dict) and (x.get("group") == "sample"))
            row["sample"] = s
            row["secret"] = len(cases) - s
            row["cases_n"] = len(cases)
            row["timeLimit"] = c.get("timeLimitMs")
        except Exception as e:
            row["cfg_err"] = str(e)
    # exported-tests dir
    et = os.path.join(d, "exported-tests")
    row["exported"] = os.path.isdir(et)
    if row["exported"]:
        row["in_count"] = len(glob.glob(os.path.join(et, "*.in")))
    rows.append(row)

print("%-3s %-7s %-7s %-6s %-6s %-5s %-4s %-5s %-6s %s" % ("id","stmt","tut","sol","sol2","val","gen","chk","tl","wrong"))
print("-" * 110)
for r in rows:
    print("%-3s %-7s %-7s %-6s %-6s %-5s %-4s %-5s %-6s %s" % (
        r["pid"],
        "Y" if r["docs/statement.md"] else "-",
        "Y" if r["docs/tutorial.md"] else "-",
        "Y" if r["src/solution.cpp"] else "-",
        "Y" if r["src/solution2.cpp"] else "-",
        "Y" if r["src/validator/validator.cpp"] else "-",
        "Y" if r["src/generator/generator.cpp"] else "-",
        "Y" if r["src/checker/checker.cpp"] else "-",
        "Y" if r["include/testlib.h"] else "-",
        "%d %s" % (len(r["wrong"]), ",".join(w.replace(".cpp","") for w in r["wrong"])) if r["wrong"] else "NONE",
    ))
print()
print("%-3s %-5s %-6s %-8s %-8s %-6s %-5s %-6s" % ("id","cfg","samp","secret","manifest","exp?","in#","tl"))
print("-" * 60)
for r in rows:
    print("%-3s %-5s %-6s %-8s %-8s %-6s %-5s %-6s" % (
        r["pid"],
        "Y" if r["config.json"] else "-",
        r["sample"] if r["sample"] is not None else "?",
        r["secret"] if r["secret"] is not None else "?",
        (str(r["manifest_n"]) if r["manifest"] else "-"),
        "Y" if r["exported"] else "-",
        r["in_count"] if r["exported"] else "-",
        r.get("timeLimit", "-"),
    ))
print()
for r in rows:
    miss = [k for k in req if k in r and r[k] is False]
    if miss:
        print(r["pid"], "MISSING:", miss)
