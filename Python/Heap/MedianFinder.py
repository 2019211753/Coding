# LeetCode 76
# 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
# 例如 arr = [2,3,4] 的中位数是 3 。
# 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
# 实现 MedianFinder 类:
# MedianFinder() 初始化 MedianFinder 对象。
# void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
# double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。

from heapq import heapify
from typing import List
import heapq
import collections

# 我的屎山
class MedianFinder:

    def __init__(self):
        self.max_heap, self.min_heap = [], []
        heapq.heapify(self.max_heap), heapq.heapify(self.min_heap)

    def addNum(self, num: int) -> None:
        if len(self.max_heap) == 0 and len(self.min_heap) == 0:
            heapq.heappush(self.max_heap, -num)
        elif len(self.max_heap) == 0 and self.min_heap[0] >= num:
            heapq.heappush(self.max_heap, -num)
        elif len(self.max_heap) == 0 and self.min_heap[0] < num:
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
            heapq.heappush(self.min_heap, num)
        elif len(self.min_heap) == 0 and -self.max_heap[0] >= num:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
            heapq.heappush(self.max_heap, -num)
        elif len(self.min_heap) == 0 and -self.max_heap[0] < num:
            heapq.heappush(self.min_heap, num)
        elif num >= self.min_heap[0]:
            if len(self.min_heap) - len(self.max_heap) == 1:
                heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
            heapq.heappush(self.min_heap, num)
        elif num <= -self.max_heap[0]:
            if len(self.min_heap) - len(self.max_heap) == -1:
                heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
            heapq.heappush(self.max_heap, -num)
        elif -self.max_heap[0] < num < self.min_heap[0]:
            if len(self.min_heap) - len(self.max_heap) >= 0:
                heapq.heappush(self.max_heap, -num)
            else:
                heapq.heappush(self.min_heap, num)

    def findMedian(self) -> float:
        if (len(self.min_heap) + len(self.max_heap)) % 2 == 1:
            if len(self.max_heap) > len(self.min_heap):
                return -self.max_heap[0]
            else:
                return self.min_heap[0]
        else:
            return (-self.max_heap[0] + self.min_heap[0]) / 2

# GPT的
class MedianFinder:
    def __init__(self):
        # 最大堆存储较小的一半（取负值实现最大堆效果）
        self.max_heap = []
        # 最小堆存储较大的一半
        self.min_heap = []

    # 遇到问题把大根堆pop出来取负到小根堆里即可 或者反之
    def addNum(self, num: int) -> None:
        # 1. 先将新数插入最大堆（取负值以实现最大堆功能）
        heapq.heappush(self.max_heap, -num)

        # 2. 确保最大堆中的最大值 <= 最小堆中的最小值
        if self.min_heap and -self.max_heap[0] > self.min_heap[0]:
            val = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, val)

        # 3. 平衡两个堆的大小，使得两堆长度差不超过 1
        if len(self.max_heap) > len(self.min_heap) + 1:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        elif len(self.min_heap) > len(self.max_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))

    def findMedian(self) -> float:
        # 如果总数为奇数，中位数为较长堆的堆顶
        if len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]
        # 如果总数为偶数，中位数为两个堆顶元素的平均值
        return (-self.max_heap[0] + self.min_heap[0]) / 2
