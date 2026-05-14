import sys

MOD = 998244353

t = int(sys.stdin.readline().strip())
for _ in range(t):
    data = sys.stdin.readline().split()
    n = int(data[0])
    k = int(data[1])
    a = list(map(int, sys.stdin.readline().split()))
    current = k
    for i in range(n):
        if i % 2 == 0:
            current = current << a[i]
        else:
            current = current >> a[i]
    print(current % MOD)