#include "iostream"
using namespace std;

typedef struct List {
    int *array;
    int length;
} L;

/**
 * 删除数组中值为x的元素
 * 使用 k 记录截止当前索引为 i 的元素，已经出现了几个值为 x 的元素。让当前元素往前移动 k 个位置。
 * @param l 数组
 * @param x 被删除的元素
 */
void remove_1(L &l, int x)
{
    int k = 0;
    int i = 0;
    while (i < l.length)
    {
        if (l.array[i] != x)
        {
            l.array[i - k] = l.array[i];
        } else {
            k++;
        }
        i++;
    }
    l.length = l.length - k;
}

/**
 * 删除数组中值为x的元素
 * 左指针的意义为 指针左侧没有等于 x 的元素
 * 右指针的意义为 指针右侧全是等于 x 的元素
 * 不太行 基于快排思想 不稳定
 */
void remove_2(L &l, int x)
{
    int i = 0, j = l.length - 1;
    while (i <= j)
    {
        while (i <= j && l.array[i] != x)
        {
            i++;
        }
        if (i <= j)
        {
            while (i <= j && l.array[j] == x)
            {
                j--;
            }
            if (i <= j)
            {
                l.array[i] = l.array[j];
                //看起来好看一点
                l.array[j] = x;
                i++;
                j--;
            }
        }
    }
    l.length = j + 1;
}

/**
 * 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 * 类比链表，这样做是因为数组删除元素移动次数比较多，而链表只需要o(1)即可。
 */
bool removeDuplicate(List &l)
{
    if (l.length == 0)
    {
        return false;
    }
    // 指针 i 始终指向一组相同数中第一个数，也是有序不重复序列的最后一个数
    int i = 0, j = 1;
    for (; j < l.length;)
    {
        // 如果 j 和 i 指向的数不同，说明 j 指向的数是下一组数，且 j 指向的数也是当前一组数的第一个数
        // 直接移动 j 到 i+1 处，同时 i、j 自增
        // 若 j 和 i 指向的数相同，则只让 j 自增，扫描下一个数
        if (l.array[i] != l.array[j])
        {
            l.array[++i] = l.array[j];
        }
        j++;
    }
    l.length = i + 1;
    return true;
}


void output(L l) {
    for (int i = 0; i < l.length; ++i) {
        cout << l.array[i] << " ";
    }
}

int main()
{
    List l;
    int array[] = {1 , 2, 7, 1, 2, 6, 7, 2};
    l.array = array;
    l.length = 8;
    removeDuplicate(l);
    output(l);
}