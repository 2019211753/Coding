# LeetCode 74
# 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
# 求在该柱状图中，能够勾勒出来的矩形的最大面积。

from typing import List
import heapq
import collections

class Solution:
    # 直接选择排序，超时
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        for i in range(k):
            max = nums[i]
            index = i
            for j in range(i + 1, n):
                if nums[j] > max:
                    max, index = nums[j], j
            nums[i], nums[index] = nums[index], nums[i]
        return nums[k - 1]

    # 快排
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quickselect(nums, l, r, k):
            if l == r:
                return nums[l]
            import random
            pivot = random.randint(l, r)
            pivot_val = nums[pivot]
            nums[l], nums[pivot] = nums[pivot], nums[l]
            low, high = l, r
            while low < high:
                while low < high and nums[high] > pivot_val:
                    high = high - 1
                if low < high:
                    nums[low] = nums[high]
                    low = low + 1
                while low < high and nums[low] < pivot_val:
                    low = low + 1
                if low < high:
                    nums[high] = nums[low]
                    high = high - 1
            nums[low] = pivot_val
            if low == k:
                return nums[low]
            elif low < k:
                return quickselect(nums, low + 1, r, k)
            else:
                return quickselect(nums, l, low - 1, k)

        n = len(nums)
        # 第 k 大元素在排序后是第 n-k 小的元素
        return quickselect(nums, 0, n - 1, n - k)

solution = Solution()
solution.findKthLargest([3, 2, 1, 5, 6, 4], 2)
