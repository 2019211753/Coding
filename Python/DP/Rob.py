# LeetCode 83
# 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
# 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    # 递归会多次考虑同一个问题，时间复杂度为o(2^n)。动态规划为o(n)
    def rob(self, nums: List[int]) -> int:
        def help(i, sums):
            nonlocal result
            if sums > result:
                result = sums
            if i > n - 1:
                return
            help(i + 2, sums + nums[i])
            help(i + 1, sums)

        n = len(nums)
        result = 0
        help(0, 0)
        return result

    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        elif len(nums) == 1:
            return nums[0]

        prev2 = nums[0]
        prev1 = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            current = max(prev1, prev2 + nums[i])
            prev2 = prev1
            prev1 = current

        return prev1