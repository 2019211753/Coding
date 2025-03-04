# LeetCode 18
# 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
# 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n, m = len(matrix), len(matrix[0])
        flag = False
        for i in range(m):
            if matrix[0][i] == 0:
                flag = True
        for i in range(1, n):
            for j in range(m):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, n):
            if matrix[i][0] == 0:
                matrix[i][:] = [0] * m
        for j in range(m):
            if matrix[0][j] == 0:
                for row in matrix:
                    row[j] = 0
        if matrix[0][0] == 0:
            for row in matrix:
                row[0] = 0
        if flag:
            matrix[0][:] = [0] * m


solution = Solution()
solution.setZeroes([[0,1,2,0],[3,4,5,2],[1,3,1,5]])
