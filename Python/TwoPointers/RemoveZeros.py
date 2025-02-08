# LeetCode 04
# 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
# 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
from typing import List

class Solution:
    # no efficient
    # def moveZeroes(self, nums: List[int]) -> None:
    #     """
    #     Do not return anything, modify nums in-place instead.
    #     """
    #     i = j = len(nums) - 1 # end of measure interval; 0 left open interval
    #     while i >= 0:
    #         while i >= 0 and nums[i] != 0:
    #             i = i - 1
    #         k = i # first zero
    #         while i >= 1 and nums[i-1] == 0:
    #             i = i - 1 # last zero
    #         zeros = k - i + 1
    #         nums[i: i+j-k] = nums[k+1: j+1]
    #         nums[j-k+i: j+1] = [0] * (k - i + 1)
    #         i = i - 1
    #         j = j - k + i - 1
    #         print(f'i:{i}, j:{j}, k:{k}')

    # efficient o(n)
    def moveZeroes(self, nums: List[int]) -> None:
        n = len(nums)
        left = right = 0
        while right < n:
            if nums[right] != 0:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            right += 1
