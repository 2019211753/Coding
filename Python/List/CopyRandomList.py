# LeetCode 32
# 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

from typing import List, Optional

# Definition for singly-linked list.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
         dict = {}
         prev = head
         while prev:
             node = Node(prev.val)
             dict[prev] = node
             prev = prev.next
         dummy = prev = Node(-1)
         while head:
             if head.next:
                dict[head].next = dict[head.next]
             if head.random:
                 dict[head].random = dict[head.random]
             prev.next = dict[head]
             prev = prev.next
             head = head.next
         return dummy.next

