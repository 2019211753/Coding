#include "../AdjacencyListBasic.cpp"

//顶点标记 一定先初始化为0
int visit_dfs[MAXSIZE] = {0};
//记录结点的父子关系
int visit[MAXSIZE] = {0};
/**
 * 无向图检测成环
 * 书接上文，对于无向图，这个“回路”可能是一个环，也可能是一个双向边，即a→b→a
 * 相比于有向图，无向图中一个边由两个边结点表示，如邻接表中的两条边ba和ab
 * 为了滤掉双向边，这里可以添加一个visit[]数组，在结点 i 深度遍历时，与它直接邻接的点标记为 i + 1
 * 这样当深度遍历时如果遇到 visit_dfs[p->adjVex] == 1 看看visit[v]  == visit[p->adjVex] + 1 是否成立即可
 * 如果成立说明 v 是 p->adjVex 的子孙，是一个双向边，不算是环。
 * @param G 邻接表存储的无向图
 * @param v 任意一个顶点
 * @return 是否成环了 true为不成环，false为成环
 */
bool check_Undirected_Graph_Circle(MyGraph *G, int v) {
    //方便剪枝
    bool flag;
    ArcNode *p;
    visit_dfs[v] = 1;
    cout << v << endl;
    p = G->adjList[v].firstArc;
    while (p != nullptr) {
        //结点 v 的遍历没遇到环，但是以后可能会遇到环
        //所以这里要接受下一级的false信号，终止 v 的遍历，并返回给上一级，终止上一级遍历
        if (visit_dfs[p->adjVex] == 0) {
            visit[p->adjVex] = visit[v] + 1;
            flag = check_Undirected_Graph_Circle(G, p->adjVex);
            //别之间return flag，那么直接终止了，是true也不能继续运行了。
            if (!flag) {
                return false;
            }
            //如果结点 v 的遍历遇到环了，返回false，且终止v的遍历
        } else if (visit_dfs[p->adjVex] != 0 && visit[p->adjVex] + 1 != visit[v]) {
            return false;
        }
        p = p->nextNode;
    }
    //都没有环 就返回true
    return true;
}

/**
 * 有向图检测成环
 * 书接上文，对于有向图，这个“回路”可能是一个环，也可能是指向另一棵树上的顶点的边，如
 *       1
 *    ↙  ↘
 *  2 ← ← ← 3
 * 所以应该在遍历完一颗子树后清除子树上的痕迹。
 * 清除痕迹后，3不会还遍历到2吗？不会造成死循环吗？
 * 不会，3遍历后到遍历2，然后就继续遍历2的子结点，遍历完就结束了，
 * 当然，这样可能会多次造成对2子结点遍历的冗余操作，可能可以另作一个数组，表示某点被遍历过了，从而剪枝。
 * @param G 邻接表存储的有向图
 * @param v 任意一个顶点
 * @return 是否成环了 true为不成环，false为成环
 */
bool check_directed_Graph_Circle(MyGraph *G, int v) {
    bool flag;
    ArcNode *p;
    visit_dfs[v] = 1;
    cout << v << endl;
    p = G->adjList[v].firstArc;
    while (p != nullptr) {
        if (visit_dfs[p->adjVex] == 0) {
            flag = check_directed_Graph_Circle(G, p->adjVex);
            if (!flag) {
                return false;
            }
        } else {
            return false;
        }
        //清除这棵树的痕迹
        visit_dfs[p->adjVex] = 0;
        p = p->nextNode;
    }
    //都没有环 就返回true
    return true;
}

int main()
{
    MyGraph *g = initial_digraph();
    cout << check_directed_Graph_Circle(g, 0);
}