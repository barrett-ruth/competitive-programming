"""
Backtracking Framework
- Set of choices
- Limited by constraints
- To reach a goal

1. Understand
- Board of W/B, can capture; looking for max consecutive sequence of captures using same piece
- Capture in any direction "skipping over"; land on open square

Similar Problems: N Queens

Set of candidates (W pieces) limited in moves (capturing B pieces) to reach max # captures (i.e. capturing moves)
2. Develop

- Given board state, w/ W candidates
- Consider every candidate as the piece yielding correct answer
- For every candidate, consider every capturing move they can make
    - For each move:
        - Make the move, and recursively find max # captures using this piece after this capture
        - update/restore state on failure
    - Update max if new max found

consider after: caching/optimization

backtracking function: def max_captures(board, w) -> int:


3. Carry Out
4. Revise

At any particular position,
"""

BOARD_SIZE = 10


def parse_board() -> tuple[list[list[str]], list[tuple[int, int]]]:
    board = []
    candidates: list[tuple[int, int]] = []

    input()

    for r in range(BOARD_SIZE):
        board.append(list(input()))

        candidates.extend((r, c) for c, cell in enumerate(board[-1]) if cell == "W")

    return board, candidates


def valid(board, r, c):
    return 0 <= r < len(board) and 0 <= c < len(board[0])


# all capturing moves white piece can make
def capturing_moves(board, r, c) -> list[tuple[int, int]]:
    if not valid(board, r, c):
        return []

    moves = []

    for dr, dc in [(-1, -1), (1, 1), (-1, 1), (1, -1)]:
        if (
            valid(board, r + 2 * dr, c + 2 * dc)
            and board[r + dr][c + dc] == "B"
            and board[r + 2 * dr][c + 2 * dc] not in "BW"
        ):
            moves.append((dr, dc))

    return moves


def max_candidate_captures(board, r, c) -> int:
    max_captures = 0

    for dr, dc in capturing_moves(board, r, c):
        # place
        board[r][c] = "."
        board[r + dr][c + dc] = "."
        board[r + dr * 2][c + dc * 2] = "W"

        ans = max_candidate_captures(board, r + dr * 2, c + dc * 2)
        max_captures = max(max_captures, 1 + ans)

        # unplace
        board[r + dr * 2][c + dc * 2] = "."
        board[r][c] = "W"
        board[r + dr][c + dc] = "B"

    return max_captures


def max_captures(board, candidates: list[tuple[int, int]]) -> int:
    max_captures = 0

    for r, c in candidates:
        max_captures = max(max_captures, max_candidate_captures(board, r, c))

    return max_captures


def solve() -> None:
    T = int(input())

    while T:
        board, candidates = parse_board()
        print(max_captures(board, candidates))
        T -= 1


def main() -> None:
    solve()


if __name__ == "__main__":
    main()
