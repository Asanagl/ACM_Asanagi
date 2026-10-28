import sys


def is_leap(year: int) -> bool:
    return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)


def days_in_month(year: int, month: int) -> int:
    lengths = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
    if month == 2:
        return lengths[1] + int(is_leap(year))
    return lengths[month - 1]


def main() -> None:
    tokens = sys.stdin.buffer.read().split()
    if len(tokens) != 4:
        return
    try:
        year, month, day, steps = (int(token) for token in tokens)
    except (TypeError, ValueError):
        return
    if not 1 <= year <= 4_000_000_000 or not 1 <= month <= 12:
        return
    if not 0 <= steps <= 100_000 or not 1 <= day <= days_in_month(year, month):
        return

    for _ in range(steps):
        day += 1
        if day <= days_in_month(year, month):
            continue
        day = 1
        month += 1
        if month <= 12:
            continue
        month = 1
        year += 1
    if year <= 4_000_000_000:
        sys.stdout.write(f"{year} {month} {day}\n")


if __name__ == "__main__":
    main()
