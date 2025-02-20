# LeetCode 05
# 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
# 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
# 返回容器可以储存的最大水量。
# 说明：你不能倾斜容器。

from typing import List

class Solution:
    # no efficient o(n^2)
    # def maxArea(self, height: List[int]) -> int:
    #     max_area = 0
    #     for i in range(len(height)):
    #         for j in range(i+1, len(height)):
    #             area = (j - i) * min(height[i], height[j])
    #             if area > max_area:
    #                 max_area = area
    #     return max_area

    # efficient o(n)
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        i, j = 0, len(height) - 1
        while i <= j:
            area = (j - i) * min(height[i], height[j])
            if area > max_area:
                max_area = area
            # if height[i] <= height[j] at initial, any other j can't be higher because the distance j - i is the largest
            # and max(min(height[i] <= height[j]) for any j can't be higher. Thus move the right pointer, store
            # current are as the minimum maximum area
            # 双指针移动后的结果一定是单调的，贪婪的
            if height[i] <= height[j]:
                i += 1
            else:
                j -= 1


