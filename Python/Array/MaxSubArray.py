# LeetCode 13
# 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
# 子数组 是数组中的一个连续部分。

from typing import List

class Solution:
    # 前缀和，借鉴 和为k的子数组个数，将问题转换成：以第i个数为结尾的数组的最大和为 sum(nums[:i] - min)，
    # 其中min为nums数组中从0到任意k<i连续子数组和最小负值
    def maxSubArray(self, nums: List[int]) -> int:
        maxsub = -10**4
        minsub = 0
        sums = 0
        for i, x in enumerate(nums):
            sums += x
            maxsub = max(maxsub, sums - minsub)
            minsub = min(minsub, sums)
        return maxsub

    # 动态规划，官方题解的更直接，将问题转换成：f(i)为以第i个数为结尾的连续子数组数组的最大和，则f(i)=max(f(i-1)+nums[i], nums[i])
    # (f(i-1)可能是负的)
    def maxSubArray(self, nums: List[int]) -> int:
        max_prev = nums[0]
        max_ans = nums[0]
        for i in range(1, len(nums)):
            max_prev = max(max_prev + nums[i], nums[i])
            max_ans = max(max_ans, max_prev)
        return max_ans