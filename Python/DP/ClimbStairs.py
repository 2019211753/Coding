# LeetCode 81
# 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
# 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    # f(x) = f(x-1) + f(x-2)
    def climbStairs(self, n: int) -> int:
        f0 = 1
        f1 = 1

        for _ in range(1, n):
            f = f0 + f1
            f0 = f1
            f1 = f
        return f1