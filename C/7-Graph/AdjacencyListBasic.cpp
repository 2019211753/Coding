/**
 * 邻接表存储的图的结构
 */
#include "iostream"

#define MAXSIZE 100
#define INF 100000


using namespace std;

//边结点
typedef struct ArcNode
{
    //该边所指向的结点的位置
    int adjVex;
    //指向下一条边的指针
    struct ArcNode *nextNode;
    //边的相关信息 如权值
    //int info;
}ArcNode;

//顶点结点 也存储顶点的第一条边
typedef struct Vnode {
    //顶点信息
    int count;
    //指向第一条边的指针
    ArcNode *firstArc;
}Vnode;

typedef struct MyGraph {
    //邻接表 存储顶点
    Vnode adjList[MAXSIZE];
    //顶点数
    int n;
    //边数
    int e;
} MyGraph;

//无向图
//图形：
//    A  —— B
//    | \
//    |  C
//    | /
//    D —— E
MyGraph* initial_undigraph() {
    auto *graph = (MyGraph*) malloc(sizeof (MyGraph));
    auto *AB = (ArcNode*) malloc(sizeof (ArcNode));
    AB->adjVex = 1;
    AB->nextNode = nullptr;
    auto *AC = (ArcNode*) malloc(sizeof (ArcNode));
    AC->adjVex = 2;
    AC->nextNode = nullptr;
    auto *AD = (ArcNode*) malloc(sizeof (ArcNode));
    AD->adjVex = 3;
    AD->nextNode = nullptr;
    auto *CD = (ArcNode*) malloc(sizeof (ArcNode));
    CD->adjVex = 3;
    CD->nextNode = nullptr;
    auto *DE = (ArcNode*) malloc(sizeof (ArcNode));
    DE->adjVex = 4;
    DE->nextNode = nullptr;

    auto *BA = (ArcNode*) malloc(sizeof (ArcNode));
    BA->adjVex = 0;
    BA->nextNode = nullptr;
    auto *CA = (ArcNode*) malloc(sizeof (ArcNode));
    CA->adjVex = 0;
    CA->nextNode = nullptr;
    auto *DA = (ArcNode*) malloc(sizeof (ArcNode));
    DA->adjVex = 0;
    DA->nextNode = nullptr;
    auto *DC = (ArcNode*) malloc(sizeof (ArcNode));
    DC->adjVex = 2;
    DC->nextNode = nullptr;
    auto *ED = (ArcNode*) malloc(sizeof (ArcNode));
    ED->adjVex = 3;
    ED->nextNode = nullptr;

    AB->nextNode = AC;
    AC->nextNode = AD;
    CA->nextNode = CD;
    DA->nextNode = DC;
    DC->nextNode = DE;

    Vnode A;
    A.firstArc = AB;
    Vnode B;
    B.firstArc = BA;
    Vnode C;
    C.firstArc = CA;
    Vnode D;
    D.firstArc = DA;
    Vnode E;
    E.firstArc = ED;

    graph->adjList[0] = A;
    graph->adjList[1] = B;
    graph->adjList[2] = C;
    graph->adjList[3] = D;
    graph->adjList[4] = E;

    graph->n = 5;
    graph->e = 10;

    return graph;
}

//有向图
//图形：
//    A  —→ B
//    | ↘
//    |   C
//    ↓ ↙
//    D —→ E
MyGraph* initial_digraph() {
    auto *graph = (MyGraph*) malloc(sizeof (MyGraph));
    auto *AB = (ArcNode*) malloc(sizeof (ArcNode));
    AB->adjVex = 1;
    AB->nextNode = nullptr;
    auto *AC = (ArcNode*) malloc(sizeof (ArcNode));
    AC->adjVex = 2;
    AC->nextNode = nullptr;
    auto *AD = (ArcNode*) malloc(sizeof (ArcNode));
    AD->adjVex = 3;
    AD->nextNode = nullptr;
    auto *CD = (ArcNode*) malloc(sizeof (ArcNode));
    CD->adjVex = 3;
    CD->nextNode = nullptr;
    auto *DE = (ArcNode*) malloc(sizeof (ArcNode));
    DE->adjVex = 4;
    DE->nextNode = nullptr;

    auto *BC = (ArcNode*) malloc(sizeof (ArcNode));
    BC->adjVex = 2;
    BC->nextNode = nullptr;

    AB->nextNode = AC;
    AC->nextNode = AD;

    Vnode A;
    A.firstArc = AB;
    Vnode B;
    B.firstArc = BC;
    Vnode C;
    C.firstArc = CD;
    Vnode D;
    D.firstArc = DE;
    Vnode E;
    E.firstArc = nullptr;

    graph->adjList[0] = A;
    graph->adjList[1] = B;
    graph->adjList[2] = C;
    graph->adjList[3] = D;
    graph->adjList[4] = E;

    graph->n = 5;
    graph->e = 6;

    return graph;
}

//将邻接表转换成邻接矩阵
int** convertListToMatrix(MyGraph *g)
{
    int **matrix = (int **)malloc(g->n * sizeof(int *));
    for (int i = 0; i < g->n; ++i) {
        matrix[i][i] = 0;
        for (int j = i + 1; j < g->n; ++j) {
            matrix[i][j] = INF;
        }
    }
    for (int i = 0; i < g->n; ++i) {
        ArcNode *arc = g->adjList[i].firstArc;
        while (arc != nullptr) {
            int k = arc->adjVex;
            matrix[i][k] = 1;
            matrix[k][i] = 1;
            arc = arc->nextNode;
        }
    }
    return matrix;
}


