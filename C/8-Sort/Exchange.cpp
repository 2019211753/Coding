/**
 * 交换排序的特点是每一次循环，都会有一个关键字到达其最终位置。
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
 * 冒泡排序
 * 每次循环结束能保证后 i 个序列全局有序，即有序且都在最终位置。
 * 稳定性：稳定 √
 * 时间复杂度：
 *      考虑最坏情况：即数组逆序，基本操作执行次数为 n - 1 + n - 2 + ··· + n - i + ··· + 1 = n * (n - 1) / 2
 *      时间复杂度为 O(n^2)
 *      最好情况：数组有序，第一趟排序之后false仍然为0，从而直接跳出循环，比较次数为 n - 1，移动次数为0。即为O(n)。
 *      故平均时间复杂度为 O(n^2)
 * 空间复杂度：
 *      算法所需的辅助存储空间不随待排序序列规模的变化而变化，是个常量，故 O(1)
 * @param R 数组
 * @param n 数组长度
 */
void bubbleSort(int R[], int n) {
    int i, j, flag, temp;
    for (i = 1; i < n; i++) {
        flag = 0;
        for (j = 1; j <= n - i; j++) {
            if (R[j - 1] > R[j]) {
                temp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

//双向冒泡排序
void BothBubbleSort(int R[], int n)
{
    int low = 0, high = n - 1;
    int flag = 0;
    //循环跳出的条件
    while (low < high && flag == 0)
    {
        int swap;
        //从前向后起泡
        for (int i = low; i < high; i++)
        {
            if (R[i] > R[i+1])
            {
                swap = R[i];
                R[i] = R[i+1];
                R[i+1] = swap;
                flag = 1;
            }
        }
        //更新上界
        high--;
        //从后向前起泡
        for (int j = high; j > low; j--)
        {
            if (R[j-1] > R[j])
            {
                swap = R[j];
                R[j] = R[j+1];
                R[j+1] = swap;
                flag = 1;
            }
        }
        //更新下界
        low++;
    }
}

/**
 * 快速排序（左右指针覆盖法）
 * 在快速排序算法中，并不一定产生有序子序列（有可能），但每趟排序后会将一个元素（枢轴元素）放在其最终的位置上。
 * 默认将序列首元素设为枢轴元素。如果选取随机枢轴元素，则在算法运行前将该元素和首元素调换即可。在可以确定枢轴元素位置的时候用。
 * 在矩阵的左右分别设一个指针，左指针表示的意义为，左面的所有值都小于等于命定值，右指针同理。每次循环时：
 * 当右边的指针大于命定值时左移，小于等于命定值时换到一个必定小于等于命定值的位置（不是交换，而是覆盖），并且停止。
 * 左侧指针同理。当小于命定值时右移，大于等于命定值时换。
 * 由此可得，右侧指针换的时候左侧指针的值肯定小于等于命定值（第一次循环等于命定值，后几次循环必然小于等于命定值）
 * 因为左指针此时指向的位置的值是上一次循环左指针停止的位置。左侧指针换的时候同理。
 * 当左右指针碰到一块的时候停止，说明这个时候是命定值应该所在的位置。左边都小于等于命定值，右边都大于等于命定值。
 * 稳定性：不稳定 × 如 4_1 4_2 2 7 第一次循环时，会变成 4_2 4_1 2 7
 * 时间复杂度：
 *      待排序列越接近无序，本算法效率越高。最好情况：每次划分所选择的中间数恰好将当前序列几乎等分，经过 log2n 趟划分，便可得到长度为1的子表。O(nlog2_n)
 *      待排序列越接近有序，本算法效率越差。最坏情况：每次所选的中间数是当前序列中的最大或最小元素，这使得每次划分所得的子表中一个为空表，
 *      另一子表的长度为原表的长度 -1。这样，长度为 n 的数据表的快速排序需要经过 n 趟划分。 O(n^2)
 *      平均情况下时间复杂度为 O(nlog2_n)
 *      在同级别的内部排序的算法中（nlog2_n）级别，基本操作执行次数多项式为 X * nlog2_n，快速排序的 X 最小，即平均性能最优。
 * 空间复杂度：
 *      由于是栈辅助递归，递归栈需要存放每次递归的数组上下界，而这取决于递归次数，和时间复杂度讨论的方式一样
 *      空间复杂度最差为O(n)，最好为 O(log2_n)，平均是O(log2_n)
 * @param R 数组
 * @param low 序列头
 * @param high 序列尾
 */
void quickSort(int R[], int low, int high) {
    int temp;
    int i = low, j = high;
    if (low < high) {
        temp = R[low];
        while (i < j) {
            while (i < j && R[j] >= temp) {
                --j;
            }
            if (i < j) {
                //为什么直接覆盖而不是交换？因为 j 元素必然会在后续循环中被覆盖。这也是将首元素设为枢轴量
                //的一个小特点。
                R[i] = R[j];
                //此时 R[i] 肯定大于等于 temp
                ++i;
            }
            while (i < j && R[i] < temp) {
                ++i;
            }
            if (i < j) {
                R[j] = R[i];
                --j;
            }
        }
        R[i] = temp;
        quickSort(R, low, i - 1);
        quickSort(R, low + 1, high);
    }
}

int main() {
    int array[MAXSIZE] = {9, 5 ,3 , 6, 2, 8, 4, 11, 15, 7, 16, 200, 111, 55, 47, 99};
    int n = 16;
    quickSort(array, 0, n - 1);
    printf(array, n);
}