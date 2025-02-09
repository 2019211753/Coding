# LeetCode 15
# 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
# 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
# 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
from itertools import product
from typing import List

class Solution:
    # 左右乘积序列 空间复杂度O(n)
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        product_left, product_right = [1] * n, [1] * n
        result = [0] * n
        for i in range(1, n):
            product_left[i] = product_left[i - 1] * nums[i - 1]
            product_right[n - i - 1] = product_right[n - i] * nums[n - i]
        for j in range(0, n):
            result[j] = product_left[j] * product_right[j]
        return result

    # 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）
    # 思路一样，但由于输出数组不被视为额外空间，所以将输出数组作为上文的product_left，就好
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        product_left = [1] * n
        product_right = 1
        for i in range(1, n):
            product_left[i] = product_left[i - 1] * nums[i - 1]
        for j in range(1, n):
            product_right *= nums[n - j]
            product_left[n - j - 1] *= product_right
        return product_left