# LeetCode 73
# 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
# 求在该柱状图中，能够勾勒出来的矩形的最大面积。

from typing import List
import heapq
import collections

class Solution:
    # 暴力枚举 以索引 i 为观察对象，看 i 之前的 i 个子区间最小值*区间长度 o(n^2)
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        max_area = 0
        for i in range(n):
            min_heights = [0] * n
            for j in range(i, n):
                if i == j:
                    min_heights[j] = heights[i]
                else:
                    min_heights[j] = min(heights[j], min_heights[j - 1])
                max_area = max(max_area, min_heights[j] * (j - i + 1))
        return max_area

    # 单调栈 o(n)
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        max_area = 0
        stack = []
        left = [-1] * n
        right = [n] * n
        for i in range(n - 1, -1, -1):
            while stack and heights[i] < heights[stack[-1]]:
                left[stack[-1]] = i
                stack.pop()
            stack.append(i)
        stack = []
        for i in range(n):
            while stack and heights[i] < heights[stack[-1]]:
                right[stack[-1]] = i
                stack.pop()
            stack.append(i)
        for i in range(n):
            max_area = max(heights[i] * (right[i] - left[i] - 1), max_area)
        return max_area

solution = Solution()
solution.largestRectangleArea([2, 1,5 ,6, 2 ,3])

