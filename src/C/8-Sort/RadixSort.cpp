#include "iostream"
#include "cmath"

using namespace std;

#define MAXSIZE 100
//几个桶子，即基的个数。若为字母即 26，若为数字则 10。
#define RADIX 10

void printf(int R[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

/**
 * 得到数 num 的长度
 * @param num 一个整数
 * @return 长度
 */
int getLen(int num) {
    int len = 0;
    //如果这个数是 0，直接返回长度 1
    if (num == 0) {
        return 1;
    }
    while (num != 0) {
        num = num / RADIX;
        len++;
    }
    return len;
}

/**
 * 获得数 num 从右往左第 k 位的数
 * @param num 一个整数
 * @param k 序号
 * @return 数
 */
int getNum(int num, int k)
{
    int i;
    //余数
    int rem;
    for (i = 0; i < k; i++) {
        rem = num % RADIX;
        num = num - rem;
        //去掉一位数
        num = num / RADIX;
    }
    return rem;
}

/**
 * 分配第 i 个数到 RADIX 个桶子里
 * @param array 数组
 * @param n 数组长度
 * @param bucket 桶子
 * @param queue 各桶子的队头和队尾
 * @param i 第 i 个数
 */
void distribute(int array[], int n, int **bucket, int **queue, int i) {
    int j;
    //余数
    int rem;
    //初始化队列
    for (j = 0; j < RADIX; j++) {
        queue[j][0] = -1;
        queue[j][1] = -1;
    }
    for (j = 0; j < n; j++) {
        //得到关键字
        rem = getNum(array[j], i);
        //入队，放到桶子里
        bucket[rem][++queue[rem][1]] = array[j];
    }
}

/**
 * 将 RADIX 个桶子里的数重新收集到数组里
 * @param array 数组
 * @param bucket 桶子
 * @param queue 各桶子的队头和队尾
 */
void collect(int array[], int **bucket, int **queue) {
    int j, k;
    //收集到第 l 个位置
    int l = 0;
    for (j = 0; j < RADIX; j++) {
        for (k = queue[j][0]; k != queue[j][1];) {
            array[l++] = bucket[j][++k];
        }
    }
}

/**
 * 基数排序
 * 每次分配和收集后，都能确定一个关键字的顺序。由于是先入先出的，故对其他关键字的排序也基于之前关键字的顺序。
 * 对所有关键字都排序后，最终有序。
 * 稳定性：稳定 √ 队列形式，先进先出
 * 时间复杂度：
 *      n 为序列中的关键字数，maxLen 为关键字的关键位数。RADIX 为基（桶）的个数。
 *      基数排序每一次都需要分配和收集。分配需要扫描整个序列，收集需要依次对每个桶进行。因此一次收集和分配
 *      需要 n + RADIX 个基本操作。而需要 maxLen 次分配和收集。故时间复杂度为 O(maxLen * (n + RADIX))
 *      故最好和最差都是 O(maxLen * (n + RADIX))
 * 空间复杂度：
 *      有 RADIX 个桶子，需要 2 * RADIX 个指针，故为 O(RADIX)
 * @param R 数组
 * @param n 数组长度
 */
void radixSort(int array[], int n) {
    int i;
    int maxLen = 0;
    //得到最长的数的长度
    for (i = 0; i < n; ++i) {
        if (getLen(array[i]) > maxLen) {
            maxLen = getLen(array[i]);
        }
    }
    //初始化桶子和队列
    int **bucket = (int**) malloc(RADIX * sizeof(int*));
    for (i = 0; i < RADIX; i++) {
        bucket[i] = (int*) malloc(n * sizeof(int*));
    }
    int **queue = (int**)malloc(RADIX * sizeof(int*));
    for (i = 0; i < RADIX; i++) {
        queue[i] = (int*) malloc(2 * sizeof(int*));
    }

    for (i = 1; i <= maxLen; i++) {
        distribute(array, n, bucket, queue, i);
        collect(array, bucket, queue);
    }
}


int main() {
    int array[MAXSIZE] = {49, 3, 65, 971, 76, 13, 27, 49};
    int n = 8;
    radixSort(array, n);
    printf(array, n);

}