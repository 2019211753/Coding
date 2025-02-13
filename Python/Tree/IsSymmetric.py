# LeetCode 39
# 给你一个二叉树的根节点 root ， 检查它是否轴对称。

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # 递归
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # 辅助函数，用于比较两个子树是否对称
        def isMirror(t1, t2):
            # 如果两个节点都为空，说明对称
            if not t1 and not t2:
                return True
            # 如果一个为空一个不为空，说明不对称
            if not t1 or not t2:
                return False
            # 递归比较两个子树的值和结构
            return (t1.val == t2.val) and isMirror(t1.left, t2.right) and isMirror(t1.right, t2.left)

        if not root:
            return True  # 空树是对称的

        return isMirror(root.left, root.right)

    # 迭代，层序遍历
    def isSymmetric(root: TreeNode) -> bool:
        if not root:
            return True

        # 使用队列存储待比较的节点对
        queue = deque([root.left, root.right])

        while queue:
            # 从队列中取出两个节点进行比较
            left, right = queue.popleft(), queue.popleft()

            # 如果两个节点都为空，说明对称
            if not left and not right:
                continue
            # 如果一个为空一个不为空，说明不对称
            if not left or not right:
                return False
            # 如果节点值不相等，也说明不对称
            if left.val != right.val:
                return False

            # 将左右子节点按对称的方式加入队列
            queue.append(left.left)
            queue.append(right.right)
            queue.append(left.right)
            queue.append(right.left)

        return True