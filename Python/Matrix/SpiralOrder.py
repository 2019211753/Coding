# LeetCode 19
# 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        result = []
        s = min(m // 2, n // 2)
        for i in range(s):
            result.extend(matrix[i][i: n - i])  # 从左到右
            result.extend([matrix[j][n - i - 1] for j in range(i + 1, m - i)])  # 从上到下
            result.extend(matrix[m - i - 1][n - i - 2: i - 1 if i > 0 else None: -1])  # 从右到左
            result.extend([matrix[j][i] for j in range(m - i - 2, i, -1)])  # 从下到上
        if 2 * s < m and 2 * s < n:
            if m <= n:
                result.extend(matrix[s][s: n - s]) # 从左到右
            else:
                result.extend([matrix[j][n - s - 1] for j in range(s, m - s)])  # 从上到下
        return result
