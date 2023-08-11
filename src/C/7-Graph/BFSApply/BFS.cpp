#include "../AdjacencyListBasic.cpp"

//一定先初始化为0
int visit_bfs[MAXSIZE] = {0};
/**
 * 广度优先遍历 与层次遍历完全一样
 * 以邻接表表示时，时间复杂度为 O(n + e) 为访问边数和访问顶点数之和。
 * 以邻接矩阵表示时，时间复杂度为 O(n^2) 为访问所有顶点次数之和
 * @param G 由邻接表存储的连通图 可有向可无向
 * @param v 最开始在第几个顶点遍历
 */
void BFS(MyGraph *G, int v) {
    //存放结点的队列 初始化
    int visit[MAXSIZE];
    int bottom = -1;
    int top = -1;
    visit[++top % MAXSIZE] = v;

    visit_bfs[v] = 1;

    ArcNode *next;
    int p;
    while (bottom != top) {
        p = visit[++bottom % MAXSIZE];
        //do something
        cout << p << " ";
        next = G->adjList[p].firstArc;
        while (next != nullptr) {
            if (visit_bfs[next->adjVex] == 0) {
                //不像二叉树层次遍历，这里需要在入队时就标记已读，而不是出队，否则会出现这种情况：
                //y、x2都是x1的邻居，且y也是x2的邻居。y在x1结点出队时入队，但x2比y先入队，x2访问周围结点时，
                //如果没有标记，y又会再次入队。
                //跟二叉树的不同是，二叉树一个儿子只能有一个爹，而图是多对多，且是平等关系（无向图）。
                visit_bfs[next->adjVex] = 1;
                visit[++top % MAXSIZE] = next->adjVex;
            }
            next = next->nextNode;
        }
    }
}

/**
 * 广度优先遍历
 * 因为bfs是从某一个顶点ｖ开始的，是通过它的边“延申出去的”，可能以ｖ为中心的图链接不到顶点ｋ
 * 所以对于非连通图，需要对每个点做遍历
 * 对于无向图，调用BFS(G, i)的次数等于该图的连通分量数。而对于有向图则不是这样，因为连通图也分强连通和非强连通。
 * 如 A → B → C 有3个强连通分量
 * @param G 由邻接表存储的非连通图（连通图也行） 可有向可无向
 */
void bfs(MyGraph *G) {
    for (int i = 0; i < G->n; ++i) {
        if (visit_bfs[i] == 0) {
            BFS(G, i);
        }
    }
}

