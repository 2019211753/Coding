# LeetCode 58
# 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，
# 并以列表形式返回。你可以按 任意顺序 返回这些组合。
# candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
# 对于给定的输入，保证和为 target 的不同组合数少于 150 个。

from typing import List, Optional
from collections import deque, defaultdict
import numpy

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def help(k, result, target_sum):
            if target_sum == 0:
                results.add(tuple(result[:]))
            if k >= n or target_sum < 0:
                return
            i = 0
            while target_sum - i * candidates[k] >= 0:
                for _ in range(i):
                    result.append(candidates[k])
                help(k + 1, result, target_sum - i * candidates[k])
                for _ in range(i):
                    result.pop()
                i += 1
        results = set()
        n = len(candidates)
        help(0, [], target)
        return list(results)

solution = Solution()
print(solution.combinationSum(candidates = [2, 3, 6, 7], target=7))