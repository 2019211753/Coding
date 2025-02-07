# LeetCode 09
# 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
from typing import List

class Solution:
    # It is more efficient to maintain the sliding window with word frequency, refer to the word frequency of ../Hash/groupAnagrams‘
    # maintaining a sliding window may help decrease o(n) to o(1)
    def findAnagrams(self, s: str, p: str) -> List[int]:
        len_sub = len(p)
        result = []
        sorted_p = sorted(p)
        for i in range(len(s) - len(p) + 1):
            substr = s[i: i+len_sub]
            sorted_substr= sorted(substr)
            if sorted_p == sorted_substr:
                result.append(i)

        return result

