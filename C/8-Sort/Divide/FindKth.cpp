using namespace std;

//查找数组元素中第k小的元素
//最直接的做法是使用排序算法先从小到大的排序，然后提取L(k)。但是其平均时间复杂度将达到O(nlog2_n)以上。
//此外，还可以采用小顶堆的方法，时间复杂度为O(n+klog2_n)。
//而使用快速排序方法，时间复杂度在平均情况下可以达到O(n)
//利用快速排序的思路划分区间，还可以用在16年统考真题中：
//已知n(n>2)个正整数构成的集合A={ak|0<=k<n}，将其划分为两个不相交的子集A1和A2，元素个数分别是n1和n2，A1和A2
//中的元素之和分别为S1，S2，设计一个划分算法满足|n1-n2|最小且|S1-S2|最大。
//即找到第floor(n/2)小的元素位置即可，时间复杂度同本题。
int findKth(int array[], int low, int high, int k)
{
    int pivot = array[low];
    int low_temp = low;
    int high_temp = high;
    while (low < high)
    {
        while (low < high && array[high] >= pivot)
        {
            high--;
        }
        array[low] = array[high];
        while (low < high && array[low] <= pivot)
        {
            ++low;
        }
        array[high] = array[low];
    }
    array[low] = pivot;
    //上面是快速排序的划分算法，下面为本算法的核心
    //快速排序的特征：能直接确定一个元素的最终位置，即所在索引为第k小/大
    //如果low == k，显然pivot就是要寻找的元素，直接返回
    if (low == k)
    {
        return array[low];
    //否则找左边的区间
    } else if (low > k) {
        return findKth(array, low_temp, low-1, k);
    } else {
        return findKth(array, low+1, high_temp, k);
    }
}

int main()
{

}