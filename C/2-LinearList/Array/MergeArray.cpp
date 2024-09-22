/*
 * 设顺序表用数组A[]表示，表中元素存储在数组下标0～m+n-1的范围内。前m个元素递增有序，
 * 后n个元素也递增有序（分别递增有序），设计一个算法，使得整个顺序表有序。
 *
 * 解1：
 * 取后面那个数组的元素B[n], 前面数组的元素为A[m], 当B[n] <= A[m]时, 将A数组从m(包括m)向后移一位，
 * A[m] = B[n]。当B[n] > A[m]时, 进入下一次循环, 与A[m + 1]比较。由于已经是递增的了，不用从头开始比较。
 * 复杂度分析：
 * 时间复杂度：最差情况的为 o(m+n)。空间复杂度：所需空间与mn无关, o(1)
 * 解2：多次移动效率较低，可以直接开个新数组，类似于MergeList，两个数组元素依次比较，小的元素加到新数组后面，
 * 最后如果有没有遍历到最后的数组，直接把整个后面加到新数组后缀。这样时间复杂度仍为O(m+n)，但空间复杂度为O(n)，见8-Sort-MergeSort
 * 解3：从第m+1个元素开始用插入排序，时间复杂度为O(m*n)
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
 * @param vector 数组
 * @param m 前一个有序序列的长度
 * @param n 后一个有序序列的长度
 */
void ArrayResort(Vector &vector, int m, int n) {
    //前m个的数组中元素的索引位置
    int i = 0;
    //后n个的数组中元素的索引位置
    int j = m;
    int temp;
    //当满足 j == i 时，即前 i 个序列有序，且从 i 开始的序列也必然有序，时，提前结束。
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