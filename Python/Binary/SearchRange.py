# LeetCode 65; AcWing 789;
# 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
# 如果数组中不存在目标值 target，返回 [-1, -1]。
# 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

from typing import List
import heapq
import collections


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        if length == 0:
            return [-1, -1]
        i = 0
        j = length - 1
        while i <= j:
            mid = int((i + j) / 2)
            if nums[mid] > target:
                j = mid - 1
            elif nums[mid] < target:
                i = mid + 1
            else:
                break
        if nums[mid] == target:
            m = mid
            n = mid
            while m >= 0 and nums[m] == target:
                m = m - 1
            m = m + 1
            while n <= length - 1 and nums[n] == target:
                n = n + 1
            n = n - 1
            return [m, n]
        else:
            return [-1, -1]

