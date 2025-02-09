# LeetCode 17
# 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
# 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

from typing import List

class Solution:
    # 根据输入数组创建一个set哈希表不满语空间复杂度要求，所以使用原地哈希
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        # 将每个正整数放到它该去的位置
        for i in range(n):
            # 交换 nums[i] 和 nums[nums[i] - 1]，当 nums[i] 是正整数并且 nums[i]不在该在的地方时
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                # 交换 nums[i] 和 nums[nums[i] - 1]
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        # 第二次遍历找出第一个不符合条件的索引
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        # 如果所有位置都正确，则缺失的最小正整数是 n + 1
        return n + 1

