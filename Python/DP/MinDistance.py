# LeetCode 95
# 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
# 你可以对一个单词进行如下三种操作：插入一个字符；删除一个字符；替换一个字符
from functools import cache


class Solution:
    def minDistance(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        # @cache可以将复杂度大幅降低，如斐波那契数列用递归是 o(2^n)，但用了@cache避免重复计算，时间复杂度降低到o(n)
        @cache
        def dfs(i, j):
            if i < 0: return j + 1
            if j < 0: return i + 1
            if s[i] == t[j]: return dfs(i - 1, j - 1)
            return min(dfs(i - 1, j), dfs(i, j - 1), dfs(i - 1, j - 1)) + 1 # 分别是删除、插入和替换操作
        return dfs(n - 1, m - 1)

    def minDistance(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        dp[0][:] = range(n + 1)
        for i, x in enumerate(t):
            dp[i + 1][0] = i + 1
            for j, y in enumerate(s):
                if x == y:
                    dp[i + 1][j + 1] = dp[i][j]
                else:
                    dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j], dp[i][j]) + 1
        return dp[m][n]

