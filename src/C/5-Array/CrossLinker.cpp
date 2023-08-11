//十字链表的初始化
//十字链表有两种结点 一种是头结点 一种是普通结点
//普通结点的数变量包括行号、列号和在该位置上的值，指针变量包括指向它下面的结点和右边的结点
//头结点的数变量包括整个二维矩阵的维度和非0个数，指针变量包括两个数组，分别代表矩阵横纵第i个行（列），
//这里的横纵指针是数组 而不是链表了
#include "iostream"

using namespace std;

#define endl '\n'
#define MAXSIZE 4

typedef struct OLNode {
    float val;
    int row;
    int col;
    OLNode* right;
    OLNode* down;
} OLNode;

typedef struct {
    OLNode* rHead;
    OLNode* cHead;
    int rows;
    int cols;
    int nzs;
} CrossList;

int createCrossListMat(float A[][MAXSIZE], int rows, int cols, int nzs, CrossList &l) {
    if (l.rHead) {
        free(l.rHead);
    }
    if (l.cHead) {
        free(l.cHead);
    }
    l.rows = rows;
    l.cols = cols;
    l.nzs = nzs;
    /*申请头结点数组空间*/
    if (!(l.rHead = (OLNode*) malloc(sizeof (OLNode) * rows))) {
        return 0;
    }
    if (!(l.cHead = (OLNode*) malloc(sizeof (OLNode) * cols))) {
        return 0;
    }
    /*头结点数组right和down置null*/
    for (int i = 0; i < rows; ++i) {
        l.rHead[i].right = nullptr;
        l.rHead[i].down = nullptr;
    }
    for (int i = 0; i < cols; ++i) {
        l.cHead[i].right = nullptr;
        l.cHead[i].down = nullptr;
    }
    /*建立列链表的辅助指针数组*/
    OLNode* temps[MAXSIZE];
    for (int i = 0; i < cols; ++i) {
        temps[i] = &(l.cHead[i]);
    }
    for (int i = 0; i < rows; ++i) {
        OLNode* r = &(l.rHead[i]);
        for (int j = 0; j < cols; ++j) {
            if (A[i][j] != 0) {
                OLNode* p = (OLNode*) malloc(sizeof (OLNode));
                p->row = i;
                p->col = j;
                p->val = A[i][j];
                p->down = nullptr;
                p->right = nullptr;
                r->right = p;
                r = p;
                temps[j]->down = p;
                temps[j] = p;
            }
        }
    }
    return 1;
}

int main() {
    float array[3][4] = {{1, 3, 5, 7}, {2, 4, 6, 8}, {11, 12, 13, 1}};
    CrossList crossList;
    crossList.rHead = nullptr;
    crossList.cHead = nullptr;
    createCrossListMat(array, 3, 4, 12, crossList);
    int a = 1;
    printf("%d", a);
}