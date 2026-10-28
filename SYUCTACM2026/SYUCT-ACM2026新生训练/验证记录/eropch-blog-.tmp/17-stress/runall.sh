#!/bin/bash
P=/c/Users/Asanagi/eropch-blog/problemsets/2026syuctacm-weekly-04/problems/17
total=0; mainfail=0
while read name type seed group; do
  total=$((total+1))
  ./solution-s.exe  < "cases/$name.in" > "cases/$name.main"
  ./solution2-s.exe < "cases/$name.in" > "cases/$name.ref"
  if ! ./chk-s.exe "cases/$name.in" "cases/$name.main" "cases/$name.ref" > /dev/null 2>"cases/$name.chk"; then
     echo "CHECK FAIL(main) $name: $(head -2 cases/$name.chk)"; mainfail=$((mainfail+1))
  fi
  # solution2 as user-answer checked against main-derived answer
  if ! ./chk-s.exe "cases/$name.in" "cases/$name.ref" "cases/$name.main" > /dev/null 2>"cases/$name.chk2"; then
     echo "CHECK FAIL(ref) $name"; mainfail=$((mainfail+1))
  fi
done < cases/list.txt
echo "cases=$total problems=$mainfail"
