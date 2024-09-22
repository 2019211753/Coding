#include <cstdio>

#define INT_MAX 0x7fffffff

int abs_(int a)
{
    if (a < 0)
    {
        return -a;
    } else {
        return a;
    }
}

bool xls_min(int a, int b, int c)
{
    if (a <= b && a <= c)
    {
        return true;
    } else {
        return false;
    }
}

/**
 * ������Ԫ��(a, b,c)�ľ��� D = |a-b| + |b-c| + |c-a|������3���ǿ���������S1, S2, S3��������
 * �ֱ�洢��3�������С�����㷨���㲢������е���Ԫ��(a, b ,c)��a��S1, b��S2, c��S3���е���С���롣
 * ��������������ΪA ���� B ���� C���������ľ����൱�������������A-C�ľ���*2��ÿ�ν�������ʱ��
 * ���ȡC�ĺ�һλ����A-C�ľ������󣬲��Ǹ��̾��롣
 * ���ȡB�ĺ�һλ����B�ĺ�һλ��AC�䣬���벻�䣬��ȡ��A-C�ұߣ���A-C��������
 * ���ȡA�ĺ�һλ������B-C��࣬������С�������B-C֮�䣬�����С����B-C�Ҳ࣬����仯δ֪��
 * ���ϣ�ÿ��������ȡ��ǰ��Сֵ�������һλ��Ψһ�ܵõ����̾����ѡ��
 * ��Ȼ����ÿ���ƶ�����Ȼ���и��Ž⣬�������ƶ��������޷���ͷ��֮ǰ��λ�ã���ô����©���
 * ���ᣬ���赱ǰ��Ϊ A_i ���� B_j ���� C_k��
 * ��һ��Ϊ(A_i ����) B_j ���� C_k ���� A_i+i �� (A_i ����) B_j ���� A_i+i ���� C_k
 * ��֪���� B_j�� C_k��α䶯�����Ҳ�ĵ���A_i��
 * ���붼�����̡��Ӷ�˵�������ں�A_i�ĸ��Ž����Ԫ�����
 *
 * �� n = (|S1| + |S2| + |S3|)��|S|Ϊ���ϴ�С��ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1)
 */
int findMinOfTrip(int A[], int n, int B[], int m, int C[], int p)
{
    int i = 0, j = 0, k = 0, D_min = INT_MAX, D;
    while (i < n && j < m && k < p && D_min > 0)
    {
        D = abs_(A[i] - B[j]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]);
        if (D < D_min)
        {
            D_min = D;
        }
        if (xls_min(A[i], B[j], C[k]))
        {
            i++;
        } else if (xls_min(B[j], C[k],A[i]))
        {
            j++;
        } else {
            k++;
        }
    }
    return D_min;
}

int main()
{
    int A[] = {-1, 0, 9}, n = 3;
    int B[] = {-25, -10, 10, 11}, m = 4;
    int C[] = {2, 9, 17, 30, 41}, p = 5;
    printf("��С����Ϊ��%d", findMinOfTrip(A, n, B, m, C, p));
}