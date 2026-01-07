from math import gcd

a, b = map(int, input().split())
max_num = float('-inf')

transcript = input().split()

fizzs = []
buzzs = []

for i, token in enumerate(transcript):
    num = a + i

    max_num = max(max_num, num)

    if token.startswith("Fizz") or token.endswith("Fizz"):
        fizzs.append(num)
    if token.startswith("Buzz") or token.endswith("Buzz"):
        buzzs.append(num)


def gcf(nums: list[int]) -> int:
    if not nums:
        return ''
    if len(nums) == 1:
        return nums[0]

    x, y = nums[0], nums[1]
    ans = gcd(x, y)

    for i in range(2, len(nums)):
        ans = gcd(ans, nums[i])

    return ans


a, b = gcf(fizzs), gcf(buzzs)

if a == '':
    a = max_num + 1
if b == '':
    b = max_num + 1

print(a, b)
