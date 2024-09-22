/*
 * ��˳���������A[]��ʾ������Ԫ�ش洢�������±�0��m+n-1�ķ�Χ�ڡ�ǰm��Ԫ�ص�������
 * ��n��Ԫ��Ҳ�������򣨷ֱ�������򣩣����һ���㷨��ʹ������˳�������
 *
 * ��1��
 * ȡ�����Ǹ������Ԫ��B[n], ǰ�������Ԫ��ΪA[m], ��B[n] <= A[m]ʱ, ��A�����m(����m)�����һλ��
 * A[m] = B[n]����B[n] > A[m]ʱ, ������һ��ѭ��, ��A[m + 1]�Ƚϡ������Ѿ��ǵ������ˣ����ô�ͷ��ʼ�Ƚϡ�
 * ���Ӷȷ�����
 * ʱ�临�Ӷȣ���������Ϊ o(m+n)���ռ临�Ӷȣ�����ռ���mn�޹�, o(1)
 * ��2������ƶ�Ч�ʽϵͣ�����ֱ�ӿ��������飬������MergeList����������Ԫ�����αȽϣ�С��Ԫ�ؼӵ���������棬
 * ��������û�б������������飬ֱ�Ӱ���������ӵ��������׺������ʱ�临�Ӷ���ΪO(m+n)�����ռ临�Ӷ�ΪO(n)����8-Sort-MergeSort
 * ��3���ӵ�m+1��Ԫ�ؿ�ʼ�ò�������ʱ�临�Ӷ�ΪO(m*n)
 */

#include "iostream"

using namespace std;

typedef struct Vector {
    int size;
    int array[1000];
} Vector;

void initial(Vector &vector, int array[], int n) {
    vector.size = n;
    for (int i = 0; i < n; i++) {
        vector.array[i] = array[i];
    }
}

/**
 * @param vector ����
 * @param m ǰһ���������еĳ���
 * @param n ��һ���������еĳ���
 */
void ArrayResort(Vector &vector, int m, int n) {
    //ǰm����������Ԫ�ص�����λ��
    int i = 0;
    //��n����������Ԫ�ص�����λ��
    int j = m;
    int temp;
    //������ j == i ʱ����ǰ i �����������Ҵ� i ��ʼ������Ҳ��Ȼ����ʱ����ǰ������
    for (; j < m + n && j != i;) {
        if (vector.array[j] < vector.array[i]) {
            temp = vector.array[j];
            for (int k = j; k > i; k--) {
                vector.array[k] = vector.array[k - 1];
            }
            vector.array[i] = temp;
            i += 1;
            j += 1;
        } else {
            i += 1;
        }
    }
}

void output(Vector vector) {
    for (int i = 0; i < vector.size; i++) {
        printf("%d,", vector.array[i]);
    }
    printf("\n************\n");
}

int main() {
    int array[8] = {3, 11, 15, 22, 47, 18, 22, 55};
    Vector vector;
    initial(vector, array, 8);
    output(vector);
    ArrayResort(vector, 5, 3);
    output(vector);
}