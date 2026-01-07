N = int(input())

matrix: list[list[int]] = []
for i in range(N):
    matrix[i] = list(map(int, list(input())))

row_map = [0] * N
col_map = [0] * N

ones_above = 0
ones_above_row = [0] * N

for i, row in enumerate(matrix):
    ones_above_row[i] = ones_above
    total = 0
    for cell in row:
        total += cell
    row_map[i] = total
    ones_above += row_map[i]

ones_left = 0
ones_left_col = [0] * N

for col in range(N):
    total = 0
    for row in range(N):
        total += matrix[row][col]
    ones_left_col[col] = ones_left
    col_map[col] = total
    ones_left += col_map[col]

found_valid_row = False
for i in range(N):
    flips_remain = row_map[i]
    total_ones = ones_above_row[-1] - row_map[i] + row_map[-1]
    if total_ones <= flips_remain:
        row_flag = True
        break

found_valid_col = False
for i in range(N):
    flips_remain = col_map[i]
    total_ones = ones_left_col[-1] - col_map[i] + col_map[-1]
    if total_ones <= flips_remain:
        found_valid_col = True
        break

if found_valid_row:
    if found_valid_col:
        print("+")
    else:
        print("-")
else:
    print("-")
