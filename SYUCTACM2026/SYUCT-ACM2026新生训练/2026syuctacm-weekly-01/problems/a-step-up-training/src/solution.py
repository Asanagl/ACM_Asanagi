import sys


def main() -> None:
    tokens = sys.stdin.buffer.read().split()
    if len(tokens) != 1:
        return
    try:
        n = int(tokens[0])
    except (TypeError, ValueError):
        return
    if not 1 <= n <= 1_000_000:
        return

    answer = n * (n + 1) * (n + 2) // 3
    if answer <= 2**63 - 1:
        sys.stdout.write(f"{answer}\n")


if __name__ == "__main__":
    main()
