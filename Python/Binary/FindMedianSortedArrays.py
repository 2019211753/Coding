# LeetCode 68
# 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
# 算法的时间复杂度应该为 O(log (m+n)) 。

from typing import List
import heapq
import collections


class Solution:
    # 二分查找 o(log(min(m, n)))
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 保证 nums1 的长度不大于nums2，在nums1上做二分效率更高
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m, n = len(nums1), len(nums2)

        low, high = 0, m
        halfLen = (m + n + 1) // 2  # 保证左边有更多或相等的元素 7: 4, 6: 3

        while low <= high:
            i = (low + high) // 2 # 分别代表分割的右侧第一个元素
            j = halfLen - i

            # 如果 nums2的左侧最大值大于nums1的右侧最小值，说明nums1还有值能插入中位数数组，增加i
            # 不需要考虑 j = 0，因为m < n
            if i < m and nums2[j - 1] > nums1[i]:
                low = i + 1
            # 反之亦然，减小i
            elif i > 0 and nums1[i - 1] > nums2[j]:
                high = i - 1
            else:
                # 找到了合适的分割点
                if i == 0:
                    maxLeft = nums2[j - 1]
                elif j == 0:
                    maxLeft = nums1[i - 1]
                else:
                    maxLeft = max(nums1[i - 1], nums2[j - 1])

                # 如果总长度为奇数，直接返回左侧最大值
                if (m + n) % 2 == 1:
                    return maxLeft

                # 计算右侧最小值
                if i == m:
                    minRight = nums2[j]
                elif j == n:
                    minRight = nums1[i]
                else:
                    minRight = min(nums1[i], nums2[j])

                return (maxLeft + minRight) / 2.0

