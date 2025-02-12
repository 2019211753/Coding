# LeetCode 33
# 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
# 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def split(head, n):
            # 从 head 开始，切出前 n 个节点
            for i in range(1, n):
                if head:
                    head = head.next
                else:
                    break
            if not head:
                return None
            next_head = head.next
            head.next = None
            return next_head

        def merge(l1, l2):
            dummy = ListNode(0)
            tail = dummy
            while l1 and l2:
                if l1.val < l2.val:
                    tail.next = l1
                    l1 = l1.next
                else:
                    tail.next = l2
                    l2 = l2.next
                tail = tail.next
            tail.next = l1 if l1 else l2
            # 移动 tail 到合并链表的尾部
            while tail.next:
                tail = tail.next
            return dummy.next, tail

        if not head or not head.next:
            return head

        # 计算链表长度
        length = 0
        node = head
        while node:
            length += 1
            node = node.next

        dummy = ListNode(0)
        dummy.next = head
        step = 1

        while step < length: # 自底向上迭代，不用递归调用可以做到常数级额外空间
            cur = dummy.next
            tail = dummy
            while cur:
                left = cur
                right = split(left, step)  # 切出左子链表，并返回右子链表的起始节点
                cur = split(right, step)  # 切出右子链表，并返回下一部分的起始节点
                merged_head, merged_tail = merge(left, right)
                tail.next = merged_head
                tail = merged_tail
            step *= 2
        return dummy.next

