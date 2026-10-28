#!/bin/bash
P=/c/Users/Asanagi/eropch-blog/problemsets/2026syuctacm-weekly-04/problems/17
mkdir -p cases
python - <<'PY' > cases/list.txt
import json
cfg=json.load(open(r'C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04\problems\17\config.json',encoding='utf-8'))
for c in cfg['generator']['cases']:
    print(c['name'], c['type'], c['seed'], c['group'])
PY
while read name type seed group; do
  ./gen_static.exe "$type" "$seed" > "cases/$name.in"
  ./val-s.exe < "cases/$name.in" > /dev/null 2>"cases/$name.valerr" || echo "VALIDATOR FAIL $name"
done < cases/list.txt
echo "generated $(ls cases/*.in | wc -l) cases"
