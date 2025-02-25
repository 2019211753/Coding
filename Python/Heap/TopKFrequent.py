# LeetCode 75
# 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    # o(nlogn)
    def topKFrequent1(self, nums: List[int], k: int) -> List[int]:
        nums_map = {}
        fre = []
        heapq.heapify(fre)
        for num in nums:
            if num in nums_map:
                nums_map[num] += 1
            else:
                nums_map[num] = 1
        for num in nums_map:
            heapq.heappush(fre, (-nums_map[num], num))

        result = []
        for _ in range(k):
            result.append(heapq.heappop(fre)[1])
        return result

    # 维护大小为 k 的小顶堆，o(nlogk)
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums_map = {}
        fre = []
        heapq.heapify(fre)
        for num in nums:
            if num in nums_map:
                nums_map[num] += 1
            else:
                nums_map[num] = 1
        for num in nums_map:
            if len(fre) < k:
                heapq.heappush(fre, (nums_map[num], num))
            else:
                if nums_map[num] > fre[0][0]:
                    heapq.heappop(fre)
                    heapq.heappush(fre, (nums_map[num], num))
        result = []
        while fre:
            result.append(heapq.heappop(fre)[1])
        return result

solution = Solution()
print(solution.topKFrequent([5,3,1,1,1,3,73,1], 2))

