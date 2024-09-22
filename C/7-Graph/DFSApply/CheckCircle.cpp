#include "../AdjacencyListBasic.cpp"

//������ һ���ȳ�ʼ��Ϊ0
int visit_dfs[MAXSIZE] = {0};
//��¼���ĸ��ӹ�ϵ
int visit[MAXSIZE] = {0};
/**
 * ����ͼ���ɻ�
 * ������ģ���������ͼ���������·��������һ������Ҳ������һ��˫��ߣ���a��b��a
 * ���������ͼ������ͼ��һ�����������߽���ʾ�����ڽӱ��е�������ba��ab
 * Ϊ���˵�˫��ߣ�����������һ��visit[]���飬�ڽ�� i ��ȱ���ʱ������ֱ���ڽӵĵ���Ϊ i + 1
 * ��������ȱ���ʱ������� visit_dfs[p->adjVex] == 1 ����visit[v]  == visit[p->adjVex] + 1 �Ƿ��������
 * �������˵�� v �� p->adjVex �������һ��˫��ߣ������ǻ���
 * @param G �ڽӱ�洢������ͼ
 * @param v ����һ������
 * @return �Ƿ�ɻ��� trueΪ���ɻ���falseΪ�ɻ�
 */
bool check_Undirected_Graph_Circle(MyGraph *G, int v) {
    //�����֦
    bool flag;
    ArcNode *p;
    visit_dfs[v] = 1;
    cout << v << endl;
    p = G->adjList[v].firstArc;
    while (p != nullptr) {
        //��� v �ı���û�������������Ժ���ܻ�������
        //��������Ҫ������һ����false�źţ���ֹ v �ı����������ظ���һ������ֹ��һ������
        if (visit_dfs[p->adjVex] == 0) {
            visit[p->adjVex] = visit[v] + 1;
            flag = check_Undirected_Graph_Circle(G, p->adjVex);
            //��֮��return flag����ôֱ����ֹ�ˣ���trueҲ���ܼ��������ˡ�
            if (!flag) {
                return false;
            }
            //������ v �ı����������ˣ�����false������ֹv�ı���
        } else if (visit_dfs[p->adjVex] != 0 && visit[p->adjVex] + 1 != visit[v]) {
            return false;
        }
        p = p->nextNode;
    }
    //��û�л� �ͷ���true
    return true;
}

/**
 * ����ͼ���ɻ�
 * ������ģ���������ͼ���������·��������һ������Ҳ������ָ����һ�����ϵĶ���ıߣ���
 *       1
 *    �L  �K
 *  2 �� �� �� 3
 * ����Ӧ���ڱ�����һ����������������ϵĺۼ���
 * ����ۼ���3���ỹ������2�𣿲��������ѭ����
 * ���ᣬ3�����󵽱���2��Ȼ��ͼ�������2���ӽ�㣬������ͽ����ˣ�
 * ��Ȼ���������ܻ�����ɶ�2�ӽ�������������������ܿ�������һ�����飬��ʾĳ�㱻�������ˣ��Ӷ���֦��
 * @param G �ڽӱ�洢������ͼ
 * @param v ����һ������
 * @return �Ƿ�ɻ��� trueΪ���ɻ���falseΪ�ɻ�
 */
bool check_directed_Graph_Circle(MyGraph *G, int v) {
    bool flag;
    ArcNode *p;
    visit_dfs[v] = 1;
    cout << v << endl;
    p = G->adjList[v].firstArc;
    while (p != nullptr) {
        if (visit_dfs[p->adjVex] == 0) {
            flag = check_directed_Graph_Circle(G, p->adjVex);
            if (!flag) {
                return false;
            }
        } else {
            return false;
        }
        //���������ĺۼ�
        visit_dfs[p->adjVex] = 0;
        p = p->nextNode;
    }
    //��û�л� �ͷ���true
    return true;
}

int main()
{
    MyGraph *g = initial_digraph();
    cout << check_directed_Graph_Circle(g, 0);
}