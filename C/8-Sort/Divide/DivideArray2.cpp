#include "iostream"

using namespace std;

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

//三指针法
//划分3个区间，前面是-1，中间是0，后面是1
//指针i意味i左边全是-1，k右边全为1，j为工作指针，左边的-1和0基本有序，右边无序。
void numArrange(int array[], int n)
{
    int i = 0, j = 0, k = n-1;
    while (j <= k)
    {
        switch (array[j]) {
            case -1:
                swap(array, i, j);
                //之所以这里交换可以j++，因为j与i交换，i必为-1或0，不可能为1，而-1或0都可以直接检查j+1数组了。
                i++;
                j++;
                break;
            case 0:
                j++;
                break;
            case 1:
                //前提：j < k，如果是1，j和k交换，1必然到j后面。所以j之前只有-1、0，没有1。
                swap(array, j, k);
                k--;
                //这里没有j++以防止交换后a[j]仍为1。如果array[k]是0，可以j++。如果是1或-1，那j还要保持在原位继续交换。
        }
    }
}