# LeetCode 82
# 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
# 在「杨辉三角」中，每个数是它左上方和右上方的数的和。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        nums = [[1]]
        for i in range(1, numRows):
            num = [1]
            for j in range(0, i - 1):
                num.append(nums[i - 1][j] + nums[i - 1][j + 1])
            num.append(1)
            nums.append(num)
        return nums

