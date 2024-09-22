/**
 * 假设图用邻接表表示，设计一个算法，输出从顶点Vi到顶点Vj的所有简单路径
 * 所有，所以不用剪枝
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
        //回溯dfs_visit数组的状态
        //因为最终输出的路径由d决定，所以不需要回溯数组元素
        //且d和u都是局部变量，不需要回溯
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