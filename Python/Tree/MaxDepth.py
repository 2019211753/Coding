# LeetCode 37
# 给定一个二叉树 root ，返回其最大深度。
# 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

from typing import List, Optional
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def help(node, depth):
            nonlocal result
            if not node:
                return
            if not node.left and not node.right:
                if depth > result:
                    result = depth
                return
            help(node.left, depth + 1)
            help(node.right, depth + 1)

        result = 0
        help(root, 1)
        return result

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def help(node, depth):
            if not node:
                return depth - 1
            left_depth = help(node.left, depth + 1)
            right_depth = help(node.right, depth + 1)
            return max(left_depth, right_depth)

        return help(root, 1)
