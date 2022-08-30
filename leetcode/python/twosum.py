class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        complements: dict[int, int] = {}

        for i, num in enumerate(nums):
            complement = target - num

            if complement in complements:
                return [complements[complement], i]
            else:
                complements[num] = i

        return []
