#!/bin/bash
for w in wrong-global wrong-vertical wrong-double-swap wrong-odd-skip; do
  killed=""; first=""
  while read name type seed group; do
    ./$w-s.exe < "cases/$name.in" > "cases/$name.$w" 2>/dev/null
    rc=$?
    if ! ./chk-s.exe "cases/$name.in" "cases/$name.$w" "cases/$name.main" > /dev/null 2>&1 || [ $rc -ne 0 ]; then
      killed="$killed $name"
      [ -z "$first" ] && first="$name"
    fi
  done < cases/list.txt
  echo "=== $w: killed_by=$(echo $killed | wc -w) first=$first"
  echo "    $killed"
done
