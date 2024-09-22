/**
 * 快排划分区间的三种方法
 */
#include "iostream"

using namespace std;

typedef struct Vector {
    int size;
    int array[];
} Vector;

void initial(Vector &vector, int array[], int n) {
    vector.size = n;
    for (int i = 0; i < n; i++) {
        vector.array[i] = array[i];
    }
}

void output(Vector &vector) {
    for (int j = 0; j < vector.size; ++j) {
        cout << vector.array[j] << " ";
    }
    cout << "*************"  << endl;
}

/**
 * 有一个顺序表L，其元素为整型数据，设计一个算法，将L中所有小于表头元素的整数放在前半部分，大于表头元素的整数放在后半部分。
 * 不要求顺序
 * 解1：
 * 典型的通过某一个命定的特殊的元素分割矩阵，是快速排序算法的一次循环。
 * 时间复杂度：最差情况即所有元素都比表头元素大，O(n)。 空间复杂度 O(1)
 */
void divide_1(Vector &vector) {
    int begin = 0;
    int end = vector.size - 1;
    int mark = vector.array[0];
    while (begin < end) {
        //因为命定值在左侧第一个，所以应该从右侧开始
        //因为如果从左侧开始，如果array[i]小于mark了，还需要移动，而从右侧开始，如果j大于mark，不需要移动
        //而且如果i大于mark了，移动到哪里去呢？哪里都不合适，而j小于mark，直接移动到i就可以了
        while (vector.array[end] > mark && begin != end) {
            end--;
        }
        if (begin != end) {
            vector.array[begin] = vector.array[end];
            begin++;
        }
        while (vector.array[begin] < mark && begin != end) {
            begin++;
        }
        if (begin != end) {
            vector.array[end] = vector.array[begin];
            end--;
        }
    }
    vector.array[begin] = mark;
}

//将所有奇数移动到所有偶数的前面
//左右指针交换法 一般在无法确定一个枢轴元素位置的时候用
void divide_2(Vector &vector)
{
    int i = 0, j = vector.size - 1;
    while (i < j)
    {
        while (i < j && vector.array[i] % 2 != 0)
        {
            i++;
        }
        while (i < j && vector.array[j] % 2 != 1)
        {
            j--;
        }
        //本题枢轴量不在特殊的位置上。则采取交换而不是覆盖。
        if (i < j)
        {
            int temp = vector.array[i];
            vector.array[i] = vector.array[j];
            vector.array[j] = temp;
        }
        //由于是交换，这里i已经小于枢轴量了，j已经大于枢轴量了，都改变。
        i++;
        j--;
    }
}

//随机选取一个枢轴量（已知枢轴量的位置可用）
//左右指针前移法（用左右指针覆盖法也可以）这里主要介绍第三种快排的划分方法。特殊在于它们移动的方向相同。
int divide_3(Vector &vector, int low, int high)
{
    //随机一个位置 将它与low元素互换 不知道为什么不能随机出来一个数
    //int rand_index = low + rand() % (high-low+1);
    int rand_index = 0;
    int temp = vector.array[low];
    vector.array[low] = vector.array[rand_index];
    vector.array[rand_index] = temp;
    temp = vector.array[low];
    //左指针先设在枢轴量处，从该位置往左，元素均小于枢轴量，最终位置时，右边元素均大于枢轴量
    int i = low;
    //右指针设在枢轴量右边一个的位置
    for (int j = low + 1; j <= high; j++)
    {
        //当前元素小于枢轴量，左指针右移，与右指针元素互换。从而左指针仍旧保持小于等于枢轴量。右指针同理。
        //枢轴量的位置始终保持不动。
        if (vector.array[j] < temp)
        {
            int t = vector.array[++i];
            vector.array[i] = vector.array[j];
            vector.array[j] = t;
        }
    }
    //最后左指针的的右侧全是大于枢轴量的数，将枢轴量与左指针交换即可
    temp = vector.array[i];
    vector.array[i] = vector.array[low];
    vector.array[low] = temp;
    return rand_index;
}

int main() {
    int array[7] = {4, 2, 7, 5, 1, 8, 7};
    Vector vector;
    initial(vector, array, 7);
    output(vector);
    cout << divide_3(vector, 0, 6) << endl;
    output(vector);
}