# LeetCode 41
# 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        queue = deque()
        queue.append((0, root))  # (层级, 节点)
        result = []  # 初始化 result 为一个空列表
        while queue:
            node_level, node = queue.popleft()
            # 如果 result 的长度不够，动态添加空子列表
            if node_level >= len(result):
                result.append([])
            result[node_level].append(node.val)  # 将当前节点的值加入对应层级的子列表
            # 左子节点入队
            if node.left:
                queue.append((node_level + 1, node.left))
            # 右子节点入队
            if node.right:
                queue.append((node_level + 1, node.right))

        return result
