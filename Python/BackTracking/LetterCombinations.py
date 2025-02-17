# LeetCode 57
# 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
# 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

from typing import List, Optional
from collections import deque, defaultdict
import numpy


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def combine(k, result):
            if k  == n:
                if n != 0:
                    results.append(''.join(result[:]))
                return
            for letter in letters[digits[k] - 2]:
                result.append(letter)
                combine(k + 1, result)
                result.pop()
        letters = [['a', 'b', 'c'], ['d', 'e', 'f'], ['g', 'h', 'i'], ['j', 'k', 'l'],
                   ['m', 'n', 'o'], ['p', 'q', 'r', 's'], ['t', 'u', 'v'], ['w', 'x', 'y', 'z']]

        digits = [int(digit) for digit in digits]
        n = len(digits)
        results = []
        combine(0, [])
        return results

