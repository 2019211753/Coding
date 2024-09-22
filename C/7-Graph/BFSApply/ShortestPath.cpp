#include "../AdjacencyListBasic.cpp"

//һ���ȳ�ʼ��Ϊ0
int visit_bfs[MAXSIZE] = {0};
/**
 * �������붥��v�Ĳ��� ��������Զ���Ǹ����
 * ��������Ȩֵ���ʱ Ҳ����������Դ���·������ �����㵽v�ľ������ ��Դ���·��
 * @param G ������ͨͼ
 * @param v ����v�ı��
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
        cout << "���" << i + 1 << "������" << v << "�ľ���Ϊ��" << array[i] << endl;
    }
    cout << "������" << v << "��Զ�Ľ��Ϊ��" << x + 1 << endl;
}