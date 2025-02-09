# LeetCode 15
# 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n  # 处理 k 大于 n 的情况，避免不必要的循环

        # 翻转整个数组
        nums.reverse()

        # 翻转前 k 个元素
        nums[:k] = reversed(nums[:k])

        # 翻转剩余的元素
        nums[k:] = reversed(nums[k:])
