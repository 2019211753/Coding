# LeetCode 71
# 给定一个经过编码的字符串，返回它解码后的字符串。
# 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
# 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
# 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

from typing import List
import heapq
import collections

class Solution:
    def decodeString(self, s: str) -> str:
        n = len(s)
        nums = []
        strs = []
        i = 0
        while i < n:
            if '0' <= s[i] <= '9':
                num = ""
                while '0' <= s[i] <= '9':
                    num += s[i]
                    i += 1
                nums.append(int(num))
            elif s[i] == ']':
                string = ""
                while strs[-1] != '[':
                    string = strs.pop() + string
                strs.pop()
                string *= nums.pop()
                strs.extend(string)
                i += 1
            else:
                strs.append(s[i])
                i += 1
        return ''.join(strs)

solution = Solution()
solution.decodeString("3[a]2[bc]")

