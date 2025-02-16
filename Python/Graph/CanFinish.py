# LeetCode 53
# 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
# 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
# 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
# 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

from typing import List, Optional
from collections import deque, defaultdict
import numpy

class Solution:
    # 我写的，能过但是很丑
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        def dfs(course):
            if right[course] == 1:
                return True
            if flag[course] == 1:
                return False
            flag[course] = 1
            if course in dict:
                pres = dict[course]
            else:
                pres = []
            finish = True
            for p in pres:
                success = dfs(p)
                finish = finish & success
                if finish:
                    right[p] = 1
                else:
                    return finish
            return finish

        dict = {}
        for pre in prerequisites:
            if pre[0] in dict:
                dict[pre[0]].append(pre[1])
            else:
                dict[pre[0]] = [pre[1]]
        right = [0] * numCourses
        for course in dict:
            flag = [0] * numCourses
            if right[course] == 1:
                continue
            over = dfs(course)
            right[course] = over
            if not over:
                return over
        return True

    # 官方题解，好看不少，快一点点但不多
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        edges = defaultdict(list)
        visited = [0] * numCourses # 分三种状态，没搜索到、搜索中、搜索完
        result = list()
        valid = True

        for info in prerequisites:
            edges[info[1]].append(info[0])

        def dfs(u: int):
            nonlocal valid
            visited[u] = 1
            for v in edges[u]:
                if visited[v] == 0: # 没搜索到，去搜索
                    dfs(v)
                    if not valid:
                        return
                elif visited[v] == 1: # 没搜索完之前又搜索到了，停止
                    valid = False
                    return
            # 如果visited[v] == 2，则之前搜索过，但是没问题，就不考虑了
            visited[u] = 2
            result.append(u)

        for i in range(numCourses):
            if valid and not visited[i]:
                dfs(i)

        return valid