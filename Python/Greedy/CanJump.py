# LeetCode 78
# 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
# 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    # 递归 超时
    def canJump(self, nums: List[int]) -> bool:
        def help(k):
            if k == n - 1:
                nonlocal flag
                flag = True
                return
            if k >= n or nums[k] == 0:
                return
            for i in range(1, nums[k] + 1):
                help(k + i)

        n = len(nums)
        flag = False
        help(0)
        return flag

    # 贪心，只要当前点之前的所有跳跃距离加一起超过当前的，则必然可以到达当前结点
    def canJump(self, nums: List[int]) -> bool:
        n, rightmost = len(nums), 0
        for i in range(n):
            if i <= rightmost:
                rightmost = max(rightmost, i + nums[i])
                if rightmost >= n - 1:
                    return True
            else:
                return False
        return False

solution =Solution()
print(solution.canJump([2, 3, 1, 1, 4]))