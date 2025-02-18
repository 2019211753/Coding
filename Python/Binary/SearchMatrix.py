# LeetCode 64
# 给你一个满足下述两条属性的 m x n 整数矩阵：
# 每行中的整数从左到右按非严格递增顺序排列。
# 每行的第一个整数大于前一行的最后一个整数。
# 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

from typing import List
import heapq
import collections

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def searchInsert(matrix, len) -> int:
            i, j = 0, len - 1
            while i <= j:
                mid = (i + j) // 2
                if matrix[mid] < target:
                    i = mid + 1
                elif matrix[mid] > target:
                    j = mid - 1
                else:
                    return mid
            return i
        n = len(matrix)
        m = len(matrix[0])
        max_lines = [matrix[i][-1] for i in range(n)]
        l = searchInsert(max_lines, n)
        if l >= n:
            return False
        if max_lines[l] == target:
            return True
        k = searchInsert(matrix[l][:], m)
        if k >= m:
            return False
        if matrix[l][k] == target:
            return True
        return False