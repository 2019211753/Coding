/**
 * 排序的核心就是：查找 比较 移动
 * 插入排序的特点是在最后一趟循环之前，整个序列没有任何一个关键字肯定到达其最终位置。
 */
#include "iostream"
using namespace std;

#define MAXSIZE 100

void printf(int R[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

/**
 * 直接插入排序
 * 第 i 个元素插入后能保证前 i 个序列局部有序
 * 稳定性：稳定 √
 * 适用性：除了适用于顺序存储，也适用于链式存储。为链式存储时，可以从前往后查找元素的位置。
 * 时间复杂度：
 *      考虑最差情况：
 *          即数组逆序，比较次数为 1 + 2 + ··· + i + ··· + n - 1 = n * (n - 1) / 2，
 *                     移动次数为 2 + ··· + i + ··· + n = (n + 2) * (n - 1) / 2
 *                     总的时间复杂度为 O(n^2)
 *      考虑最好情况：
 *          数组顺序，内层循环始终不执行，基本操作总执行次数为 n - 1（比较次数），时间复杂度为 O(n)
 *      故平均时间复杂度为 O(n^2)
 * 空间复杂度：
 *      算法所需的辅助存储空间不随待排序序列规模的变化而变化，是个常量，故 O(1)
 * @param R 数组
 * @param n 数组长度
 */
void insertSort(int R[], int n) {
    int temp;
    int i, j;
    for (i = 1; i < n; ++i) {
        j = i;
        temp = R[j];
        while (j >= 1 && temp < R[j - 1]) {
            R[j] = R[j - 1];
            j--;
        }
        R[j] = temp;
    }
}

/**
 * 折半插入排序
 * 基于直接排序，区别是优化了查找的逻辑。使查找次数从 n 降到 nlog2_n。
 * 搜索到最后比较时一定有 i == j，然后 B[i] 和 x 比较，如果小于则 i 不变，j--，否则 j 不变，i++
 * 最终一定有 i == j + 1，i 为应该插入的位置
 * 稳定性：稳定 √ 当 i == j B[i] = x 时 i++
 * 适用性：线性表为顺序存储。用链式存储时间复杂度会增加。
 * 时间复杂度：
 *      在查找插入位置上面所花的时间大大减少，仅与表中元素个数n有关，与初始排列顺序无关，
 *      而在关键字移动次数方面和直接插入排序一样，故时间复杂度不变
 * 空间复杂度：
 *      O(1)
 * @param R 数组
 * @param n 数组长度
 * @param x 被插入的数
 */
void binaryResort(int R[], int n) {
    int i, j, k, mid, x;
    //每次循环对前 m + 1 个数进行折半插入排序
    for (int m = 1; m < n; ++m) {
        //第一个数和第 m 个数的索引
        i = 0, j = m - 1;
        //保存本次循环被排序的数（第 m + 1 个数）
        x = R[m];
        //若序列长度大于等于 1，进入循环
        while (i <= j) {
            //向下取索引 若 (i + j) / 2  + 1 则当 i == j 时区间 变为 [j + 1, j]
            mid = (i + j) / 2;
            //当 mid 大于 x，在 mid 前插入
            if (R[mid] > x) {
                j = mid - 1;
            } else {
            //若大于或等于，则在 mid 之后插入，稳定
                i = mid + 1;
            }
        }
        //把大于 x 的数都延后
        for (k = m; k > i; --k) {
            R[k] = R[k - 1];
        }
        //插到该插的地方
        R[i] = x;
    }
}

/**
 * 对序列长度 dk 进行单次希尔排序
 * @param R 数组
 * @param n 数组长度
 * @param dk 序列长度
 */
void shellInsert(int R[], int n, int dk) {
    int i, j, temp;
    for (i = 2; i <= n / dk; i++)
    {
        j = i * dk - 1;
        temp = R[j];
        while (j >= dk && temp < R[j - dk]) {
            R[j] = R[j - dk];
            j = j - dk;
        }
        R[j] = temp;
    }
}

/**
 * 希尔排序 （缩小增量序列）
 * 将整个待排记录序列分割为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序时”，
 * 再对全体记录进行一次直接插入排序，注意最小增量一定要是 1。优化了最后全体记录的直接插入排序的比较和移动次数次数。
 * 稳定性：不稳定 ×，如 1 3 2_1 2_2，当增量序列为 2 时，3 会和2_2 互换，变成 1 2_2 2_1 3
 * 应用场景：适合正序序列或分段正序序列
 * 适用性：线性表为顺序存储。用链式存储时间复杂度会增加。
 * 时间复杂度：
 *      考虑最差情况：当整个逆序的时候，仍然是 O(n^2)
 *      最好情况：整个正序，时间复杂是 O(n)
 * 空间复杂度：
 *      O(1)
 * @param R 数组
 * @param n R长度
 * @param dks 选择多个序列长度
 * @param t dks长度
 */
void shellSort(int R[], int n, int dks[], int t)
{
    int i;
    for (i = 0; i < t; i++)
    {
        shellInsert(R, n, dks[i]);
    }
}

int main() {
    int array[MAXSIZE] = {1, 5 ,3 , 6, 2, 8, 4, 11, 15, 7, 16, 200, 111, 55, 47, 99};
    int n = 16;
    int dks[3] = {5, 3, 1};
    int t = 3;
//    shellSort(B, n, dks, t);
    binaryResort(array, n);
    printf(array, n);
}