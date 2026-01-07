n, a = list(map(int, input().split()))

es = list(map(int, input().split()))

es.sort()

won = 0

for e in es:
    if a <= e:
        break
    won += 1
    a -= (e + 1)

print(won)
