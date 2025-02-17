# LeetCode 61
# 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

from typing import List, Optional
from collections import deque, defaultdict
import numpy

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(s):
            for i in range(len(s) // 2):
                if s[i] != s[len(s) - i - 1]:
                    return False
            return True

        def help(i):
            if i == n:
                results.append(result[:])
                return

            for k in range(i + 1, n + 1):
                left_substr = s[i:k]
                if isPalindrome(left_substr):
                    result.append(left_substr)
                    help(k)
                    result.pop()
        n = len(s)
        results, result = [], []
        help(0)
        return results

solution = Solution()
solution.partition("cbbbcc")

