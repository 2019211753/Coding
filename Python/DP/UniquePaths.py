# LeetCode 91
# 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
# 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
# 问总共有多少条不同的路径？

from typing import List

class Solution:
    # def uniquePaths(self, m: int, n: int) -> int:
    #     dp = [[0] * n for _ in range(m)]
    #     dp[0][0] = 1
    #     for i in range(m):
    #         for j in range(n):
    #             if j > 0:
    #                 dp[i][j] += dp[i][j - 1]
    #             if i > 0:
    #                 dp[i][j] += dp[i - 1][j]
    #     return dp[m - 1][n - 1]

    # 由于当前状态只和上一行和当前行有关，所以可以优化
    def uniquePaths(self, m: int, n: int) -> int:
        f = [1] * n
        for i in range(1, m): # 第一行和第一列的都是1
            for j in range(1, n):
                f[j] += f[j - 1] # 计算前的f[j]为上一行第 j 列的dp，f[j - 1]为当前行左边的dp，加和即可
        return f[n - 1]

solution = Solution()
solution.uniquePaths(3, 3)
