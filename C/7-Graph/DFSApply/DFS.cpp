#include "../AdjacencyListBasic.cpp"

//������ һ���ȳ�ʼ��Ϊ0
int visit_dfs[MAXSIZE] = {0};
/**
 * ������ȱ���
 * �ݹ��㷨
 * ���ڽӱ��ʾʱ��ʱ�临�Ӷ�Ϊ O(n + e) Ϊ���ʱ����ͷ��ʶ�����֮�͡�
 * ���ڽӾ����ʾʱ��ʱ�临�Ӷ�Ϊ O(n^2) Ϊ�������ж������֮�͡�
 * �ռ临�Ӷ�Ϊ (n)
 * ���ĳ�ջ˳������˳���ǲ�һ���� ���������޻�ͼ ��ջ˳��������������
 * @param G ���ڽӱ�洢����ͨ���ӣ�ͼ �����������
 * @param v �ʼ�ڵڼ����������
 */
void DFS_Recurve(MyGraph *G, int v) {
    ArcNode *p;
    visit_dfs[v] = 1;
    cout << v << " ";
    p = G->adjList[v].firstArc;
    //���ƶ�����ǰ����� �����������Ǳ���������֧ ͼ�Ƕ����֧
    while (p != nullptr) {
        //�������ߵ���һ�����㻹û�б������� ��������
        //������ͼ�� �������ȱ����Ĺ����з��� visit_dfs[p->adjVex] == 1
        //��ô��� p->adjVex �Ѿ����������ˣ�˵�����������ڵ�ǰ���ǰ��ĳ��㵽��� p->adjVex ��·��
        //����ǰ��㵽 p->adjVex �ִ���һ����p ��˵������һ����·
        //��������ͼ������ͼ���ɻ����㷨��CheckCircle.cpp��
        //bfsû���������
        if (visit_dfs[p->adjVex] == 0) {
            DFS_Recurve(G, p->adjVex);
        }
        p = p->nextNode;
    }
}

/**
 * DFS�ķǵݹ��㷨 ������
 * �ǵݹ��㷨����ڵݹ��㷨����Ҫ�Լ�дһ���ݹ�ջ������Ĳ�����ͨ���Աȵݹ�ջһ������ĳ�ջ�ͳ�ջ������
 * ��ջ����Ϊ�ý������������Χ�߶���ջ�ˡ���ջ��Ӧ�����������û�б�������������ջʱ���visit���顣
 * ����ʹ����ջ��ʹ�ñ����ķ�ʽ���ҵ�����У���ͬ�ڳ���Ĵ������ˣ�����Ȼ����ȱ���
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
        //��k���������
        cout << k;
        //�ý��w����Χ���������ջ
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
 * DFS�ķǵݹ��㷨 ���ڰ�
 * ��ջ��Ӧ���������������б߶����������ˡ���ջ��Ӧ�����������û�б�������������ջʱ���visit���飬
 * ͬʱ������������ķ��ʲ�����
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
        //��ȡջ����㣬����ջ
        int v0 = stack[top];
        //�õ���ǰ����һ��û�����ʹ��ı�
        ArcNode *p = g->adjList[v0].firstArc;
        while (p != nullptr && visit_dfs[p->adjVex] == 1) {
            p = p->nextNode;
        }
        //������������б߶��������ˣ�ֱ�ӳ�ջ��
        if (p == nullptr) {
            top--;
            continue;
        }
        //��û�����ʵıߣ�������ߵ���һ�˽����ջ��ͬʱ��ǡ���һ��ѭ����������Ϊ��ʼ��㡣
        stack[++top] = p->adjVex;
        visit_dfs[p->adjVex] = 1;
        cout << p->adjVex << " ";
    }
    cout << endl;
}

/**
 * ������ȱ���
 * ��ΪDFS_Recurve�Ǵ�ĳһ���������ʼ�ģ���ͨ�����ıߡ������ȥ�ġ��������ԣ�Ϊ���ĵ�ͼ���Ӳ��������
 * ���Զ��ڷ���ͨͼ����Ҫ��ÿ����������
 * @param G ���ڽӱ�洢�ķ���ͨͼ����ͨͼҲ�У� �����������
 */
void dfs(MyGraph *G) {
    for (int i = 0; i < G->n; ++i) {
        //��һ��dfs��������û�б�����
        if (visit_dfs[i] == 0) {
            DFS_Recurve(G, i);
        }
    }
}

int main() {
    MyGraph *G = initial_undigraph();
    DFS_NO_Recurve_1(G, 0);
}