# LeetCode 45
# 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

from typing import List, Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        result = []
        queue = deque()
        queue.append((0, root))
        depth = 0
        while queue:
            cur_depth, node = queue.popleft()
            if cur_depth == depth:
                depth += 1
                result.append(node.val)
            if node.right:
                queue.append((cur_depth + 1, node.right))
            if node.left:
                queue.append((cur_depth + 1, node.left))
        return result
