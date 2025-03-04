# LeetCode 19
# 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n, m = len(matrix), len(matrix[0])
        s = min(n, m) // 2
        result = []
        for i in range(s):
            for j in range(i, m - i):
                result.append(matrix[i][j])
            for j in range(i + 1, n - i):
                result.append(matrix[j][m - i - 1])
            for j in range(m - i - 2, i - 1, -1):
                result.append(matrix[n - i - 1][j])
            for j in range(n - i - 2, i, -1):
                result.append(matrix[j][i])
        print(result)
        if m >= n > 2 * s:
            result.extend(matrix[s][s: m - s])
        elif n > m > 2 * s:
            result.extend([matrix[k][s] for k in range(s, n - s)])
        return result

