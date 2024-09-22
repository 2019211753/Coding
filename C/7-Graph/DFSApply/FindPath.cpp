/**
 * ����ͼ���ڽӱ��ʾ�����һ���㷨������Ӷ���Vi������Vj�����м�·��
 * ���У����Բ��ü�֦
 */
#include "../AdjacencyListBasic.cpp"

int path[MAXSIZE] = {0};
int dfs_visit[MAXSIZE] = {0};

void findPath(MyGraph *g, int u, int v, int d)
{
    if (u != v)
    {
        dfs_visit[u] = 1;
        path[d] = u;
        ArcNode *arc = g->adjList[u].firstArc;
        while (arc != nullptr)
        {
            if (dfs_visit[arc->adjVex] == 0)
            {
                findPath(g, arc->adjVex, v, d+1);
            }
            arc = arc->nextNode;
        }
        //����dfs_visit�����״̬
        //��Ϊ���������·����d���������Բ���Ҫ��������Ԫ��
        //��d��u���Ǿֲ�����������Ҫ����
        dfs_visit[u] = 0;
    } else {
        for (int i = 0; i < d; i++)
        {
            cout << path[i] << " ";
        }
        cout << v << endl;
        return;
    }
}

int main() {
    MyGraph *G = initial_undigraph();
    findPath(G, 0, 4, 0);
}