#include "../AdjacencyListBasic.cpp"

//顶点标记 一定先初始化为0
int visit_dfs[MAXSIZE] = {0};

/**
 * 判断一张无向图是否是一棵树
 * 如果图的边数 = 顶点数 - 1，且图是联通的，或图是无回路的连通图，可以形成一棵树。本算法采用前者。
 * 若仅有边数 = 顶点数 - 1 则未必联通 如正方形左上角三个顶点成环 右下角顶点孤立
 * 我觉得也可以正常dfs遍历，然后直接比较e == n - 1 && visit全为1
 * @param G 任意一张图
 * @param v 顶点序号 随便取
 * @param vn 顶点数
 * @param en 边数（有向）
 */
void dfs(MyGraph *G, int v, int &vn, int &en) {
    ArcNode *p;
    visit_dfs[v] = 1;
    //访问到一个顶点后就 + 1
    ++vn;
    p = G->adjList[v].firstArc;
    while(p != nullptr) {
        //不管这个边的另一个顶点有没有被访问过，都记录，这样最后就变成2 * 原边数 也可以判断
        //能不能加一个判断条件，另一个顶点被访问过就不记录？
        //不行，这个边的这个顶点和另一个顶点都被访问过不代表这个边已经被访问过了
        //如 A —— B —— C
        //         \  /
        //          D
        //B被访问完访问C，C被访问完访问D，在D深度遍历时，发现B已经被遍历了，不遍历DB这条边，回溯到B时，发现D
        //也被遍历了，也不遍历BD这条边，那么BD这条边就不会被记录，代码错误。
        ++en;
        if (visit_dfs[p->adjVex] == 0) {
            dfs(G, p->adjVex, vn, en);
        }
        p = p->nextNode;
    }
}

int GisTree(MyGraph *G) {
    int vn = 0;
    int en = 0;
    dfs(G, 0, vn, en);
    if (vn == G->n && (G->n - 1 == en / 2)) {
        return 1;
    } else {
        return 0;
    }
}
