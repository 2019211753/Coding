class Solution:
    def twoSum(self, nums: list, target: int) -> list:
        dict = {} # python dict×Ô´øsearchºÍinsert
        for key, value in enumerate(nums):
            complement = target - value
            if complement in dict:
                return [key, dict[complement]]
            else:
                dict[value] = key