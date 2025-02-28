# LeetCode 98
# 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
# 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
# 必须在不使用库内置的 sort 函数的情况下解决这个问题。

from typing import List, Optional

class Solution:
    # 默写快排
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def sort(low, high):

            if low >= high:
                return
            i, j = low, high
            mid = (i + j) // 2
            pivot = nums[mid]
            nums[i], nums[mid] = nums[mid], nums[i]
            while i < j:
                while i < j and nums[j] > pivot:
                    j -= 1
                if i < j:
                    nums[i] = nums[j]
                    i += 1
                while i < j and nums[i] < pivot:
                    i += 1
                if i < j:
                    nums[j] = nums[i]
                    j -= 1
            nums[i] = pivot
            sort(low, i - 1)
            sort(i + 1, high)
        return sort(0, len(nums) - 1)

    def sortColors(self, nums: List[int]) -> None:
        n = len(nums)
        p0, p2 = 0, n - 1 # p2右侧都是2，p0左侧都是0
        i = 0 # i 左侧的0和2都去了该去的地方
        while i <= p2: # 不能 p0 >= p2，还有p1
            while i <= p2 and nums[i] == 2: # 避免p2交换过来的是2，那样 i += 1 后会有问题
                nums[i], nums[p2] = nums[p2], nums[i]
                p2 -= 1
            if i <= p2 and nums[i] == 0: # 如果是0，不处理会有问题
                nums[i], nums[p0] = nums[p0], nums[i]
                p0 += 1
            i += 1