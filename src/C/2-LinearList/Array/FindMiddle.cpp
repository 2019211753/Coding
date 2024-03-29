#include "iostream"

using namespace std;

#define endl '\n'

/**
 * 一个长度为L(L≥1)的升序序列S，处在第L/2（向上取整）个位置的数称为S的中位数。
 * 例如，若序列S=(11,13, 15, 17, 19)。则S的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。
 * 例如，若S=(2,4,6,8,20)，则S和S的中位数是11。
 * 现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数
 * @param A A数组
 * @param B B数组
 * @param n 数组长度
 * @return 中位数
 */
int findMiddleInSortedArrays(int A[], int B[], int n)
{
    // s1、s2 分别为AB新数组首位数在原数组中的索引
    // d1、d2 ...末位数...
    // m1、m2 ...中位数
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
    // 当A数组或B数组都只剩下一个元素时停止，每次循环都删去一部分部位中位数的数组
    while (s1 != d1 || s2 != d2)
    {
        // 找到中位数
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        // 如果A数组中位数等于B数组中位数，则这个中位数相当于整个数组的中位数
        if (A[m1] == B[m2])
        {
            return A[m1];
        } else if (A[m1] < B[m2])
        {
        // 如果...<... 假设每个数组长度为n，中位数取在n/2（向上取整）中位数应大于等于m1，小于等于m2
        // m1到m2数组长度为n+1，在这个新数组中重新寻找中位数
            if ((s1 + d1) % 2 == 0) {
            // 若原数组长度为奇数，中位数取在n/2（向下取整）+1
            // 数组中最多有n/2（向下取整）个数比m1小，最少0。故m1可能为中位数。
            // 数组中最少有n/2（向上取整个数）个数比m2小，最多n，故m2不可能为中位数。
                // 舍弃A中间点以前的部分且保留中间点
                s1 = m1;
                // 舍弃B中间点以后的部分且保留中间点
                // 虽然由上m2不可能为中位数，但需要让两次舍弃的长度相等，这样新数组的中位数才能是整个数组的中位数，故保留中间点，下同
                d2 = m2;
            } else {
            // 若原数组长度为偶数，中位数取在n/2+1处
            // 数组中最多有n/2-1个数比m1小，最少0。故m1不可能为中位数。
            // 数组中最少有n/2个数比m2小，最多n，故m2可能为中位数。
                // 舍弃A中间点及中间点以前部分
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
        // 如果...>... 同上反过来而已
            // 如果数组长度为奇数
            if ((s2 + d2) % 2 == 0) {
                // 舍弃A中间点以后部分且保留中间点
                d1 = m1;
                // 舍弃B中间点以前部分且保留中间点
                s2 = m2;
            } else {
                d1 = m1;
                // 舍弃B中间点及中间点以前部分
                s2 = m2 + 1;
            }
        }
    }
    return A[s1] < B[s2] ? A[s1]:B[s2];
}

int main()
{
    int A[] = {11, 13, 15, 17, 19};
    int B[] = {2, 4, 6, 8, 20};
    int n = 5;
    cout << findMiddleInSortedArrays(A, B, n);
}