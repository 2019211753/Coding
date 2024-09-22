/**
 * �ڽӱ�洢��ͼ�Ľṹ
 */
#include "iostream"

#define MAXSIZE 100
#define INF 100000


using namespace std;

//�߽��
typedef struct ArcNode
{
    //�ñ���ָ��Ľ���λ��
    int adjVex;
    //ָ����һ���ߵ�ָ��
    struct ArcNode *nextNode;
    //�ߵ������Ϣ ��Ȩֵ
    //int info;
}ArcNode;

//������ Ҳ�洢����ĵ�һ����
typedef struct Vnode {
    //������Ϣ
    int count;
    //ָ���һ���ߵ�ָ��
    ArcNode *firstArc;
}Vnode;

typedef struct MyGraph {
    //�ڽӱ� �洢����
    Vnode adjList[MAXSIZE];
    //������
    int n;
    //����
    int e;
} MyGraph;

//����ͼ
//ͼ�Σ�
//    A  ���� B
//    | \
//    |  C
//    | /
//    D ���� E
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

//����ͼ
//ͼ�Σ�
//    A  ���� B
//    | �K
//    |   C
//    �� �L
//    D ���� E
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

//���ڽӱ�ת�����ڽӾ���
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


