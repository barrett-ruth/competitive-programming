class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        complements: dict[int, int] = {}

        for i, num in enumerate(nums):
            complement = complements.get(num)

            if complement is not None:
                return [complement, i]
            else:
                complements[target - num] = i

        return []
