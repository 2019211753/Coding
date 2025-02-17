# LeetCode 60
# 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
# 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

from typing import List, Optional
from collections import deque, defaultdict
import numpy

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def help(k, i, j):
            if i < 0 or i > m - 1 or j < 0 or j > n - 1:
                return False
            if flag[i][j] == 1:
                return False
            if k == l - 1 and board[i][j] == word[k]:
                return True
            if board[i][j] == word[k]: # 没搜索到不要置1 可能绕一圈还能回来
                flag[i][j] = 1 # 搜索到且搜索中中置1
                up = help(k + 1, i, j - 1)
                left = help(k + 1, i - 1, j)
                right = help(k + 1, i + 1, j)
                down = help(k + 1, i, j + 1)
                flag[i][j] = 0 # 搜索完置0
                return up or left or right or down
            else:
                return False

        m = len(board)
        n = len(board[0])
        l = len(word)
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    flag = [[0] * n for _ in range(m)] # 每次循环都重新立flag
                    success = help(0, i, j)
                    if success:
                        return success
        return False