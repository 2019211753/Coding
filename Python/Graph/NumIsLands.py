# LeetCode 51
# 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
# 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
# 此外，你可以假设该网格的四条边均被水包围。

from typing import List, Optional
from collections import deque, defaultdict
import numpy

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n:
                return
            if flag[i][j]:
                return
            if grid[i][j] == '0':
                return
            if grid[i][j] == '1':
                flag[i][j] = 1
            dfs(i - 1, j)
            dfs(i + 1, j)
            dfs(i, j - 1)
            dfs(i, j + 1)

        def find_ones(grid: List[List[str]]):
            indices = []
            for i, row in enumerate(grid):
                for j, value in enumerate(row):
                    if value == '1':
                        indices.append((i, j))
            return indices

        m = len(grid)
        n = len(grid[0])
        flag = [[0] * n for _ in range(m)]
        index = find_ones(grid)
        result = 0
        for i, j in index:
            if not flag[i][j]:
                dfs(i, j)
                result += 1
        return result

solution = Solution()
solution.numIslands([["1","1","1"],["0","1","0"],["1","1","1"]]

)
