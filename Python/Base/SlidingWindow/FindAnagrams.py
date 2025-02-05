# LeetCode 08
# Given two strings s and p, return an array of all the start indices of p's
from typing import List

class Solution:
    # It is more efficient to maintain the sliding window with word frequency, refer to the word frequency of ../Hash/groupAnagrams
    def findAnagrams(self, s: str, p: str) -> List[int]:
        len_sub = len(p)
        i = 0
        result = []
        sorted_p = sorted(p)
        for i in range(len(s) - len(p) + 1):
            substr = s[i: i+len_sub]
            sorted_substr= sorted(substr)
            if sorted_p == sorted_substr:
                result.append(i)

        return result

