#include "../AdjacencyListBasic.cpp"

//一定先初始化为0
int visit_bfs[MAXSIZE] = {0};
/**
 * 求各点距离顶点v的层数 并返回最远的那个结点
 * 当各边上权值相等时 也可以用来求单源最短路径问题 即各点到v的距离层数 单源最短路径
 * @param G 无向连通图
 * @param v 顶点v的编号
 */
int bfs(MyGraph *G, int v, int array[MAXSIZE]) {
    int visit[MAXSIZE];
    int bottom = -1;
    int top = -1;
    visit[++top % MAXSIZE] = v;
    visit_bfs[v] = 1;
    array[v] = 0;
    ArcNode *next;
    int p;
    while (bottom != top) {
        p = visit[++bottom % MAXSIZE];
        next = G->adjList[p].firstArc;
        while (next != nullptr) {
            if (visit_bfs[next->adjVex] == 0) {
                visit_bfs[next->adjVex] = 1;
                visit[++top % MAXSIZE] = next->adjVex;
                array[next->adjVex] = array[p] + 1;
            }
            next = next->nextNode;
        }
    }
    return p;
}

int main() {
    MyGraph *G = initial_undigraph();
    int array[MAXSIZE];
    int v = 1;
    int x = bfs(G, v, array);
    for (int i = 0; i < G->n; ++i) {
        cout << "结点" << i + 1 << "距离结点" << v << "的距离为：" << array[i] << endl;
    }
    cout << "距离结点" << v << "最远的结点为：" << x + 1 << endl;
}