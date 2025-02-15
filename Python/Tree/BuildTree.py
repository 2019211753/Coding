# LeetCode 47
# 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def help(i, j, m, n):
            if i <= j:
                node = TreeNode(preorder[i])
                # 可以通过建立hash映射节省时间 hash_index[inorder[i]] = i
                for k in range(m, n + 1):
                    if inorder[k] == preorder[i]:
                        break

                node.left = help(i + 1, i + k - m, m, k - 1)
                node.right = help(i + k - m + 1, j, k + 1, n)
                return node
            else:
                return None
        return help(0, len(preorder) - 1, 0, len(inorder) - 1)


solution = Solution()
solution.buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20 ,7])