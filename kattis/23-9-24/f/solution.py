import sys
from collections import Counter


def solve() -> None:
    counter: Counter[str] = Counter()

    ans = []

    lines = sys.stdin.readlines()
    for line in lines:
        first, last = line.split()

        counter[first] += 1

        ans.append((last, first))

    ans.sort()

    for last, first in ans:
        if counter[first] > 1:
            print(f"{first} {last}")
        else:
            print(first)


def main() -> None:
    solve()


if __name__ == "__main__":
    main()
