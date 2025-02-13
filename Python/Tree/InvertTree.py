# LeetCode 38
# 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

from typing import List, Optional
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def help(node):
            if not node:
                return None
            right = help(node.right)
            left = help(node.left)
            node.left = right
            node.right = left
            return node
        return help(root)