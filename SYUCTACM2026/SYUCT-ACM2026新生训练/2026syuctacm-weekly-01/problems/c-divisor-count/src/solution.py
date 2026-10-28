import math
import sys


def count_divisors(n: int) -> int:
    answer = 0
    for divisor in range(1, math.isqrt(n) + 1):
        if n % divisor != 0:
            continue
        answer += 1 if divisor * divisor == n else 2
    return answer


def main() -> None:
    tokens = sys.stdin.buffer.read().split()
    if len(tokens) != 1:
        return
    try:
        n = int(tokens[0])
    except (TypeError, ValueError):
        return
    if not 1 <= n <= 1_000_000_000_000:
        return
    sys.stdout.write(f"{count_divisors(n)}\n")


if __name__ == "__main__":
    main()
