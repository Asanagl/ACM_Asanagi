#!/bin/bash
seed=12345
pass=0
fail=0
for i in $(seq 1 120); do
  ./gen_static.exe stress-small $seed > case.in
  if ! ./val-s.exe < case.in > /dev/null 2>val.err; then echo "VALIDATOR FAIL seed=$seed"; cat val.err; fail=$((fail+1)); break; fi
  ./solution-s.exe < case.in > main.out
  ./solution2-s.exe < case.in > ref.out
  if cmp -s main.out ref.out; then pass=$((pass+1)); else
    echo "MISMATCH seed=$seed"; cp case.in mismatch-$seed.in; fail=$((fail+1))
  fi
  seed=$((seed+1))
done
echo "pass=$pass fail=$fail last_seed=$((seed-1))"
