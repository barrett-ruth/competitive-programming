def solve(equation: str) -> None:
    stack = []
    paren_pairs = []

    for i, token in enumerate(equation):
        if token == "(":
            stack.append([i, None])
        elif token == ")":
            l, r = stack.pop()
            r = i
            paren_pairs.append((l, r))

    P = [[]]

    for paren_pair in paren_pairs:
        P.extend([[paren_pair] + p for p in P])

    def format(permutation):
        output = list(equation)

        for l, r in permutation:
            output[l] = None
            output[r] = None

        return "".join(filter(lambda token: token, output))

    seen = set()
    ans = []
    for permutation in P[1:]:
        output = format(permutation)
        if output not in seen:
            seen.add(output)
            ans.append(output)

    for x in sorted(ans):
        print(x)


def main() -> None:
    equation = input()

    solve(equation)


if __name__ == "__main__":
    main()
