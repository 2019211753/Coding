# LeetCode 69
# 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
# 有效字符串需满足：
# 左括号必须用相同类型的右括号闭合。
# 左括号必须以正确的顺序闭合。
# 每个右括号都有一个对应的相同类型的左括号。

from typing import List
import heapq
import collections


class Solution:
    def isValid(self, s: str) -> bool:
        queue = []
        for string in s:
            if string == ')':
                if len(queue) == 0 or queue[-1] != '(':
                    return False
                else:
                    queue.pop()
            if string == '}':
                if len(queue) == 0 or queue[-1] != '{':
                    return False
                else:
                    queue.pop()
            if string == ']':
                if len(queue) == 0 or queue[-1] != '[':
                    return False
                else:
                    queue.pop()
            if string not in ")}]":
                queue.append(string)

        if len(queue) != 0:
            return False
        return True