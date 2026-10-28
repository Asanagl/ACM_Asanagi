import re, html, glob, json

def unesc(s):
    def rep(m):
        c = m.group(1)
        return {'n': '\n', 't': '\t', 'r': '\r', '"': '"', "'": "'",
                '\\': '\\', '/': '/', 'b': '\b', 'f': '\f'}.get(c, c)
    s = re.sub(r'\\u([0-9a-fA-F]{4})', lambda m: chr(int(m.group(1), 16)), s)
    return re.sub(r'\\(.)', rep, s)

def clean(t):
    # merge surrogate pairs produced by per-\uXXXX decoding (math italic letters etc.)
    try:
        t = t.encode('utf-16', 'surrogatepass').decode('utf-16')
    except Exception:
        pass
    t = re.sub(r'<[^>]+>', ' ', t)
    t = html.unescape(t)
    return re.sub(r'[ \t]+', ' ', t)

out = []
for f in sorted(glob.glob('p*.html'), key=lambda x: int(x[1:-5])):
    s = open(f, encoding='utf-8', errors='ignore').read()
    text = None
    # peel up to 4 escape layers over the whole page
    cur = s
    for layer in range(4):
        cur = unesc(cur)
        # try direct string content
        for m in re.finditer(r'"content"\s*:\s*"((?:[^"\\]|\\.)*)"', cur):
            raw = m.group(1)
            c = unesc(raw)
            if c.lstrip().startswith('{'):
                c2 = unesc(c)
                san = re.sub(r'\\([^"\\/bfnrtu])', r'\\\\\1', c2)
                try:
                    obj = json.loads(san)
                    v = obj.get('zh') or obj.get('en')
                    if isinstance(v, str) and len(v) > 20:
                        text = v
                        break
                except Exception:
                    pass
                m2 = re.search(r'"zh"\s*:\s*"(.*)', c2, re.S)
                if m2:
                    text = unesc(m2.group(1).rsplit('"', 1)[0])
                    break
            elif len(c) > 20 and ('Description' in c or '题目' in c or '# ' in c):
                text = c
                break
        if text:
            break
    if not text:
        out.append(f'{f}: NO CONTENT')
        continue
    out.append('=' * 10 + ' ' + f)
    out.append(clean(text)[:700])
    out.append('')

open('statements.txt', 'w', encoding='utf-8').write('\n'.join(out))
print('done')
