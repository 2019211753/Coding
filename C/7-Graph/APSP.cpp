/**
 * ���·���㷨�����ڴ�Ȩͼ������ν��������
 * ���·���㷨ͨ��������һ�����ʣ�������֮������·��Ҳ������·�����������������·����Ҳ������̰�Ĳ���
*/
#include "AdjacencyMatrixBasic.cpp"

int dist[MAXSIZE];
int path[MAXSIZE];

/**
 * ���·�� ˫�ױ�ʾ��ֻ��ֱ�����Ҷ�ӽ�㵽����� ��ͨ��ջ����
 * @param path path[i]��¼���v���������i��·���ϳ����i������һ�������� ��˫�״洢��ʽ�洢��
 * @param a ���i�����
 */
void printfPath(int path[], int a) {
    int stack[MAXSIZE], top = -1;
    //�Ѹ���㣨�ڽ��a֮ǰ�Ľ�㣩������ջ
    while (path[a] != -1) {
        stack[++top] = a;
        a = path[a];
    }
    //������path[a] = -1��a ������� ��ʼ�ڵ�v
    stack[++top] = a;
    while (top != -1) {
        cout << stack[top--] << " ";
    }
    cout <<endl;
}

/**
 * �Ͻ�˹�����㷨 ���������л�·�Ĵ�Ȩͼ
 * ��ͼ��ĳһ���㵽�������������·������Դ���·������û�취��������������·����
 * ʹ���ڽӾ����ʾʱ��ʱ�临�Ӷ�ΪO(|V|^2)��ʹ�ô�Ȩ���ڽӱ��ʾʱ����Ȼ�޸�dist[]��ʱ����Լ��٣�
 * ����������dist[]��ѡ����С������ʱ�䲻�䣬ʱ�临�Ӷ���ΪO(|V|^2)
 * ���ҵ�ֻ���ҵ���������·��ʱ������㷨���Ӷ�ҲΪO(|V|^2)
 * ����Զ�ÿ���ڵ㶼����һ�Σ����б�Ȩֵ�Ǹ�������ɵõ�ÿ�Զ���֮������·����ʱ�临�Ӷ�ΪO(|V|^3)
 * ��������и�Ȩֵ���Ͻ�˹���������ã���Ϊ��Ӹ�Ȩֵ�ߵ������п��ܵ���֮ǰ�Ѿ�����˵����·����ø��̣���
 * �Ͻ�˹����û�и���֮ǰ·���Ĺ��ܡ�
 * @param g ͼ
 * @param v ��ʼ�ڵ�v�����
 * @param dist dist[i]��¼���v���������i�����·������
 * @param path path[i]��¼���v���������i��·���� �����i������һ��������
 */
void Dijkstra(MyGraph g, int v, int dist[], int path[]) {
    //��¼���i�����·���ǲ����Ѿ�������
    int set[MAXSIZE];
    int min, i, j, u;
    //��ʼ�� ����v�ڽӵĽ���·��ǰ�̽���Ϊ���v ����Ϊ-1
    for (i = 0; i < g.n; i++) {
        dist[i] = g.edges[v][i];
        set[i] = 0;
        if (g.edges[v][i] < INF) {
            path[i] = v;
        } else {
            path[i] = -1;
        }
    }
    //���ڽ��v�ĳ�ʼ��
    set[v] = 1;
    path[v] = -1;
    dist[v] = 0;
    //�ҵ���ǰ����v�����һ�����
    //��ǰ�ҵ���v-u��·�� ��Ϊvͨ����ǰ���뵽·���ĵ㵽��u�����·��
    //�����ͨ�������õ��Ľ��k��u�γ��µ�·�� ��ô��·������Ϊ(v, k) + (k, u)
    //����֪(v, u)����һ�αȽϾ�С��(v, k)�� ���Ե�ǰ���·���������·��
    //��������n - 1���������·��������
    for (i = 0; i < g.n - 1; i++) {
        min = INF;
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        //�����v�ĳ���Ϊ0 �˳����� ����set[u]�����
        if (min == INF) {
            return;
        }
        set[u] = 1;
        //�¼���һ�����󣬶�����û�й������·���Ľ�����
        for (j = 0; j < g.n; j++) {
            if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
                //��ǰv-j�����·����ǰ�����Ϊu
                path[j] = u;
            }
        }
    }
}

/*************************************************/
int A[MAXSIZE][MAXSIZE];
int Path[MAXSIZE][MAXSIZE];

/**
 * ���u-v��·��
 * @param u ��ʼ�������
 * @param v ��ֹ�������
 * @param path ·������ path[i][j]�洢���i�����j·�����м��
 * @param A ���·�����Ⱦ���
 */
void printfPath(int u, int v, int path[][MAXSIZE], int A[][MAXSIZE]) {
     //�����·��
     if (A[u][v] != INF) {
        //����ֻ�����˵� v������ⲿ���
        //��Ϊ��� cout << u << " " << v �Ļ� 1 2 3��·��������Ϊ 1 22 3 ��2��Ϊ�м�����������
        if (path[u][v] == -1)
        {
            cout << u << " ";
        } else {
            //�м��
            int mid = path[u][v];
            //����ǰ���·��
            printfPath(u, mid, path, A);
            //�������·��
            printfPath(mid, v, path, A);
        }
    } else {
        cout << endl;
    }
}

/**
 * ���������㷨
 * ��ͼ������һ�Զ��������·���ͳ���
 * ���� A[i][j] ʱ��ԭ���� A[i][j] �� A[i][k] + A[k][j] �Ƚ�
 * �ֶ���ʱ��ÿ���Ե� i ������0��ʼ��Ϊ�м��ʱ����i�к͵�i�е������䣬��Ϊ
 * A[i][j] == A[i][i] + A[i][j],  A[j][i] = A[j][i] + A[i][i]
 * ʱ�临�Ӷ�ΪO(|V|^3)��
 * Floyd�㷨����ͼ���д���Ȩֵ�ıߣ����������а�������Ȩ�Ƶı���ɵĻ�·��Floyd�㷨ͬ�������ڴ�Ȩ����ͼ��
 * ��Ϊ��Ȩ����ͼ������ΪȨֵ��ͬ�������رߵ�����ͼ��
 * @param g ͼ
 * @param path ·������ path[i][j]�洢���i�����j·�����м��
 * @param A ���·�����Ⱦ���
 */
void Floyd(MyGraph g, int Path[][MAXSIZE], int A[][MAXSIZE]) {
    int i, j, k;
    //��ʼ��
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
    cout << "Dijkstra�㷨�Ľ��Ϊ��" << endl;
    for (int v = 0; v < g.n; ++v) {
        Dijkstra(g, v, dist, path);
        for (int i = 0; i < g.n; ++i) {
            if (path[i] != -1) {
                cout << "���" << v << "�����" << i << "�����·��Ϊ��";
                printfPath(path, i);
                cout << "����Ϊ��" << dist[i] << endl;
            }
        }
    }

    cout << "Floyd�㷨�Ľ��Ϊ��" << endl;
    Floyd(g, Path, A);
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            //���ﲻ����Dijkstra����ͨ���ж�Path[i][j] == -1���õ�i��j��·���Ľ��
            if (A[i][j] != 0 && A[i][j] != INF) {
                cout << "���" << i << "�����" << j << "�����·��Ϊ��";
                printfPath(i, j, Path, A);
                cout << j << endl;
                cout << "����Ϊ��" << A[i][j] << endl;
            }
        }
    }
}


