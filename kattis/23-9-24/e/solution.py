ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."

character_to_index = {c: i for i, c in enumerate(ALPHABET)}
index_to_character = {i: c for i, c in enumerate(ALPHABET)}

while line := input():
    split = line.split()

    if len(split) == 1:
        break

    k, string = int(split[0]), split[1]

    backwards = string[::-1]

    ans: list[str] = []

    for letter in backwards:
        index = character_to_index[letter]
        ans.append(index_to_character[(index + k) % len(ALPHABET)])

    print("".join(ans))
