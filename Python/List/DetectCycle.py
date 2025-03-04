# LeetCode 26
# 给定一个链表的头节点 head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
# 不允许修改 链表。

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 我们使用两个指针，fast 与 slow。它们起始都位于链表的头部。随后，slow 指针每次向后移动一个位置，而 fast 指针向后移动两个位置。
    # 如果链表中存在环，则 fast 指针最终将再次与 slow 指针在环中相遇。
    # 如下图所示，设链表中环外部分的长度为 a。slow 指针进入环后，又走了 b 的距离与 fast 相遇。c为环剩下的长度。
    # 此时，fast 指针已经走完了环的 n 圈，因此它走过的总距离为 a+n(b+c)+b=a+(n+1)b+nc。
    # 根据题意，任意时刻，fast 指针走过的距离都为 slow 指针的 2 倍。因此，我们有
    #
    # a+(n+1)b+nc=2(a+b)⟹a=c+(n−1)(b+c)（由于fast速度是slow的二倍，所以一定是在slow第一圈跑完前就能碰到）
    # 有了 a=c+(n−1)(b+c) 的等量关系，我们会发现：从相遇点到入环点的距离加上 n−1 圈的环长，恰好等于从链表头部到入环点的距离。
    #
    # 因此，当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。
    #
    # 作者：力扣官方题解
    # 链接：https://leetcode.cn/problems/linked-list-cycle-ii/solutions/441131/huan-xing-lian-biao-ii-by-leetcode-solution/
    # 来源：力扣（LeetCode）
    # 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 快慢指针
        slow, fast = head, head

        # 步骤 1: 检测链表中是否有环
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            # 如果快慢指针相遇，则说明有环
            if slow == fast:
                # 步骤 2: 找到环的入口节点
                pointer = head
                while pointer != slow:
                    pointer = pointer.next
                    slow = slow.next
                return pointer  # 环的入口节点

        # 如果没有环，返回 None
        return None

    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        slow, fast = head, head.next
        while slow and fast and fast.next:
            if slow != fast:
                slow = slow.next
                fast = fast.next.next
                print(slow.val)
            else:
                slow = head
                fast = fast.next
                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                return slow
        return None
