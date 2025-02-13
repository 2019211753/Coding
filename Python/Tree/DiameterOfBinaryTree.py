# LeetCode 40
# 给你一棵二叉树的根节点，返回该树的 直径 。
# 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
# 两节点之间路径的 长度 由它们之间边数表示。

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def help(node):
            if not node:
                return 0
            if not node.left and not node.right:
                return 1
            nonlocal result
            left = help(node.left)
            right = help(node.right)
            dis = left + right
            result = max(dis, result)
            return max(left, right) + 1
        result = 0
        help(root)
        return result

