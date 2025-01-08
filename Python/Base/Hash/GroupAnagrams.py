# LeetCode 02
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def count(string: str):  # sort���Եõ�hash����������ĸ������Ϊhash����O(n)�ģ�ʱ�临�Ӷȸ���
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
