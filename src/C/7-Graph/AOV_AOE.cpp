/**
 * AOV（拓扑排序）和AOE网（关键路径）
 * 共同点：都是有向无环图
 * 不同点：AOV网的顶点表示活动，边无权值，边代表活动之间的先后关系。
 *        对于入度和出度无要求。
 *        AOE网的边表示活动，有权值，边表示活动持续时间；顶点表示事件，事件是图中新活动开始或旧活动结束的标志。
 *        对于一个表示工程的AOE网，只存在一个入度为0的顶点，称为源点，表示整个工程的开始；也只存在一个出度为0的顶点，
 *        称为汇点，表示整个工程的结束。
 */
#include "AdjacencyListBasic.cpp"

//图形：
//      B_0
//   ↗     ↘
// A → B_1 → C
//  ↘     ↗
//    B_2
//有向图AOV
//count 定义为入度
MyGraph* initial_AOV() {
    auto *graph = (MyGraph*) malloc(sizeof (MyGraph));
    auto *AB0 = (ArcNode*) malloc(sizeof (ArcNode));
    AB0->adjVex = 1;
    AB0->nextNode = nullptr;
    auto *AB1 = (ArcNode*) malloc(sizeof (ArcNode));
    AB1->adjVex = 2;
    AB1->nextNode = nullptr;
    auto *AB2 = (ArcNode*) malloc(sizeof (ArcNode));
    AB2->adjVex = 3;
    AB2->nextNode = nullptr;
    auto *BC0 = (ArcNode*) malloc(sizeof (ArcNode));
    BC0->adjVex = 4;
    BC0->nextNode = nullptr;
    auto *BC1 = (ArcNode*) malloc(sizeof (ArcNode));
    BC1->adjVex = 4;
    BC1->nextNode = nullptr;
    auto *BC2 = (ArcNode*) malloc(sizeof (ArcNode));
    BC2->adjVex = 4;
    BC2->nextNode = nullptr;

    AB0->nextNode = AB1;
    AB1->nextNode = AB2;

    Vnode A;
    A.firstArc = AB0;
    A.count = 0;
    Vnode B_0;
    B_0.firstArc = BC0;
    B_0.count = 1;
    Vnode B_1;
    B_1.firstArc = BC1;
    B_1.count = 1;
    Vnode B_2;
    B_2.firstArc = BC2;
    B_2.count = 1;
    Vnode C;
    C.firstArc = nullptr;
    C.count = 3;

    graph->adjList[0] = A;
    graph->adjList[1] = B_0;
    graph->adjList[2] = B_1;
    graph->adjList[3] = B_2;
    graph->adjList[4] = C;

    graph->n = 5;
    graph->e = 6;

    return graph;
}

/**
 * 拓扑排序
 * 一种实现方式如下
 * 使用邻接表存储时的时间复杂度为 输出结点的次数+删除边的次数 故为 O(|V|+|E|)
 * 采用邻接矩阵存储时的时间复杂度为O(|V|^2)
 * 另一种是dfs的出栈顺序取逆，前提是已知无环
 * @param g AOV网
 * @return 是否排序成功 1成功 0失败
 */
int TopSort(MyGraph *g) {
    int i, j, n = 0;
    //定义并初始化栈 栈里装的全是入度为0的结点
    int stack[MAXSIZE], top = -1;
    ArcNode *p;
    //将入度为0的点全入栈 因为入度为0则最先活动
    for (i = 0; i < g->n; i++) {
        if (g->adjList[i].count == 0)
            stack[++top] = i;
    }
    while (top != -1) {
        i = stack[top--];
        ++n;
        cout << i << " ";
        p = g->adjList[i].firstArc;
        //找到这个点延伸出去的所有边的另一个端点，入度均-1
        //如果另一个端点的入度变成0了，则说明这个点不再是别的活动的后继了，该输出了，入栈
        while (p != nullptr) {
            j = p->adjVex;
            --(g->adjList[j].count);
            if (g->adjList[j].count == 0) {
                stack[++top] = j;
            }
            p = p->nextNode;
        }
    }
    cout << endl;
    //如果n != g->n 则说明有环
    if (n == g->n) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    MyGraph *g = initial_AOV();
    cout << TopSort(g) << endl;
}