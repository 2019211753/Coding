#include "iostream"

using namespace std;

#define MAXSIZE 100

void printf(int R[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

int *B = (int*) malloc(MAXSIZE * sizeof (int ));
/**
 * 将两个有序序列归并成一个整体有序的序列
 * 时间复杂度为O(m+n) 最少比较min(m+n)次，最多比较m+n-1次
 * @param A 数组
 * @param low 前一个有序序列的起始位置
 * @param mid 前一个有序序列的终止位置，也即前后分界点
 * @param high 后一个序列在整个数组中的终止位置
 */
void merge(int A[], int low, int mid, int high) {
    int i, j, k;
    //把A数组所有元素复制到B
    for (k = low; k <= high; k++)
    {
        B[k] = A[k];
    }
    //比较A前半段和后半段的元素，小的赋值到B数组中
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i++];
        } else {
            A[k] = B[j++];
        }
    }
    //还有数组没遍历到，直接复制加到B后面
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= high)
    {
        A[k++] = B[j++];
    }
}

/**
 * 2-路归并排序
 * 深度递归到两个数为一对，对每一对进行排序，然后向上到四个数一对，最终整个排序。
 * 稳定性：稳定 √
 * 时间复杂度：
 *      每趟归并都需要对数组全部元素分组排序，故时间复杂度为O(n)，共需[log2_n]（取上界）趟
 *      故时间复杂度为 O(nlog(2_n))，且归并排序时间复杂度与初始序列无关，最好最坏均为 O(nlog2_n)
 *      m-路归并时间复杂为为O[logm_n]（取上界）
 * 空间复杂度：
 *      merge操作要转存整个待排序列，故空间复杂度为 O(n)
 * @param R 数组
 * @param low 第一个序列的起始位置
 * @param high 第二个序列的起始位置
 */

void mergeSort(int R[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(R, low, mid);
        mergeSort(R, mid + 1, high);
        merge(R, low, mid, high);
    }
}



int main() {
    int array[MAXSIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    mergeSort(array, 0, n - 1);
    printf(array, n);
}