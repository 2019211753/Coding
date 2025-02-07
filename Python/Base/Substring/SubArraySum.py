# LeetCode 09
# 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
# 子数组是数组中元素的连续非空序列。
from typing import List

class Solution:
    def subarraySum(nums, k):
        # 哈希表存储前缀和的出现次数
        prefix_sum = {0: 1}  # 初始化为0的前缀和出现一次
        current_sum = 0
        count = 0

        for num in nums:
            current_sum += num  # 更新当前前缀和

            # 如果 current_sum - k 在哈希表中，说明有子数组和为k
            if current_sum - k in prefix_sum:
                count += prefix_sum[current_sum - k]

            # 更新前缀和的出现次数
            if current_sum in prefix_sum:
                prefix_sum[current_sum] += 1
            else:
                prefix_sum[current_sum] = 1

        return count

