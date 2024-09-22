#include "iostream"

#define MAXSIZE 100
//����֮��û�б� ��һ������ͼ�����б�Ȩֵ������ΪȨֵ
//���㵽�����·�����ȶ���Ϊ0
#define INF 100000

using namespace std;

//���㶨��
typedef struct VertexType {
    //������
    int no;
    //������Ϣ
    //char info;
} VertexType;

typedef struct MyGraph {
    //�ڽӾ����� �������Ȩͼ �ĳ�float��
    int edges[MAXSIZE][MAXSIZE];
    //�洢����
    VertexType vex[MAXSIZE];
    //������
    int n;
    //����
    int e;
} MyGraph;

//����ͼ
//ͼ�Σ�       0
//           /|  \
//      (5)/  |   \(2)
//       /    |(1) \
//     / (3)  |     \
//   1 ������������ 2 ����������3
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

//����ͼ
//ͼ�Σ�
//                        (7)
//                  1 �� �� �� �� ��  4
//            (4)�J  �K (1) (6)�L ���K(6)
//            �J  (6)  �K  �L     ��  �K
//         0 �� �� �� �� �� �� 2    (1)��     6
//       (6)�K      (2)�J �K    ��   �J
//            �K    �J   (4)�K  ���J(8)
//               3 �� �� �� �� �� �� 5
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


