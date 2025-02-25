# LeetCode 74
# 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
# 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
# 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

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
