/**
 * AOV���������򣩺�AOE�����ؼ�·����
 * ��ͬ�㣺���������޻�ͼ
 * ��ͬ�㣺AOV���Ķ����ʾ�������Ȩֵ���ߴ���֮����Ⱥ��ϵ��
 *        ������Ⱥͳ�����Ҫ��
 *        AOE���ı߱�ʾ�����Ȩֵ���߱�ʾ�����ʱ�䣻�����ʾ�¼����¼���ͼ���»��ʼ��ɻ�����ı�־��
 *        ����һ����ʾ���̵�AOE����ֻ����һ�����Ϊ0�Ķ��㣬��ΪԴ�㣬��ʾ�������̵Ŀ�ʼ��Ҳֻ����һ������Ϊ0�Ķ��㣬
 *        ��Ϊ��㣬��ʾ�������̵Ľ�����
 */
#include "AdjacencyListBasic.cpp"

//ͼ�Σ�
//      B_0
//   �J     �K
// A �� B_1 �� C
//  �K     �J
//    B_2
//����ͼAOV
//count ����Ϊ���
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
 * ��������
 * һ��ʵ�ַ�ʽ����
 * ʹ���ڽӱ�洢ʱ��ʱ�临�Ӷ�Ϊ ������Ĵ���+ɾ���ߵĴ��� ��Ϊ O(|V|+|E|)
 * �����ڽӾ���洢ʱ��ʱ�临�Ӷ�ΪO(|V|^2)
 * ��һ����dfs�ĳ�ջ˳��ȡ�棬ǰ������֪�޻�
 * @param g AOV��
 * @return �Ƿ�����ɹ� 1�ɹ� 0ʧ��
 */
int TopSort(MyGraph *g) {
    int i, j, n = 0;
    //���岢��ʼ��ջ ջ��װ��ȫ�����Ϊ0�Ľ��
    int stack[MAXSIZE], top = -1;
    ArcNode *p;
    //�����Ϊ0�ĵ�ȫ��ջ ��Ϊ���Ϊ0�����Ȼ
    for (i = 0; i < g->n; i++) {
        if (g->adjList[i].count == 0)
            stack[++top] = i;
    }
    while (top != -1) {
        i = stack[top--];
        ++n;
        cout << i << " ";
        p = g->adjList[i].firstArc;
        //�ҵ�����������ȥ�����бߵ���һ���˵㣬��Ⱦ�-1
        //�����һ���˵����ȱ��0�ˣ���˵������㲻���Ǳ�Ļ�ĺ���ˣ�������ˣ���ջ
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
    //���n != g->n ��˵���л�
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