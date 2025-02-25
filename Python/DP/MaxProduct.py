# LeetCode 88
# 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
# 测试用例的答案是一个 32-位 整数。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0

        # 初始化最大值、最小值和结果，避免用长度为n的dp数组
        max_product = nums[0]
        curr_max, curr_min = nums[0], nums[0]

        for i in range(1, len(nums)):
            # 如果当前数为负数，则交换最大值和最小值
            # 因为乘以负数会使最大值变为最小值，最小值变为最大值
            if nums[i] < 0:
                curr_max, curr_min = curr_min, curr_max

            # 更新当前位置的最大值和最小值
            curr_max = max(nums[i], curr_max * nums[i])
            curr_min = min(nums[i], curr_min * nums[i])

            # 更新全局最大乘积
            max_product = max(max_product, curr_max)

        return max_product

