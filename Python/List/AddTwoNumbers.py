# LeetCode 28
# 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
# 请你将两个数相加，并以相同形式返回一个表示和的链表。
# 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    class Solution:
        def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
            # 创建一个虚拟头节点，便于操作
            dummy_head = ListNode(0)
            current = dummy_head  # 结果链表的当前节点
            carry = 0  # 进位

            # 遍历两个链表，直到两个链表都为空，且进位为0
            while l1 or l2 or carry:
                # 获取当前位的数字，若链表已遍历完，则值为0
                val1 = l1.val if l1 else 0
                val2 = l2.val if l2 else 0

                # 计算当前位的和，以及进位
                total = val1 + val2 + carry
                carry = total // 10  # 进位
                current.next = ListNode(total % 10)  # 当前位的数字

                # 移动当前链表指针
                current = current.next

                # 移动 l1 和 l2 指针
                if l1:
                    l1 = l1.next
                if l2:
                    l2 = l2.next

            return dummy_head.next  # 返回合并后的链表（跳过虚拟头节点）





        head = prev = ListNode(-1)