# LeetCode 08
# 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
from typing import List

class Solution:
    # def lengthOfLongestSubstring(self, s: str) -> int:
    #     i, j = 0, 0
    #     max_len = 0
    #     substr = ""
    #     while j < len(s):
    #         k = substr.find(s[j])
    #         if k == -1:
    #             substr += s[j]
    #         else:
    #             if j - i > max_len:
    #                 max_len = j - i
    #             substr = substr[k + 1:] + s[j]
    #             i = i + k + 1
    #         j += 1
    #     if j - i > max_len:
    #         max_len = j - i
    #     return max_len

    # LeetCode Official. Same but more concise and templated
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Hash set to record whether a character has appeared
        occ = set()
        n = len(s)
        # Right pointer, initial value is -1, meaning we are at the left boundary before the start of the string
        rk, ans = -1, 0
        for i in range(n):
            if i != 0:
                # Move the left pointer to the right by one step, remove one character
                occ.remove(s[i - 1])
            while rk + 1 < n and s[rk + 1] not in occ:
                # Continuously move the right pointer
                occ.add(s[rk + 1])
                rk += 1
            # The substring from index i to rk is the longest substring without repeating characters
            ans = max(ans, rk - i + 1)
        return ans

# 创建 Solution 类的实例
solution = Solution()

# 调用 lengthOfLongestSubstring 方法并传入字符串
result = solution.lengthOfLongestSubstring(" ")
print(result)  # 输出结果