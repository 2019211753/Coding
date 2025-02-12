# LeetCode 34
# 给你一个链表数组，每个链表都已经按升序排列。
# 请你将所有链表合并到一个升序链表中，返回合并后的链表。

from typing import List, Optional
import heapq

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 顺序遍历 时间复杂度O(nk)，空间复杂度O(1)
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def findMin(heads: List[Optional[ListNode]]):
            min_node = ListNode(10e4)
            min_index = -1
            for i in range(n):
                if heads[i] and heads[i].val <= min_node.val:
                    min_node = heads[i]
                    min_index = i
            return min_node, min_index

        def checkNull(heads: List[Optional[ListNode]]):
            flag = False
            for i in range(n):
                if heads[i]:
                    flag = True
                    return flag
            return flag

        n = len(lists)
        if n == 0:
            return None

        dummy = prev = ListNode(-1)
        while checkNull(lists):
            node, index = findMin(lists)
            print(f"index:{index}, val:{node.val}")
            prev.next = node
            prev = prev.next
            lists[index] = lists[index].next
        return dummy.next


    # 最小堆，优先队列，时间复杂度O(nlog k)，空间复杂度O(k)
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        # 将每个非空链表的头节点加入堆中
        for i, node in enumerate(lists):
            if node:
                # 元组中加入一个唯一的编号 i 以防止当节点值相同时堆比较失败
                heapq.heappush(heap, (node.val, i, node))

        dummy = ListNode(0)
        tail = dummy

        while heap:
            val, i, node = heapq.heappop(heap)
            tail.next = node
            tail = tail.next
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))

        return dummy.next

    # 归并排序，时间复杂度O(nlog k）如果迭代的话就是空间复杂度O(1)，递归就是O(log k)
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
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
            return dummy.next

        if not lists:
            return None
        n = len(lists)
        interval = 1
        while interval < n:
            for i in range(0, n - interval, interval * 2):
                lists[i] = mergeTwoLists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0]
