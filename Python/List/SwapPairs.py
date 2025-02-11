# LeetCode 30
# 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = prev = ListNode(-1)
        if not head or not head.next:
            return head
        while head and head.next:
            prev.next = head.next
            head.next = head.next.next
            prev.next.next = head
            prev = head
            head = head.next
        if head:
            prev.next = head
        return dummy.next




















