#include "../AdjacencyListBasic.cpp"

//顶点标记 一定先初始化为0
int visit_dfs[MAXSIZE] = {0};
/**
 * 深度优先遍历
 * 递归算法
 * 以邻接表表示时，时间复杂度为 O(n + e) 为访问边数和访问顶点数之和。
 * 以邻接矩阵表示时，时间复杂度为 O(n^2) 为访问所有顶点次数之和。
 * 空间复杂度为 (n)
 * 它的出栈顺序和输出顺序是不一样的 对于有向无环图 出栈顺序是逆拓扑排序
 * @param G 由邻接表存储的连通（子）图 可有向可无向
 * @param v 最开始在第几个顶点遍历
 */
void DFS_Recurve(MyGraph *G, int v) {
    ArcNode *p;
    visit_dfs[v] = 1;
    cout << v << " ";
    p = G->adjList[v].firstArc;
    //类似二叉树前序遍历 不过二叉树是遍历两个分支 图是多个分支
    while (p != nullptr) {
        //如果这个边的另一个顶点还没有被遍历过 继续遍历
        //在无向图中 如果在深度遍历的过程中发现 visit_dfs[p->adjVex] == 1
        //那么这个 p->adjVex 已经被遍历过了，说明遍历序列在当前结点前的某结点到结点 p->adjVex 有路径
        //而当前结点到 p->adjVex 又存在一个边p 则说明构成一个回路
        //对于有向图和无向图检测成环的算法在CheckCircle.cpp中
        //bfs没有这个性质
        if (visit_dfs[p->adjVex] == 0) {
            DFS_Recurve(G, p->adjVex);
        }
        p = p->nextNode;
    }
}

/**
 * DFS的非递归算法 王道版
 * 非递归算法相对于递归算法，需要自己写一个递归栈，具体的操作，通过对比递归栈一个顶点的出栈和出栈来考虑
 * 出栈定义为该结点遍历完成且周围边都入栈了。入栈，应该是这个顶点没有被遍历，且在入栈时标记visit数组。
 * 由于使用了栈，使得遍历的方式从右到左进行，不同于常规的从左到右了，但仍然是深度遍历
 * @param g
 * @param v
 */
void DFS_NO_Recurve_1(MyGraph *g, int v) {
    int stack[MAXSIZE];
    int top = -1;
    stack[++top] = v;
    visit_dfs[v] = 1;
    while(top != -1) {
        int k = stack[top--];
        //对k结点做操作
        cout << k;
        //让结点w的周围结点依次入栈
        for (ArcNode *w = g->adjList[k].firstArc; w != nullptr; w = w->nextNode)
        {
            if (visit_dfs[w->adjVex] == 0)
            {
                stack[++top] = w->adjVex;
                visit_dfs[w->adjVex] = 1;
            }
        }
    }
    cout << endl;
}

/**
 * DFS的非递归算法 天勤版
 * 出栈，应该是这个顶点的所有边都被遍历完了。入栈，应该是这个顶点没有被遍历。且在入栈时标记visit数组，
 * 同时做输出或其它的访问操作。
 * @param g
 * @param v
 */
void DFS_NO_Recurve_2(MyGraph *g, int v) {
    int stack[MAXSIZE];
    int top = -1;
    stack[++top] = v;
    visit_dfs[v] = 1;
    cout << v << " ";
    while(top != -1) {
        //读取栈顶结点，不出栈
        int v0 = stack[top];
        //得到当前结点第一条没被访问过的边
        ArcNode *p = g->adjList[v0].firstArc;
        while (p != nullptr && visit_dfs[p->adjVex] == 1) {
            p = p->nextNode;
        }
        //如果这个结点所有边都被访问了，直接出栈。
        if (p == nullptr) {
            top--;
            continue;
        }
        //有没被访问的边，让这个边的另一端结点入栈，同时标记。下一次循环以这个结点为起始结点。
        stack[++top] = p->adjVex;
        visit_dfs[p->adjVex] = 1;
        cout << p->adjVex << " ";
    }
    cout << endl;
}

/**
 * 深度优先遍历
 * 因为DFS_Recurve是从某一个顶点ｖ开始的，是通过它的边“延申出去的”，可能以ｖ为中心的图链接不到顶点ｋ
 * 所以对于非连通图，需要对每个点做遍历
 * @param G 由邻接表存储的非连通图（连通图也行） 可有向可无向
 */
void dfs(MyGraph *G) {
    for (int i = 0; i < G->n; ++i) {
        //上一次dfs结束后仍没有遍历到
        if (visit_dfs[i] == 0) {
            DFS_Recurve(G, i);
        }
    }
}

int main() {
    MyGraph *G = initial_undigraph();
    DFS_NO_Recurve_1(G, 0);
}