# LeetCode 49
# 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
# 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

from typing import List, Optional
from collections import deque, defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def help(node):
            nonlocal result
            if not node:
                return None
            left = help(node.left)
            right = help(node.right)
            if {left, right} == {p, q} or {left, node} == {p, q} or {right, node} == {p, q}:
                result = node
                return node
            if node in {p, q}:
                return node
            if left in {p, q}:
                return left
            if right in {p, q}:
                return right
            return None
        result = None
        help(root)
        return result

# 官方题解
class Solution:
    def __init__(self):
        self.ans = None

    def dfs(self, root, p, q):
        if not root:
            return False

        lson = self.dfs(root.left, p, q)
        rson = self.dfs(root.right, p, q)

        if (lson and rson) or ((root.val == p.val or root.val == q.val) and (lson or rson)):
            self.ans = root

        return lson or rson or (root.val == p.val or root.val == q.val)

    def lowestCommonAncestor(self, root, p, q):
        self.dfs(root, p, q)
        return self.ans
