# LeetCode 89
# 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    # 错误的，当我们在处理 num = 1 时，dp[1] 会变为 True。
    # 如果接下来处理 num = 2，我们希望 dp[3] = dp[3] or dp[3-2]。
    # 由于我们是正序遍历，dp[1] 已经在当前循环中被更新为 True，因此 dp[3] 会被错误地标记为 True。
    # 这种问题的本质是：正序遍历会在同一轮循环中“提前”使用了当前元素，从而导致状态污染。
    # def canPartition(self, nums: List[int]) -> bool:
    #     n = len(nums)
    #     sums = sum(nums)
    #     if sums % 2 == 1:
    #         return False
    #     s = sums // 2
    #     dp = [False] * (s + 1)
    #     dp[0] = True
    #     for i in range(1, s + 1):
    #         for j in range(n):
    #             if nums[j] <= i and dp[i - nums[j]]:
    #                 dp[i] = True
    #     return dp[s]

    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)
        # 如果总和为奇数，无法分割成两个相等的子集
        if total_sum % 2 == 1:
            return False

        target = total_sum // 2
        dp = [False] * (target + 1)
        dp[0] = True  # 和为0总是可以通过不选择任何数字得到

        # 遍历每个数字，如果遍历dp，内循环遍历数字的话，[1, 2, 5]时，dp[3]为True
        # 逆序遍历，只考虑当前数字num到target之间的dp[i]，保证每次计算 dp[j] 时，都使用的是当前数字加入前的状态，确保每个数字只被用一次。
        # 避免出现 num = 2时，4-2=2的情况。
        for num in nums:
            for curr_sum in range(target, num - 1, -1):
                dp[curr_sum] = dp[curr_sum] or dp[curr_sum - num]

        return dp[target]

solution = Solution()
solution.canPartition([1,2,3])
