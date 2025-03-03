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
        # tails 用来记录当前递增子序列的最小尾部元素
        tails = []

        for num in nums:
            # 手动实现二分查找
            left, right = 0, len(tails)
            while left < right:
                mid = (left + right) // 2
                if tails[mid] < num:
                    left = mid + 1
                else:
                    right = mid
            # left 位置即为要插入或更新的位置
            if left == len(tails):
                tails.append(num)  # 如果 num 大于所有元素，添加到 tails 尾部
            else:
                tails[left] = num  # 否则覆盖该位置

        return len(tails)

solution = Solution()
solution.lengthOfLIS([1,3,6,7,9,4,10,5,6])
