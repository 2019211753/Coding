# LeetCode 66
# 整数数组 nums 按升序排列，数组中的值 互不相同 。
# 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
# 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
# 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
# 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
# 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

from typing import List
import heapq
import collections

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def help1():
            i, j = 0, n - 1
            while i <= j:
                mid = (i + j) // 2
                if nums[mid] >= nums[0]: # 要大于等于，不然mid=0时有问题
                    i = mid + 1
                else:
                    j = mid - 1
            return i

        def help2(i, j, target):
            while i <= j:
                mid = (i + j) // 2
                if nums[mid] < target:
                    i = mid + 1
                elif nums[mid] > target:
                    j = mid - 1
                else:
                    return mid
            return -1

        n = len(nums)
        k = help1()
        left = help2(0, k - 1, target)
        right = help2(k, n - 1, target)
        if left == -1 and right == -1:
            return -1
        else:
            return left if right == -1 else right

solution = Solution()
solution.search([4,5,6,7,0,1,2], 0)