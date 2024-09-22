/**
 * 最小代价生成树算法（贪心算法） 仅用于无向图
 * 生成一个由 n 个顶点构成的边的权值之和最小的极小连通子图（肯定只有 n -  1 条边）
 *
 * 什么样的图其最小生成树是唯一的？
 * 所有权值均不相等，或者有相等的边，但是在构造最小生成树的过程中权值相等的边都被列入生成树的图，其最小生成树唯一
 * 如       0
 *     (1)/   \ (2)
 *      /      \
 *    1 —— 2 —— 3
 *     (3)  (3)
 * (1, 2)和 (2, 3)只有一个能进图，所以不唯一
 *
 * 如       0
 *     (1)/   \ (4)
 *      /      \
 *    1 —— 2 —— 3
 *     (3)  (3)
 * (1, 2) 和 (2, 3)都可以进图，所以唯一
 *
 * 虽然树型不一定唯一，但是权值之和总是唯一的，且最小
 */
#include "AdjacencyMatrixBasic.cpp"

/**
 * 普利姆算法 和dijkstra的算法逻辑很像
 * prim的核心是循环查找与当前树“邻接的”最近的，且加入后不会形成回路的结点加入到树
 * 而dijkstra是查找与结点v“邻接的”最近的结点并加入到图，也因此，dijsktra形成的最短路径不一定是最小生成树。
 * 即某一次添加的边与v最近，但与已加入S的结点这颗树不是最近。
 * 邻接矩阵存储结构下，时间复杂度为O(|V|^2)，不依赖于|E|
 * 记当前在最小生成树内的点集为G，在外点集为V
 * @param g 邻接矩阵存储结果下的无向图
 * @param v0 任意选择的一个结点
 * @param sum 最小生成树的权值
 */
void prim(MyGraph g, int v0, int &sum) {
    //当前树到结点i的最短距离
    int lowcost[MAXSIZE];
    //标记结点i是否已经进入G 0为G外 1为G内
    int vset[MAXSIZE];
    int v, i, j, k, min;
    v = v0;
    //初始化距离与标记数组
    for (i = 0; i < g.n; i++) {
        lowcost[i] = g.edges[v][i];
        vset[i] = 0;
    }
    vset[v] = 1;
    sum = 0;
    //只需要将其余 n - 1 个结点纳入G即可 所以只循环 n - 1 次
    for (i = 0; i < g.n - 1; i++) {
        min = INF;
        //找到在V中G的距离最近的点
        for (j = 0; j < g.n; j++) {
            if (vset[j] == 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
        }
        //纳入G
        vset[k] = 1;
        v = k;
        sum += min;
        //通过新加入G的结点k更新G到其余点的距离
        //跟dijkstra的更新方式不同的是，prim的G距离j的距离是由<k,j>更新的，最短路径可能是<k,j>
        //而dijkstra是<v,k> + <k,j>
        for (j = 0; j < g.n; j++) {
            if (vset[j] == 0 && g.edges[v][j] < lowcost[j]) {
                lowcost[j] = g.edges[v][j];
            }
        }
    }
}

/*************************************************/
//边的结构体
typedef struct {
    //一个边定义的俩顶点
    int a, b;
    //权值
    int w;
} Road;
//边数组
Road road[MAXSIZE];

void initial(MyGraph g, Road road[]) {
    int k = 0;
    for (int i = 0; i < g.n; i++) {
        for (int j = i + 1; j < g.n; j++) {
            if (g.edges[i][j] != INF) {
                Road r;
                r.a = i;
                r.b = j;
                r.w = g.edges[i][j];
                road[k++] = r;
            }
        }
    }
}

//并查集数组
int v[MAXSIZE];

/**
 * 在并查集中查找根结点的函数
 * @param a 在并查集中的位置，即结点序号
 * @return 所在树节点的位置
 */
int getRoot(int a) {
    while (a != v[a]) {
        a = v[a];
    }
    return a;
}

/**
 * 对边的权值排序
 * 排序算法是克鲁斯卡尔算法的关键，所以应该根据题目对算法时间复杂度的要求选择合适的排序算法
 * @param road 边数组
 * @param e 边数
 */
void sort(Road road[], int e) {
    for (int i = 0; i < e - 1; ++i) {
        for (int j = 0; j < e - i - 1; ++j) {
            if (road[j].w > road[j + 1].w) {
                Road r = road[j];
                road[j] = road[j + 1];
                road[j + 1] = r;
            }
        }
    }
}
/**
 * 克鲁斯卡尔算法
 * 初始时只有n个顶点而无边的非连通图 T={V,{}}，每个顶点自成一个连通分量，然后按照边的权值由小到大的顺序，不断选取当前
 * 未被选取过且权值最小的边，若该点依附的顶点落在T中不同的连通分量上（不形成回路），则将此边加入T。否则舍弃此边
 * 而选择下一条权值最小的边，以此类推，直到T中所有顶点都在一个连通分量上。
 * 时间复杂度视sort()而定 而sort()的运行效率由Road[]维数 即由|E|决定 与|V|无关 故适用于边稀疏而顶点较多的图
 * 可以延申的题目——若已规定必须选定某些边，则预处理令已形成的边构成一个树，预先处理好并查集
 * 以及在判断是否连边时 加一个判断该边是否原来已被选中
 * @param g 邻接矩阵存储结构下的无向图
 * @param sum 最小生成树的权值
 * @param road 边数组
 */
void kruskal(MyGraph g, int &sum, Road road[]) {
    int i;
    int N, E, a, b;
    N = g.n;
    E = g.e;
    sum = 0;
    //构建并查集，最开始各个结点都是“自环”，即自己是自己的根结点
    for (i = 0; i < N; i++) {
        v[i] = i;
    }
    //对边排序
    sort(road, E);
    for (i = 0; i < E; i++) {
        //得到当前边的两个顶点各自的祖先
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        //如果祖先相同，即在一棵树上，说明这两个顶点在此之前已经加入到树里了，这个边就不并入树里了，否则会成环
        if (a != b) {
            v[a] = b;
            //可变
            sum += road[i].w;
        }
    }
}

int main() {
    MyGraph g = initial_undigraph();
    int sum_prim = 0;
    prim(g, 0, sum_prim);
    cout << "prime算法的最小生成树的权值为：" << sum_prim << endl;
    int sum_kruskal = 0;
    initial(g, road);
    kruskal(g, sum_kruskal, road);
    cout << "kruskal算法的最小生成树的权值为：" << sum_kruskal << endl;
}
