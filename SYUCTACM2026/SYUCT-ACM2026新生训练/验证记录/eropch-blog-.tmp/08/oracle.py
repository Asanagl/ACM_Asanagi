import sys
def solve(s,t):
    n,m=len(s),len(t)
    for i in range(n-m+1):
        if s[i:i+m]==t: return i
    return -1
lines=sys.stdin.read().split('\n')
s=lines[0].strip(); t=lines[1].strip()
print(solve(s,t))
