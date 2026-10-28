import re

s = open('p217.html', encoding='utf-8', errors='ignore').read()
best = None
for m in re.finditer(r'"content"\s*:\s*"((?:[^"\\]|\\.)*)"', s):
    if best is None or len(m.group(1)) > len(best[0]):
        best = (m.group(1), m.start())
print('best len:', len(best[0]))
print('best tail:', repr(best[0][-80:]))
endpos = best[1] + len('"content":') + 1 + len(best[0])
print('after match:', repr(s[endpos:endpos+80]))
