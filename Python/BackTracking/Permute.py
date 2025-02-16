# LeetCode 55
# 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

from typing import List, Optional
from collections import deque, defaultdict
import numpy


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def help(result, k):
            if k == n:
                results.append(result[:]) # 注意添加副本，否则递归回溯过程中result会改
                return
            for num in nums:
                if not visit[num]:
                    visit[num] = 1
                    result.append(num)
                    help(result, k + 1)
                    result.pop()
                    visit[num] = 0


        n = len(nums)
        results = []
        visit = {key: 0 for key in nums}
        help([], 0)
        return results

solution = Solution()
results = solution.permute([1, 2, 3])
for i in results:
    print(i)