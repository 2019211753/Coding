# LeetCode 93
# 给你一个字符串 s，找到 s 中最长的 回文 子串。

from typing import List

class Solution:
    # 超时了，但是思路方向是对的，还是dp递推公式没想好，空间复杂度o(n^3)
    # def longestPalindrome(self, s: str) -> str:
    #     n = len(s)
    #     dp = [[1] for _ in range(n)]
    #     result = s[0]
    #     for i in range(1, n):
    #         for j in range(i - 1, -1, -1):
    #             if s[i] == s[j]:
    #                 if i - j == 1:
    #                     dp[i].append(2)
    #                 else:
    #                     for l in dp[i - 1]:
    #                         if i - j - 1 == l:
    #                             dp[i].append(i - j + 1)
    #                             break
    #
    #             if len(result) < dp[i][-1]:
    #                 result = s[i - dp[i][-1] + 1: i + 1]
    #     return result

    # 状态转移方程：p(i, j) = p(i + 1, j - 1) & (Si == Sj), p(i, i + 1) = Si == Si+1
    # 时间复杂度o(n^2)，空间复杂度o(n^2)
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 0:
            return ""

        # dp[i][j] 表示 s[i:j+1] 是否是回文
        dp = [[False] * n for _ in range(n)]
        start = 0  # 最长回文子串的起始位置
        max_len = 1  # 最长回文子串的长度，最小为1，因为单个字符也是回文

        # 所有长度为1的子串都是回文
        for i in range(n):
            dp[i][i] = True

        # 检查长度为2的子串是否是回文
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                start = i
                max_len = 2

        # 检查长度大于2的子串是否是回文
        for length in range(3, n + 1):  # length是子串的长度
            for i in range(n - length + 1):
                j = i + length - 1  # 子串的终止位置
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    if length > max_len:
                        max_len = length
                        start = i

        return s[start:start + max_len]

    # 中心扩展法 时间复杂度o(n^2)，空间复杂度o(1)
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        def expand_from_center(left: int, right: int) -> str:
            # 向两边扩展，直到不再是回文
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # 返回扩展后的回文子串
            return s[left + 1:right]

        longest = ""
        for i in range(len(s)):
            # 扩展出奇数长度回文子串 (只有一个字符作为中心)
            odd_palindrome = expand_from_center(i, i)
            # 扩展出偶数长度回文子串 (两个相同字符作为中心)
            even_palindrome = expand_from_center(i, i + 1)

            # 更新最长回文子串
            if len(odd_palindrome) > len(longest):
                longest = odd_palindrome
            if len(even_palindrome) > len(longest):
                longest = even_palindrome

        return longest

solution = Solution()
solution.longestPalindrome("aaaa")