#include "../AdjacencyListBasic.cpp"

//һ���ȳ�ʼ��Ϊ0
int visit_bfs[MAXSIZE] = {0};
/**
 * ������ȱ��� ���α�����ȫһ��
 * ���ڽӱ��ʾʱ��ʱ�临�Ӷ�Ϊ O(n + e) Ϊ���ʱ����ͷ��ʶ�����֮�͡�
 * ���ڽӾ����ʾʱ��ʱ�临�Ӷ�Ϊ O(n^2) Ϊ�������ж������֮��
 * @param G ���ڽӱ�洢����ͨͼ �����������
 * @param v �ʼ�ڵڼ����������
 */
void BFS(MyGraph *G, int v) {
    //��Ž��Ķ��� ��ʼ��
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
                //�����������α�����������Ҫ�����ʱ�ͱ���Ѷ��������ǳ��ӣ������������������
                //y��x2����x1���ھӣ���yҲ��x2���ھӡ�y��x1������ʱ��ӣ���x2��y����ӣ�x2������Χ���ʱ��
                //���û�б�ǣ�y�ֻ��ٴ���ӡ�
                //���������Ĳ�ͬ�ǣ�������һ������ֻ����һ��������ͼ�Ƕ�Զ࣬����ƽ�ȹ�ϵ������ͼ����
                visit_bfs[next->adjVex] = 1;
                visit[++top % MAXSIZE] = next->adjVex;
            }
            next = next->nextNode;
        }
    }
}

/**
 * ������ȱ���
 * ��Ϊbfs�Ǵ�ĳһ���������ʼ�ģ���ͨ�����ıߡ������ȥ�ġ��������ԣ�Ϊ���ĵ�ͼ���Ӳ��������
 * ���Զ��ڷ���ͨͼ����Ҫ��ÿ����������
 * ��������ͼ������BFS(G, i)�Ĵ������ڸ�ͼ����ͨ������������������ͼ������������Ϊ��ͨͼҲ��ǿ��ͨ�ͷ�ǿ��ͨ��
 * �� A �� B �� C ��3��ǿ��ͨ����
 * @param G ���ڽӱ�洢�ķ���ͨͼ����ͨͼҲ�У� �����������
 */
void bfs(MyGraph *G) {
    for (int i = 0; i < G->n; ++i) {
        if (visit_bfs[i] == 0) {
            BFS(G, i);
        }
    }
}

