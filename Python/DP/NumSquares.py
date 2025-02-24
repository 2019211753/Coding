# LeetCode 84
# 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
# 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    def numSquares(self, n: int) -> int:
        dp = [float('inf')] * (n + 1)  # 初始化一个大数组，dp[i] 表示 i 的最小完全平方数个数
        dp[0] = 0  # 和为0时，完全平方数个数为0

        for i in range(1, n + 1):
            # 计算所有小于等于 i 的完全平方数
            j = 1
            while j * j <= i:
                dp[i] = min(dp[i], dp[i - j * j] + 1)
                j += 1

        return dp[n]



