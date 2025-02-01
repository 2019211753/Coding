# LeetCode 05
# You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
# Find two lines that together with the x-axis form a container, such that the container contains the most water.
# Return the maximum amount of water a container can store
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
            if height[i] <= height[j]:
                i += 1
            else:
                j -= 1


