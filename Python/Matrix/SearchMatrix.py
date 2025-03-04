# LeetCode 21
# 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
# 每行的元素从左到右升序排列。
# 每列的元素从上到下升序排列。

from typing import List


class Solution:
    # 整个矩阵进行二分不可行，不能直接像一维数组那样，一次二分就能确定目标位置。太复杂了，需要用分治法将矩阵分割为多个区域
    # 但这种方式较复杂且不容易实现。可以对每行进行二分。时间复杂度o(nlogm)。
    # z字查找（贪心），时间复杂度o(m + n)。之所以从右上角开始查，是因为判断大小后，可以得到确定性的方块区域，左下角也可以，从左上角和右下角就不行。
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:  # 防止空矩阵
            return False

        m, n = len(matrix), len(matrix[0])  # 获取行数和列数
        row, col = 0, n - 1  # 从右上角开始

        while row < m and col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                col -= 1  # 当前值太大，列左移
            else:
                row += 1  # 当前值太小，行下移

        return False  # 没找到