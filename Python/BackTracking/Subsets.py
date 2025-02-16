# LeetCode 56
# 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
# 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

from typing import List, Optional
from collections import deque, defaultdict
import numpy

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def help(result, k):
            if k == n:
                if tuple(result[:]) not in results:
                    results.add(tuple(result[:]))  # 注意添加副本，否则递归回溯过程中result会改
                return
            for num in nums:
                if not visit[num]:
                    visit[num] = 1
                    result.append(num)
                    help(result, k + 1)
                    result.pop()

                    help(result, k + 1)
                    visit[num] = 0


        n = len(nums)
        results = set()
        visit = {key: 0 for key in nums}
        help([], 0)
        return list(results)

# 误会了，以为只是从全排列到排列了
class Solution1:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def help(result, k):
            if k == n:
                results.add(tuple(result[:]))  # 使用元组存储结果，防止重复
                return
            # 选择当前元素
            result.append(nums[k])
            help(result, k + 1)
            # 不选择当前元素
            result.pop()
            help(result, k + 1)

        n = len(nums)
        results = set()
        help([], 0)
        return [list(subset) for subset in results]  # 返回的是 list 的列表

solution = Solution()
results = solution.subsets([1, 2, 3])
for i in results:
    print(i)