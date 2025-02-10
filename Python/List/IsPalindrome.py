# LeetCode 24
# 给你一个单链表的头节点 head ，请你判断该链表是否为 回文链表。如果是，返回 true ；否则，返回 false 。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 双指针，时间复杂度o(n) 空间复杂度o(n)
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        vals = []
        while head is not None:
            vals.append(head.val)
            head = head.next
        n = len(vals)
        for i in range(n // 2):
            if vals[i] != vals[n - i - 1]:
                return False
        return True

    # 快慢指针，反转链表。空间复杂度o(1)，但需要修改原链表，不是很好
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return True

        # 1. 使用快慢指针找到中间节点
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # 2. 反转后半部分链表
        prev = None
        while slow:
            next_node = slow.next
            slow.next = prev
            prev = slow
            slow = next_node

        # 3. 比较前半部分和反转后的后半部分
        left, right = head, prev
        while right:  # 只需要比较右半部分即可
            if left.val != right.val:
                return False
            left = left.next
            right = right.next

        return True

    # 递归，空间复杂度o(1)
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # 用于递归过程中回溯的辅助函数
        def helper(node):
            nonlocal head  # 使用外部的head变量
            if node is None:
                return True
            # 递归处理后续节点
            result = helper(node.next)
            # 如果已经不匹配，则直接返回False
            if not result or node.val != head.val:
                return False
            # 回溯到当前节点后，头节点向后移动一位
            head = head.next
            return True

        return helper(head)
