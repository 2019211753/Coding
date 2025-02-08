# LeetCode 02
# 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
# 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def count(string: str):  # sort可以得到hash，这里用字母计数作为hash，是O(n)的，时间复杂度更低
            counts = [0] * 26
            for char in string:
                counts[ord(char) - ord('a')] += 1
            return tuple(counts)

        grams = {}
        for string in strs:
            counts = count(string)
            if counts in grams:
                grams[counts].append(string)
            else:
                grams[counts] = [string]
        results = []
        for _, gram in grams.items():
            results.append(gram)
        return results
