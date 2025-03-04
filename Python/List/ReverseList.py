# LeetCode 23
# 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 迭代
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        while curr is not None:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev

    # 递归
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        elif head.next is None:
            return head
        else:
            reversed_head = self.reverseList(head.next)
            head.next.next = head # head.next即为反转链表的尾部
            head.next = None
            return reversed_head

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def help(node):
            nonlocal dummy
            if node:
               help(node.next)
               node.next = None
               dummy.next = node
               dummy = node

        dummy_head = dummy = ListNode(0)
        dummy.next = None
        help(head)
        return dummy_head.next

