from bs4 import BeautifulSoup
from pathlib import Path
import difflib
import re

old_html = Path('public/2026/09/23/xcpc-cpp-guide-ch1-variables/index.html').read_text(encoding='utf-8')
new_html = Path('.tmp/current-ch1.html').read_text(encoding='utf-8')
old_soup = BeautifulSoup(old_html, 'html.parser').select_one('div.e-content')
new_soup = BeautifulSoup(new_html, 'html.parser')
for gutter in old_soup.select('.gutter'):
    gutter.decompose()

def lines(soup):
    result = []
    for raw in soup.get_text('\n').splitlines():
        line = re.sub(r'\s+', ' ', raw).strip()
        if line:
            result.append(line)
    return result

old_lines = lines(old_soup)
new_lines = lines(new_soup)
diff = difflib.unified_diff(old_lines, new_lines, fromfile='previous', tofile='current', lineterm='', n=2)
Path('.tmp/ch1-content.diff').write_text('\n'.join(diff), encoding='utf-8')
print(f'previous text lines={len(old_lines)}, current text lines={len(new_lines)}')
