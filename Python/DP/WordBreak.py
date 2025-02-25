# LeetCode 86
# 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
# 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # 将字典转化为集合，方便查询
        wordSet = set(wordDict)
        # dp[i]表示s的前i个字符是否可以用字典中的单词拼接而成
        dp = [False] * (len(s) + 1)
        dp[0] = True  # 空字符串肯定能拼接成

        # 遍历字符串的每个位置
        for i in range(1, len(s) + 1):
            # 对每个位置i，检查从0到i的位置的所有子串
            for j in range(i):
                # 如果s[0:j]可以拼接，并且s[j:i]是字典中的一个单词
                if dp[j] and s[j:i] in wordSet:
                    dp[i] = True
                    break  # 一旦找到一个匹配的就可以停止检查了

        # 返回dp[len(s)]，即整个字符串是否能拼接成
        return dp[len(s)]

