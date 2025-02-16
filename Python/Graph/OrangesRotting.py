# LeetCode 52
# 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
# 值 0 代表空单元格；
# 值 1 代表新鲜橘子；
# 值 2 代表腐烂的橘子。
# 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
# 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

from typing import List, Optional
from collections import deque, defaultdict
import numpy


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        flag = [[0] * m for _ in range(n)]
        t_max = 0
        queue = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    queue.append((0, i, j))
                    flag[i][j] = 1
        while queue:
            t, i, j = queue.popleft()
            if i - 1 >= 0 and grid[i - 1][j] == 1 and flag[i - 1][j] == 0:
                queue.append((t + 1, i - 1, j))
                flag[i - 1][j] = 1
                grid[i - 1][j] = 2
            if j - 1 >= 0 and grid[i][j - 1] == 1 and flag[i][j - 1] == 0:
                queue.append((t + 1, i, j - 1))
                flag[i][j - 1] = 1
                grid[i][j - 1] = 2
            if j + 1 < m and grid[i][j + 1] == 1 and flag[i][j + 1] == 0:
                queue.append((t + 1, i, j + 1))
                flag[i][j + 1] = 1
                grid[i][j + 1] = 2
            if i + 1 < n and grid[i + 1][j] == 1 and flag[i + 1][j] == 0:
                queue.append((t + 1, i + 1, j))
                flag[i + 1][j] = 1
                grid[i + 1][j] = 2

            t_max = max(t_max, t)
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return -1

        return t_max

