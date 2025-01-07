class Solution:
    def twoSum(self, nums: list, target: int) -> list:
        dict = {} # python dict�Դ�search��insert
        for key, value in enumerate(nums):
            complement = target - value
            if complement in dict:
                return [key, dict[complement]]
            else:
                dict[value] = key