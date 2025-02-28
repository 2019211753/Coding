# LeetCode 97
# 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
# 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

from typing import List, Optional

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        val = nums[0]
        count = 1
        for i in range(1, n):
            if nums[i] == val:
                count += 1
            elif count == 1:
                val = nums[i]
                count = 1
            else:
                count -= 1
        return val
