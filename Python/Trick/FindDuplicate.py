# LeetCode 100
# 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
# 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
# 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

from typing import List

from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # 第一步：寻找两个指针相遇的点（证明存在环）
        # 将数组看成一个链表，其中每个索引 i 的下一个节点是 nums[i]。
        # 由于 nums 中数字范围是 [1, n]，数组长度为 n+1，因此必然存在重复数字，
        # 对应链表中必然存在一个环。
        slow = nums[0]
        fast = nums[0]
        while True:
            # 慢指针每次走一步
            slow = nums[slow]
            # 快指针每次走两步
            fast = nums[nums[fast]]
            if slow == fast:
                break  # 相遇，说明存在环

        # 第二步：寻找环的入口，也就是重复的数字
        # 将慢指针重新置于起点，然后快慢指针一起每次走一步，
        # 它们相遇的地方就是环的入口，也就是重复的数字。
        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]

        return slow