s = input()
n = len(s)
last_occurrence = {}
total = 0

for right in range(n):
    char = s[right]
    left = last_occurrence.get(char, -1) + 1

    unique_chars = set()
    for l in range(right - 1, left - 1, -1):
        if s[l] not in unique_chars:
            total += 1
        unique_chars.add(s[l])
    last_occurrence[char] = right

print(total)
