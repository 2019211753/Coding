# LeetCode 14
# 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
# 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sorted_intervals = sorted(intervals, key=lambda x: x[0])
        result = []
        interval = sorted_intervals[0]
        for i in range(1, len(sorted_intervals)):
            if sorted_intervals[i][0] <= interval[1]:
                if sorted_intervals[i][1] > interval[1]:
                    interval[1] = sorted_intervals[i][1]
                else:
                    continue
            else:
                result.append(interval)
                interval = sorted_intervals[i]
        result.append(interval)
        return result