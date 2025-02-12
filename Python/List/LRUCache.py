# LeetCode 35
# 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
# 实现 LRUCache 类：
# LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
# int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
# void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
# 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
# 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
from linecache import cache

import collectionscodi

# 我写的
class LRUCache:

    def __init__(self, capacity: int):
        # 结点不但需要存储key，还要存储value，因为找到应该删除的结点靠的是定位链表中的结点，清理链表结点的同时清理hash表结点
        # 而hash必须要存key（o(1)查找）所以链表中的结点要存key
        class Node:
            def __init__(self, key, value):
                self.key = key
                self.val = value
                self.prev = None
                self.next = None

        self.capacity = capacity
        self.cur = 0
        self.cache = {}
        self.Node = Node
        self.dummy = Node(-1, -1)
        self.tail = self.dummy

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            if node != self.dummy.next:
                prev_node = node.prev
                next_node = node.next
                prev_node.next = next_node
                if next_node:
                    next_node.prev = prev_node
                else:
                    if self.dummy.next != self.tail:
                        self.tail = prev_node
                dummy_next = self.dummy.next
                node.next = dummy_next
                node.prev = self.dummy
                if dummy_next:
                    dummy_next.prev = node
                self.dummy.next = node
            return node.val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            node.val = value
            prev_node = node.prev
            if node == self.tail and self.dummy.next != self.tail:
                self.tail = prev_node
            next_node = node.next
            prev_node.next = next_node
            if next_node:
                next_node.prev = prev_node
            dummy_next = self.dummy.next
            node.next = dummy_next
            node.prev = self.dummy
            if dummy_next:
                dummy_next.prev = node
            self.dummy.next = node
        else:
            if self.cur >= self.capacity:
                node = self.tail
                prev_node = node.prev
                prev_node.next = None
                self.tail = prev_node
                self.cache.pop(node.key)
                del node
                self.cur -= 1
            node = self.Node(key, value)
            if self.tail == self.dummy:
                self.tail = node
            dummy_next = self.dummy.next
            node.prev = self.dummy
            node.next = self.dummy.next
            self.dummy.next = node
            if dummy_next:
                dummy_next.prev = node
            self.cur += 1
            self.cache[key] = node

# GPT写的
class LRUCache:
    class Node:
        def __init__(self, key=0, val=0):
            self.key = key
            self.val = val
            self.prev = None
            self.next = None

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # key -> Node
        self.size = 0
        # 伪头节点和伪尾节点
        self.head = LRUCache.Node()
        self.tail = LRUCache.Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def _add_node(self, node: 'LRUCache.Node'):
        """
        将新节点添加到伪头节点之后（最常使用的位置）。
        """
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def _remove_node(self, node: 'LRUCache.Node'):
        """
        删除链表中的某个节点。
        """
        prev_node = node.prev
        next_node = node.next
        prev_node.next = next_node
        next_node.prev = prev_node

    def _move_to_head(self, node: 'LRUCache.Node'):
        """
        将某个节点移到头部，表示最近使用过。
        """
        self._remove_node(node)
        self._add_node(node)

    def _pop_tail(self) -> 'LRUCache.Node':
        """
        移除并返回链表尾部的节点（真正的尾节点的前一个伪尾）。
        """
        node = self.tail.prev
        self._remove_node(node)
        return node

    def get(self, key: int) -> int:
        node = self.cache.get(key, None)
        if not node:
            return -1
        # 使用过之后，将节点移到头部
        self._move_to_head(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        node = self.cache.get(key)
        if not node:
            # 如果 key 不存在，则创建一个新的节点
            new_node = LRUCache.Node(key, value)
            self.cache[key] = new_node
            self._add_node(new_node)
            self.size += 1

            if self.size > self.capacity:
                # 超出容量，弹出尾部节点
                tail = self._pop_tail()
                del self.cache[tail.key]
                self.size -= 1
        else:
            # 如果 key 存在，则更新节点值并移到头部
            node.val = value
            self._move_to_head(node)
