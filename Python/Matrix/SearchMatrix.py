# LeetCode 21
# 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
# 每行的元素从左到右升序排列。
# 每列的元素从上到下升序排列。

from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix) - 1, len(matrix[0]) - 1
        h_m, h_n = m, n
        l_m, l_n = 0, 0
        while l_m <= h_m and l_n <= h_n:
            m_m, m_n = (h_m + l_m) // 2, (h_n + l_n) // 2
            if matrix[m_m][m_n] > target:
                h_m, h_n = m_m - 1, m_n - 1
            elif matrix[m_m][m_n] < target:
                l_m, l_n = m_m + 1, m_n + 1
            else:
                return True
        if l_m <= m and l_n <= n:
            for i in range(l_m + 1):
                if matrix[i][l_n] == target:
                    return True
            for j in range(l_n + 1):
                if matrix[l_m][j] == target:
                    return True
            return False
        if l_m <= m:
            for i in range(l_m, m + 1):
                if matrix[i][l_n - 1] == target:
                    return True
            return False
        if l_n <= n:
            for i in range(l_n, n + 1):
                if matrix[l_m - 1][i] == target:
                    return True
            return False
        return False

solution = Solution()
solution.searchMatrix([[1,2,3,4,5]], 2)