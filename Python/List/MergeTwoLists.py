# LeetCode 27
# 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # 创建一个虚拟头节点
        dummy = ListNode(0)
        prev = dummy

        # 遍历两个链表
        while list1 and list2:
            if list1.val <= list2.val:
                prev.next = list1  # 将 list1 的当前节点接到结果链表
                list1 = list1.next  # list1 移动到下一个节点
            else:
                prev.next = list2  # 将 list2 的当前节点接到结果链表
                list2 = list2.next  # list2 移动到下一个节点
            prev = prev.next  # prev 指针移动到新连接的节点

        # 处理剩余部分
        prev.next = list1 if list1 else list2

        return dummy.next  # 返回合并后的链表头节点