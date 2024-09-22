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
 * 定义三元组(a, b,c)的距离 D = |a-b| + |b-c| + |c-a|。给定3个非空整数集合S1, S2, S3，按升序
 * 分别存储在3个数组中。设计算法计算并输出所有的三元组(a, b ,c)（a∈S1, b∈S2, c∈S3）中的最小距离。
 * 三个点在数轴上为A —— B —— C，三个点间的距离相当于最边上两个点A-C的距离*2。每次进行搜索时，
 * 如果取C的后一位，则A-C的距离增大，不是更短距离。
 * 如果取B的后一位，若B的后一位在AC间，距离不变，若取在A-C右边，则A-C距离增大。
 * 如果取A的后一位，若在B-C左侧，则距离减小。如果在B-C之间，距离减小，在B-C右侧，距离变化未知。
 * 综上，每次搜索，取当前最小值的数组后一位是唯一能得到更短距离的选择。
 * 既然不是每次移动都必然会有更优解，且往后移动的数组无法回头到之前的位置，那么不会漏解嘛？
 * 不会，假设当前解为 A_i —— B_j —— C_k，
 * 下一解为(A_i ——) B_j —— C_k —— A_i+i 或 (A_i ——) B_j —— A_i+i —— C_k
 * 可知无论 B_j和 C_k如何变动，最右侧的点与A_i的
 * 距离都不会变短。从而说明不存在含A_i的更优解的三元组组合
 *
 * 令 n = (|S1| + |S2| + |S3|)，|S|为集合大小，时间复杂度为 O(n)，空间复杂度为 O(1)
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
    printf("最小距离为：%d", findMinOfTrip(A, n, B, m, C, p));
}