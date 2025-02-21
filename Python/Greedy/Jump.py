# LeetCode 79
# 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
# 每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
# 0 <= j <= nums[i]
# i + j < n
# 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        rightmost = 0
        jumps = [0] * n
        for i in range(n):
            if rightmost >= n - 1:
                return jumps[n - 1]
            currentmost = nums[i] + i
            if currentmost > rightmost:
                for j in range(rightmost + 1, min(n, currentmost + 1)):
                    jumps[j] = jumps[i] + 1
                rightmost = currentmost

solution = Solution()
print(solution.jump([7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]))