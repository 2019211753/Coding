# LeetCode 43
# 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
# 有效 二叉搜索树定义如下：
# 节点的 左子树 只包含 小于 当前节点的数。节点的 右子树 只包含 大于 当前节点的数。
# 所有左子树和右子树自身必须也是二叉搜索树。

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # 递归的剪枝
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def help(node):
            nonlocal result
            if not node:
                return True
            stop = help(node.left)
            if not stop:
                return stop
            if len(result) == 0 or (len(result) != 0 and result[-1] < node.val):
                result.append(node.val)
            else:
                return False
            return help(node.right)
        result = []
        return help(root)

    # 迭代写的更舒服
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        queue = deque()
        node = root
        result = []
        while queue or node:
            if node:
                queue.append(node)
                node = node.left
            else:
                node = queue.pop()
                if len(result) == 0 or result[-1] < node.val:
                    result.append(node.val)
                else:
                    return False
                node = node.right
        return True