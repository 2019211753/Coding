# LeetCode 87
# 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
# 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    # o(n^2)
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        max_len = 1
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                   dp[i] = max(dp[i], dp[j] + 1)
            max_len = max(max_len, dp[i])
        return max_len

    # 贪心+二分 o(nlogn)
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        max_len = 1
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                   dp[i] = max(dp[i], dp[j] + 1)
            max_len = max(max_len, dp[i])
        return max_len

solution = Solution()
solution.lengthOfLIS([1,3,6,7,9,4,10,5,6])
