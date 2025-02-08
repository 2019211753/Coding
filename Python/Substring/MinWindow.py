# LeetCode 12
# 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
from typing import List
from collections import Counter

class Solution:
    # 比较子串字符频率时 每次都需要比较52次 时间复杂度o(52*m + n)
    def minWindow(self, s: str, t: str) -> str:
        ans_left, ans_right = -1, len(s)
        cnt_s = Counter()  # s 子串字母的出现次数
        cnt_t = Counter(t)  # t 中字母的出现次数

        left = 0
        for right, c in enumerate(s):  # 移动子串右端点
            cnt_s[c] += 1  # 右端点字母移入子串
            # 判断子串是否包含了 t 中的所有字符
            while all(cnt_s[char] >= cnt_t[char] for char in cnt_t):  # 涵盖
                if right - left < ans_right - ans_left:  # 找到更短的子串
                    ans_left, ans_right = left, right  # 记录此时的左右端点
                cnt_s[s[left]] -= 1  # 左端点字母移出子串
                left += 1
        return "" if ans_left < 0 else s[ans_left: ans_right + 1]

    # 用一个变量维护当前子串是否满足要求 时间复杂度 o(m + n)
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        # 记录 t 中的字符频率
        t_count = Counter(t)
        required = len(t_count)  # 目标字符种类的数量

        # 记录窗口中字符的频率
        window_count = {}
        left, right = 0, 0
        formed = 0  # 窗口中符合条件的字符种类数
        ans = float("inf"), None, None  # 最小窗口的长度、左索引、右索引

        # 通过右指针扩展窗口
        while right < len(s):
            # 计算当前字符并将其加入窗口
            char = s[right]
            window_count[char] = window_count.get(char, 0) + 1

            # 如果窗口中字符满足了 t_count 中的需求，增加 formed
            if char in t_count and window_count[char] == t_count[char]:
                formed += 1

            # 如果 formed 等于 required，说明当前窗口是有效的，开始尝试收缩窗口
            while left <= right and formed == required:
                # 更新最小窗口
                window_size = right - left + 1
                if window_size < ans[0]:
                    ans = window_size, left, right

                # 收缩窗口，移动左指针
                left_char = s[left]
                window_count[left_char] -= 1
                if left_char in t_count and window_count[left_char] < t_count[left_char]:
                    formed -= 1  # 如果不再满足 t_count 中的需求，减少 formed

                left += 1

            # 扩展右指针
            right += 1

        # 如果找到了有效的子串，返回最小子串
        if ans[0] == float("inf"):
            return ""
        else:
            return s[ans[1]:ans[2] + 1]


