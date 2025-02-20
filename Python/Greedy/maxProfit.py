# LeetCode 77
# 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
# 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
# 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

from heapq import heapify
from typing import List
import heapq
import collections

class Solution:
    # 动态规划，类似于接雨水了，数组最大差值
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        leftmin, rightmax = [prices[0]] * n, [prices[n - 1]] * n
        for i in range(1, n):
            leftmin[i] = min(prices[i], leftmin[i - 1])
        for i in range(n - 2, -1, -1):
            rightmax[i] = max(prices[i], rightmax[i + 1])
        result = 0
        for i in range(n):
            result = max(result, rightmax[i] - leftmin[i])
        return result

    # 直接看第i天之前的最大最小值，坐记录
    def maxProfit(self, prices: List[int]) -> int:
        inf = int(1e9)
        minprice = inf
        maxprofit = 0
        for price in prices:
            maxprofit = max(price - minprice, maxprofit)
            minprice = min(price, minprice)
        return maxprofit


