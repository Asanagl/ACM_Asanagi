import sys

def main():
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    n = int(data[0])
    m = int(data[1])
    vals = data[2:2 + n * m]
    out = []
    for i in range(n):
        s = 0
        base = i * m
        for j in range(m):
            s += int(vals[base + j])
        out.append(str(s))
    sys.stdout.write("\n".join(out) + "\n")

main()
