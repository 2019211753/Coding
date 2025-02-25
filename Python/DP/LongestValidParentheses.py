# LeetCode 90
# 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

from typing import List

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0

        # dp[i] 表示以 s[i] 结尾的最长有效括号子串长度
        dp = [0] * n
        max_length = 0

        for i in range(1, n):
            if s[i] == ')':
                # 情况 1：如果前一个字符是 '('，例如 "..."
                if s[i - 1] == '(':
                    # 如果 i>=2，则加上 dp[i-2]，否则为 0
                    dp[i] = (dp[i - 2] if i >= 2 else 0) + 2
                # 情况 2：如果前一个字符也是 ')'，例如 "...))"
                else:
                    # i - dp[i-1] - 1 是当前有效子串之前的一个位置
                    j = i - dp[i - 1] - 1
                    if j >= 0 and s[j] == '(':
                        # dp[i-1] 表示以 s[i-1] 结尾的有效子串长度，加上匹配的 '(' 和 ')' 的2个字符，
                        # j-1 处可能存在有效子串，则加上 dp[j-1]
                        # 如 (()(()) 遍历到最后一个)时，前面的dp为 002002，则先判断对应的括号是否有效，除了加上上一个)的dp外，还要加上可能存在的与当前)平行的dp
                        dp[i] = dp[i - 1] + 2 + (dp[j - 1] if j >= 1 else 0)
                max_length = max(max_length, dp[i])

        return max_length

    def longestValidParentheses(self, s: str) -> int:
        max_length = 0
        # 栈中初始存入 -1 作为哨兵，方便计算长度
        stack = [-1]

        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            else:
                # 遇到 ')' 弹出栈顶
                stack.pop()
                # 当弹出后栈仍不为空时，当前的右括号找到了匹配的左括号。此时，栈顶元素（不再是刚刚弹出的那个，而是更新后的栈顶）
                # 表示当前有效子串之前最后一个没有被匹配的右括号的索引。用当前索引减去栈顶的索引，就得到了当前有效括号子串的长度。更新最大长度即可。
                # 栈为空：
                # 如果弹出后栈为空，说明当前的右括号没有匹配的左括号，即这个右括号无法参与构成有效子串。
                # 为了记录下一个可能的有效子串的起始位置，将当前的右括号索引压入栈中作为新的起始点。

                if not stack:
                    stack.append(i)
                else:
                    # 当前有效括号子串的长度 = 当前索引 - 栈顶索引
                    max_length = max(max_length, i - stack[-1])
        return max_length
