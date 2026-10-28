import sys


def main():
    data = sys.stdin.buffer.read().split()
    if len(data) < 2:
        return
    n = int(data[0])
    s = data[1]
    answer = sum(s[i] != s[n - 1 - i] for i in range(n // 2))
    print(answer)


if __name__ == "__main__":
    main()
