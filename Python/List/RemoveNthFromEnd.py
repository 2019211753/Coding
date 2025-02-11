# LeetCode 29
# 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 递归
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        def help(l : Optional[ListNode]):
            nonlocal s
            if not l:
                return None
            else:
                next_node = help(l.next)
                s += 1
                if s == n:
                    return next_node
                else:
                    l.next = next_node
                    return l

        s = 0
        return help(head)

    # 快慢指针
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        first = head
        second = dummy
        for i in range(n):
            first = first.next

        while first:
            first = first.next
            second = second.next

        second.next = second.next.next
        return dummy.next