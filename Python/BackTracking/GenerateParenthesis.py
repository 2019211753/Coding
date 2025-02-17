# LeetCode 59
# 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

from typing import List, Optional
from collections import deque, defaultdict
import numpy

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def help(p, q):
            if p == n and q == n:
                results.append(''.join(result[:]))
                return
            if p <= n - 1:
                result.append('(')
                help(p + 1, q)
                result.pop()
            if q < p and q <= n - 1:
                result.append(')')
                help(p, q + 1)
                result.pop()

        result, results = [], []
        help(0, 0)
        return results

solution = Solution()
print(solution.generateParenthesis(3))