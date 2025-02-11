# LeetCode 31
# 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
# k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
# 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse(l: Optional[ListNode]):
            nonlocal s
            s -= 1
            if s == 0:
                return l
            else:
                reversed_head = reverse(l.next)
                reversed_tail = l.next.next
                l.next.next = l
                l.next = reversed_tail
                return reversed_head

        def get_length(l: Optional[ListNode]):
            len = 0
            while l:
                len += 1
                l = l.next
            return len

        length = get_length(head)
        n = length // k
        dummy = prev = ListNode(-1)
        for i in range(n):
            s = k
            rever_head = reverse(head)
            prev.next = rever_head
            s = k
            while s > 0:
                prev = prev.next
                s -= 1
            head = prev.next
        if not head:
            prev.next = head
        return dummy.next


    def build_linked_list(self, values):
        """根据 Python 列表构建链表，并返回链表头节点"""
        if not values:  # 如果列表为空，返回 None
            return None

        head = ListNode(values[0])  # 创建头节点
        current = head  # 用于遍历链表的指针

        for val in values[1:]:  # 遍历列表的剩余元素
            current.next = ListNode(val)  # 创建新节点并连接
            current = current.next  # 移动到新创建的节点

        return head  # 返回链表的头节点

solution = Solution()
head = solution.build_linked_list([1,2,3,4,5])
solution.reverseKGroup(head, 3)


