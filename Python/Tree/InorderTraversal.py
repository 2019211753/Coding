# LeetCode 36
# 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

from typing import List, Optional
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # 递归
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        def help(node: Optional[TreeNode]):
            if node:
                help(node.left)
                result.append(node.val)
                help(node.right)
        help(root)
        return result

    # 迭代
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        nodes = collections.deque()
        node = root
        while nodes or node:
            if node:
                nodes.append(node)
                node = node.left
            else:
                node = nodes.pop()
                result.append(node.val)
                node = node.right
        return result