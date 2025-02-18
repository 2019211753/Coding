# LeetCode 62
# 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
# n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
# 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
# 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位

from typing import List
import heapq
import collections

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def hasSpace(n, k):
            space = [x for x in range(n)]
            for i, j in result:
                if j in space:
                    space.remove(j)
                if j + k - i < n and j + k - i in space:
                    space.remove(j + k - i)
                if j - k + i < n and j - k + i in space:
                    space.remove(j - k + i)
            return space

        def help(k):
            if k == n:
                results.append(result[:])
                return
            space = hasSpace(n, k)
            if len(space) == 0:
                return
            for j in space:
                result.append([k, j])
                help(k + 1)
                result.pop()

        results, result = [], []
        help(0)
        solved = []
        for result in results:
            solve = []
            for _, j in result:
                string = '.' * j + 'Q' + '.' * (n - j - 1)
                solve.append(string)
            solved.append(solve)

        return solved

solution = Solution()
solution.solveNQueens(4)