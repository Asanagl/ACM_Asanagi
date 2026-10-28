import sys


def main() -> None:
    tokens = sys.stdin.buffer.read().split()
    if not tokens:
        return
    try:
        n = int(tokens[0])
        values = [int(token) for token in tokens[1:]]
    except (TypeError, ValueError):
        return
    if n < 1 or n > 200_001 or n % 2 == 0 or len(values) != n:
        return
    if any(value < -1_000_000_000 or value > 1_000_000_000 for value in values):
        return

    values = sorted(values)
    median = values[(n - 1) // 2]
    total = sum(abs(value - median) for value in values)
    if total <= 2**63 - 1:
        sys.stdout.write(f"{median} {total}\n")


if __name__ == "__main__":
    main()
