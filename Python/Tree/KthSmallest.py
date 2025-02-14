# LeetCode 44
# 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        queue = deque()
        node = root
        n = 0
        while queue or node:
            if node:
                queue.append(node)
                node = node.left
            else:
                node = queue.pop()
                n = n + 1
                if n == k:
                    return node.val
                node = node.right
        return True