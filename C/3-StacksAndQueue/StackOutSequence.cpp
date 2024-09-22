/**
 * ��֪��ջ����Ϊ 1,2,...,n ���ֵ���ǰ20�ֳ�ջ˳��
 * �������� C(n, 2n) / (n + 1)
 * 1. Ӧ������ͨ����֪��ջ���У������г�ջ���С�
 * 2. ��֪������ǰ��������ж��������Ρ���ǰ��������Ϊ��ջʱ�����У���ջ�ʹ�ӡ��������������Ϊ��ջʱ�����С�
 */
#include "iostream"

using namespace std;

// �������ǰ20��
int cnt = 20;
// �����г���Ϊ3
const int n = 3;
// ���ջ
int out[n];
int top_out = -1;
// ����ջ
int ready[n];
int top_ready = -1;
// ��ǰ�������
int in = 1;

void dfs() {
    // �����20��ʱ���˳�
    if (cnt == 0) {
        return;
    }
    // ���ջ��ʱ���
    if (top_out == n - 1) {
        cnt--;
        for (int i : out) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    // Ϊʲô������ģ�塪����for{ if() }ѭ�������������������ӽڵ㣿
    //����������Ϊ��ǰ����ջ���ǳ�ջ��ֻ��������𣬹���if() if()����
    // ֻҪ����ջ��Ϊ�գ��������ջ����ΪҪ�ֵ��������ֵ�������if������
    if (top_ready >= 0) {
        int temp = ready[top_ready];
        out[++top_out] = ready[top_ready--];
        dfs();
        top_out--;
        ready[++top_ready] = temp;
    }
    // ������ջδ������������ջ
    if (in <= n) {
        ready[++top_ready] = in++;
        dfs();
        top_ready--;
        in--;
    }
}

int main() {
    dfs();
}