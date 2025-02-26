# LeetCode 92
# 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
# 说明：每次只能向下或者向右移动一步。

from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = grid[0]
        for k in range(1, n):
            f[k] += f[k - 1]
        for i in range(1, m):
            for j in range(n):
                if j == 0:
                    f[j] = f[j] + grid[i][j]
                else:
                    if f[j] > f[j - 1]:
                        f[j] = f[j - 1] + grid[i][j]
                    else:
                        f[j] = f[j] + grid[i][j]
        return f[n - 1]

solution = Solution()
solution.minPathSum([[1,3,1],[1,5,1],[4,2,1]])