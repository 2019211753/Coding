# LeetCode 80
# 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
# 例如，字符串 "ababcc" 能够被分为 ["abab", "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。
# 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
# 返回一个表示每个字符串片段的长度的列表。

from heapq import heapify
from typing import List
import heapq
import collections


class Solution:
    # 哈希表判断当前片段字母是否全了，比下面的慢一点，但空间复杂度少一点
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        labels_dict = {}
        for string in s:
            if string in labels_dict:
                labels_dict[string] += 1
            else:
                labels_dict[string] = 1
        result = []
        cur_dict = {}
        last = -1
        for i in range(n):
            if s[i] in cur_dict:
                cur_dict[s[i]] += 1
            else:
                cur_dict[s[i]] = 1
            flag = True
            for string in cur_dict:
                if cur_dict[string] != labels_dict[string]:
                    flag = False
                    break
            if flag:
                result.append(i - last)
                last = i
                cur_dict = {}
        return result

    # 先维护每个字母的最后出现位置，若当前串最后出现距离等于当前字符的最后出现距离，则字母全了。如果小于，则更新当前串最后出现距离，大于不管，继续遍历
    def partitionLabels(self, s: str) -> List[int]:
        last = [0] * 26
        for i, ch in enumerate(s):
            last[ord(ch) - ord("a")] = i

        partition = list()
        start = end = 0
        for i, ch in enumerate(s):
            end = max(end, last[ord(ch) - ord("a")])
            if i == end:
                partition.append(end - start + 1)
                start = end + 1

        return partition

solution = Solution()
solution.partitionLabels("ababcbacadefegdehijhklij")