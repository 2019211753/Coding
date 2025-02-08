# LeetCode 11
# 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
# 返回 滑动窗口中的最大值 。
from typing import List
import heapq
import collections

class Solution:
    # 一般解法的时间复杂度为 o(nk)。遇到最大值问题用优先队列（大根堆），时间复杂度为 o(nlogn)（堆的插入），空间复杂度为o(n)（最坏情况，数组单调递增）
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        # 注意 Python 默认的优先队列是小根堆
        q = [(-nums[i], i) for i in range(k)]
        heapq.heapify(q)

        ans = [-q[0][0]]
        for i in range(k, n):
            heapq.heappush(q, (-nums[i], i))
            while q[0][1] <= i - k: # 防止最大的数是窗口之外的
                heapq.heappop(q)
            ans.append(-q[0][0])

        return ans

    # 单调队列（双端队列）。时间复杂度O(n)（每个元素最多进一次，出一次），空间复杂度O(k)
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        q = collections.deque()
        for i in range(k): # 队列中左到右 i < j 且 nums[i] > nums[j]
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)

        ans = [nums[q[0]]]
        for i in range(k, n):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            while q[0] <= i - k: # 和大根堆解法一样
                q.popleft()
            ans.append(nums[q[0]])

        return ans

