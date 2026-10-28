import re, html, json

def unesc(s):
    def rep(m):
        c = m.group(1)
        return {'n': '\n', 't': '\t', 'r': '\r', '"': '"', "'": "'",
                '\\': '\\', '/': '/', 'b': '\b', 'f': '\f'}.get(c, c)
    s = re.sub(r'\\u([0-9a-fA-F]{4})', lambda m: chr(int(m.group(1), 16)), s)
    return re.sub(r'\\(.)', rep, s)

s = open('p2449.html', encoding='utf-8', errors='ignore').read()
cur = s
for layer in range(4):
    cur = unesc(cur)
    for m in re.finditer(r'"content"\s*:\s*"((?:[^"\\]|\\.)*)"', cur):
        c = unesc(m.group(1))
        if c.lstrip().startswith('{'):
            c2 = unesc(c)
            m2 = re.search(r'"zh"\s*:\s*"(.*)', c2, re.S)
            if m2:
                t = unesc(m2.group(1).rsplit('"', 1)[0])
                t = re.sub(r'<[^>]+>', ' ', t)
                if len(t) > 200:
                    print(t)
                    raise SystemExit
print('not found')
