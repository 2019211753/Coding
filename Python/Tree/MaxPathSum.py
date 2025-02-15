# LeetCode 50
# 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
# 路径和 是路径中各节点值的总和。
# 给你一个二叉树的根节点 root ，返回其 最大路径和 。

from typing import List, Optional
from collections import deque, defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def helper(node):
            nonlocal result
            if not node:
                return -10**4
            left_max = helper(node.left)
            right_max = helper(node.right)
            cur_max = max(max(0, left_max), max(0, right_max)) + node.val
            result = max(result, left_max, right_max, cur_max, max(0, left_max) + max(0, right_max) + node.val)
            return cur_max
        result = -10**4
        helper(root)
        return result