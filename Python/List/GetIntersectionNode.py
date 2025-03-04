# LeetCode 22
# 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
# 题目数据 保证 整个链式结构中不存在环。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 下面提供双指针方法的正确性证明。考虑两种情况，第一种情况是两个链表相交，第二种情况是两个链表不相交。
    # 情况一：两个链表相交
    # 链表 headA 和 headB 的长度分别是 m 和 n。假设链表 headA 的不相交部分有 a 个节点，链表 headB 的不相交部分有 b 个节点，两个链表相交的部分有 c 个节点，
    # 则有 a+c=m，b+c=n。如果 a=b，则两个指针会同时到达两个链表相交的节点，此时返回相交的节点；
    # 如果 a !=b，则指针 pA 会遍历完链表 headA，指针 pB 会遍历完链表 headB，两个指针不会同时到达链表的尾节点，
    # 然后指针 pA 移到链表 headB 的头节点，指针 pB 移到链表 headA 的头节点，然后两个指针继续移动，
    # 在指针 pA 移动了 a+c+b 次、指针 pB 移动了 b+c+a 次之后，两个指针会同时到达两个链表相交的节点，该节点也是两个指针第一次同时指向的节点，
    # 此时返回相交的节点。
    #
    # 情况二：两个链表不相交
    # 链表 headA 和 headB 的长度分别是 m 和 n。考虑当 m=n 和 m!=n 时，两个指针分别会如何移动：
    # 如果 m=n，则两个指针会同时到达两个链表的尾节点，然后同时变成空值 null，此时返回 null；
    # 如果 m!=n，则由于两个链表没有公共节点，两个指针也不会同时到达两个链表的尾节点，因此两个指针都会遍历完两个链表，
    # 在指针 pA 移动了 m+n 次, 指针 pB 移动了 n+m 次之后，两个指针会同时变成空值 null，此时返回 null。
    #
    # 作者：力扣官方题解
    # 链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/solutions/811625/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/
    # 来源：力扣（LeetCode）
    # 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        # 如果任一链表为空，直接返回None
        if not headA or not headB:
            return None

        # 初始化两个指针
        pointerA, pointerB = headA, headB

        # 遍历两个链表
        while pointerA != pointerB:
            # 如果指针A到达链表A的末尾，重新指向链表B的头
            pointerA = pointerA.next if pointerA else headB
            # 如果指针B到达链表B的末尾，重新指向链表A的头
            pointerB = pointerB.next if pointerB else headA

        # 最终指针A和B相遇的地方就是交点，如果没有交点，返回None
        return pointerA

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        a, b = 0, 0
        node_a, node_b = headA, headB
        while node_a:
            a += 1
            node_a = node_a.next
        while node_b:
            b += 1
            node_b = node_b.next
        if a < b:
            headA, headB = headB, headA
            a, b = b, a
        for _ in range(a - b):
            headA = headA.next
        while headA and headB:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next

        return None

