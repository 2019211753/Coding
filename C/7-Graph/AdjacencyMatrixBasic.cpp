#include "iostream"

#define MAXSIZE 100
//若点之间没有边 则将一个大于图中所有边权值的数设为权值
//顶点到自身的路径长度定义为0
#define INF 100000

using namespace std;

//顶点定义
typedef struct VertexType {
    //顶点编号
    int no;
    //顶点信息
    //char info;
} VertexType;

typedef struct MyGraph {
    //邻接矩阵定义 如果是有权图 改成float型
    int edges[MAXSIZE][MAXSIZE];
    //存储顶点
    VertexType vex[MAXSIZE];
    //顶点数
    int n;
    //边数
    int e;
} MyGraph;

//无向图
//图形：       0
//           /|  \
//      (5)/  |   \(2)
//       /    |(1) \
//     / (3)  |     \
//   1 —————— 2 —————3
//     \     |   (6) /
//      \ (2)|     /
//       \  |    /(3)
//     (4)\ |  /
//          4
MyGraph initial_undigraph() {
    MyGraph g;
    int n = 5;
    for (int i = 0; i < n; ++i) {
        VertexType vex;
        vex.no = i;
        g.vex[i] = vex;
    }
    for (int i = 0; i < n; ++i) {
        g.edges[i][i] = INF;
    }
    g.edges[0][1] = 5;
    g.edges[0][2] = 1;
    g.edges[0][3] = 2;
    g.edges[0][4] = INF;
    g.edges[1][2] = 3;
    g.edges[1][3] = INF;
    g.edges[1][4] = 4;
    g.edges[2][3] = 6;
    g.edges[2][4] = 2;
    g.edges[3][4] = 3;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g.edges[j][i] = g.edges[i][j];
        }
        g.edges[i][i] = 0;
    }
    g.n = n;
    g.e = 8;
    return g;
}

//有向图
//图形；
//                        (7)
//                  1 → → → → →  4
//            (4)↗  ↘ (1) (6)↙ ↑↘(6)
//            ↗  (6)  ↘  ↙     ↑  ↘
//         0 → → → → → → 2    (1)↑     6
//       (6)↘      (2)↗ ↘    ↑   ↗
//            ↘    ↗   (4)↘  ↑↗(8)
//               3 → → → → → → 5
//                     (5)
MyGraph initial_digraph() {
    MyGraph g;
    int n = 7;
    for (int i = 0; i < n; ++i) {
        VertexType vex;
        vex.no = i;
        g.vex[i] = vex;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g.edges[i][j] = INF;
        }
        g.edges[i][i] = 0;
    }
    g.edges[0][1] = 4;
    g.edges[0][2] = 6;
    g.edges[0][3] = 6;
    g.edges[1][2] = 1;
    g.edges[1][4] = 7;
    g.edges[2][4] = 6;
    g.edges[2][5] = 4;
    g.edges[3][2] = 2;
    g.edges[3][5] = 5;
    g.edges[4][6] = 6;
    g.edges[5][4] = 1;
    g.edges[5][6] = 8;

    g.n = n;
    g.e = 12;
    return g;
}


