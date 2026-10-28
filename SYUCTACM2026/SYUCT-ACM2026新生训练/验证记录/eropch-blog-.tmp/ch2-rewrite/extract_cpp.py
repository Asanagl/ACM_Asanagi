import re, os, json

md = open('../../source/_posts/xcpc-cpp-guide-ch2-loops.md', encoding='utf-8').read()
blocks = re.findall(r'```cpp\n(.*?)```', md, re.S)
os.makedirs('verify', exist_ok=True)
manifest = []
for i, b in enumerate(blocks):
    name = f'ex{i:02d}.cpp'
    open(f'verify/{name}', 'w', encoding='utf-8').write(b)
    has_main = 'int main()' in b
    manifest.append({'i': i, 'name': name, 'main': has_main, 'first': b.splitlines()[0] if b.splitlines() else ''})
print(json.dumps(manifest, ensure_ascii=False, indent=1))
