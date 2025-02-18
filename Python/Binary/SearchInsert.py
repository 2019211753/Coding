# LeetCode 63
# 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
# 请必须使用时间复杂度为 O(log n) 的算法。

from typing import List
import heapq
import collections

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        i, j = 0, n - 1
        while i <= j:
            mid = (i + j) // 2
            if nums[mid] < target:
                i = mid + 1
            elif nums[mid] > target:
                j = mid - 1
            else:
                return mid
        return i # 返回值总大于等于 i - 1
