/**
 * 最短路径算法（用于带权图，无所谓有向无向）
 * 最短路径算法通常依赖于一种性质，即两点之间的最短路径也包含了路径上其它顶点间的最短路径，也即基于贪心策略
*/
#include "AdjacencyMatrixBasic.cpp"

int dist[MAXSIZE];
int path[MAXSIZE];

/**
 * 输出路径 双亲表示法只能直接输出叶子结点到根结点 故通过栈逆序
 * @param path path[i]记录结点v到其它结点i的路径上除结点i外的最后一个结点序号 以双亲存储方式存储的
 * @param a 结点i的序号
 */
void printfPath(int path[], int a) {
    int stack[MAXSIZE], top = -1;
    //把父结点（在结点a之前的结点）都加入栈
    while (path[a] != -1) {
        stack[++top] = a;
        a = path[a];
    }
    //最后加入path[a] = -1的a 即根结点 起始节点v
    stack[++top] = a;
    while (top != -1) {
        cout << stack[top--] << " ";
    }
    cout <<endl;
}

/**
 * 迪杰斯特拉算法 可适用于有回路的带权图
 * 求图中某一顶点到其余各顶点的最短路径（单源最短路径），没办法单独求两点的最短路径。
 * 使用邻接矩阵表示时，时间复杂度为O(|V|^2)，使用带权的邻接表表示时，虽然修改dist[]的时间可以减少，
 * 但是由于在dist[]中选择最小分量的时间不变，时间复杂度仍为O(|V|^2)
 * 并且当只想找到两点间最短路径时，这个算法复杂度也为O(|V|^2)
 * 如果对对每个节点都运行一次（所有边权值非负），则可得到每对顶点之间的最短路径。时间复杂度为O(|V|^3)
 * 如果边上有负权值，迪杰斯特拉不适用，因为添加负权值边到集合中可能导致之前已经添加了的最短路径变得更短，而
 * 迪杰斯特拉没有更新之前路径的功能。
 * @param g 图
 * @param v 起始节点v的序号
 * @param dist dist[i]记录结点v到其它结点i的最短路径长度
 * @param path path[i]记录结点v到其它结点i的路径上 除结点i外的最后一个结点序号
 */
void Dijkstra(MyGraph g, int v, int dist[], int path[]) {
    //记录结点i的最短路径是不是已经求完了
    int set[MAXSIZE];
    int min, i, j, u;
    //初始化 与结点v邻接的结点的路径前继结点均为结点v 否则为-1
    for (i = 0; i < g.n; i++) {
        dist[i] = g.edges[v][i];
        set[i] = 0;
        if (g.edges[v][i] < INF) {
            path[i] = v;
        } else {
            path[i] = -1;
        }
    }
    //关于结点v的初始化
    set[v] = 1;
    path[v] = -1;
    dist[v] = 0;
    //找到当前与结点v最近的一个结点
    //当前找到的v-u的路径 即为v通过当前加入到路径的点到达u的最短路径
    //如果能通过后续得到的结点k对u形成新的路径 那么新路径长度为(v, k) + (k, u)
    //但已知(v, u)在上一次比较就小于(v, k)了 所以当前这个路径就是最短路径
    //找与其它n - 1个结点的最短路径就行了
    for (i = 0; i < g.n - 1; i++) {
        min = INF;
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        //若结点v的出度为0 退出程序 否则set[u]会溢出
        if (min == INF) {
            return;
        }
        set[u] = 1;
        //新加入一个结点后，对其它没有构成最短路径的结点更新
        for (j = 0; j < g.n; j++) {
            if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
                //当前v-j的最短路径的前驱结点为u
                path[j] = u;
            }
        }
    }
}

/*************************************************/
int A[MAXSIZE][MAXSIZE];
int Path[MAXSIZE][MAXSIZE];

/**
 * 输出u-v的路径
 * @param u 起始结点的序号
 * @param v 终止结点的序号
 * @param path 路径矩阵 path[i][j]存储结点i到结点j路径的中间点
 * @param A 最短路径长度矩阵
 */
void printfPath(int u, int v, int path[][MAXSIZE], int A[][MAXSIZE]) {
     //如果有路径
     if (A[u][v] != INF) {
        //这里只输出左端点 v结点在外部输出
        //因为如果 cout << u << " " << v 的话 1 2 3的路径输出结果为 1 22 3 即2作为中间点输出了两次
        if (path[u][v] == -1)
        {
            cout << u << " ";
        } else {
            //中间点
            int mid = path[u][v];
            //处理前半段路径
            printfPath(u, mid, path, A);
            //处理后半段路径
            printfPath(mid, v, path, A);
        }
    } else {
        cout << endl;
    }
}

/**
 * 弗洛伊德算法
 * 求图中任意一对顶点间的最短路径和长度
 * 计算 A[i][j] 时，原本的 A[i][j] 与 A[i][k] + A[k][j] 比较
 * 手动做时，每次以第 i 个（从0开始）为中间点时，第i列和第i行的数不变，因为
 * A[i][j] == A[i][i] + A[i][j],  A[j][i] = A[j][i] + A[i][i]
 * 时间复杂度为O(|V|^3)。
 * Floyd算法允许图中有带负权值的边，但不允许有包含带负权制的边组成的回路。Floyd算法同样适用于带权无向图，
 * 因为带权无向图可以视为权值相同往返二重边的有向图。
 * @param g 图
 * @param path 路径矩阵 path[i][j]存储结点i到结点j路径的中间点
 * @param A 最短路径长度矩阵
 */
void Floyd(MyGraph g, int Path[][MAXSIZE], int A[][MAXSIZE]) {
    int i, j, k;
    //初始化
    for (i = 0; i < g.n; ++i) {
        for (j = 0; j < g.n; ++j) {
            A[i][j] = g.edges[i][j];
            Path[i][j] = -1;
        }
    }
    for (k = 0; k < g.n; ++k) {
        for (i = 0; i < g.n; ++i) {
            for (j = 0; j < g.n; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    Path[i][j] = k;
                }
            }
        }
    }
}

int main() {
    MyGraph g = initial_digraph();
    cout << "Dijkstra算法的结果为：" << endl;
    for (int v = 0; v < g.n; ++v) {
        Dijkstra(g, v, dist, path);
        for (int i = 0; i < g.n; ++i) {
            if (path[i] != -1) {
                cout << "结点" << v << "到结点" << i << "的最短路径为：";
                printfPath(path, i);
                cout << "长度为：" << dist[i] << endl;
            }
        }
    }

    cout << "Floyd算法的结果为：" << endl;
    Floyd(g, Path, A);
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            //这里不能像Dijkstra意义通过判断Path[i][j] == -1来得到i和j无路径的结果
            if (A[i][j] != 0 && A[i][j] != INF) {
                cout << "结点" << i << "到结点" << j << "的最短路径为：";
                printfPath(i, j, Path, A);
                cout << j << endl;
                cout << "长度为：" << A[i][j] << endl;
            }
        }
    }
}


