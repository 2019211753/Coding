/**
 * Acwing.785 快速排序 https://www.acwing.com/activity/content/problem/content/819/
 * 快速排序每次递归可以使一个枢轴量到达它应该在的位置
 */
package Java.ArraysSort.Base;

import java.util.Scanner;

public class QuickSort {
    static void swap(int[] array, int i, int j)
    {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }

    //法1：覆盖法
    //特点是到最后 i一定等于j 也就是枢轴量应该在的位置
    //输入的low、high都是索引，分布是 0 和 len-1
    static void sort1(int[] array, int low, int high) {
        if (low >= high)
        {
            return;
        }
        int mid = (low + high) / 2;
        int i = low, j = high;
        swap(array, low, mid);
        int pivot = array[low];
        while (i < j) {
            while (i < j && array[j] > pivot) {
                j--;
            }
            //这里强调，如果发生交换，一定要让i的位置发生变化，否则如果array[j]和枢轴量相等，那么会陷入死循环，下同
            if (i < j) {
                array[i++] = array[j];
            }
            while (i < j && array[i] < pivot) {
                i++;
            }
            if (i < j) {
                array[j--] = array[i];
            }
        }
        array[i] = pivot;
        sort1(array, low, j - 1);
        sort1(array, j + 1, high);
    }

    //法2：交换法
    //特点是 i、j循环到最后可能 j + 1 = i，也可能 i = j，代码简洁，但对比覆盖法，数组元素变动次数多了一些
    //输入的low、high都是索引，分布是 0 和 len-1
    static void sort2(int[] array, int low, int high) {
        if (low >= high)
        {
            return;
        }
        //这里是取中位的下界位置为枢轴量，和取i为枢轴量差不多，不过更好，避免数组有序时时间复杂度到达O(n^2)。
        //当分治边界取 j 和 j+1 时，pivot不能取 arr[high]，因为 j 下界为 low，则[j + 1, high]不会造成无限划分，但 [low, j]却可能造成，因为 j 可能取到 high。
        int pivot = array[(low + high) / 2];
        //初始化，arr[low, low+1, ..., i] <= pivot, arr[j, j+1, ..., high] >= pivot
        int i = low - 1, j = high + 1;
        while (i < j) {
            //做完这个循环，arr[low, low+1, ..., i-1] <= pivot, arr[i] >= pivot
            do {
                i++; //每次循环都要让i至少变化一次，不然如果arr[i]=pivot，就一直不动了
            } while (array[i] < pivot); //这里不能是<=，如果 arr 中元素全相等，则 i 会自增到 i+1，数组越界。
            //做完这个循环，arr[j+1, ..., high] >= pivot, arr[j] <= pivot
            do {
                j--;
            } while (array[j] > pivot);
            //以上前提可以保证 i - 1 < j + 1，即 i < j + 2。当整个循环结束后，有 i >= j，即存在 i = j 和 i = j + 1 两种情况，且i和j必不可能越界
            //在最后一轮循环之前，做完下面这个if语句，arr[low, low+1, ..., i] <= pivot, arr[j, j+1, ..., high] >= pivot，又回归到初始化的状态
            //但最后一轮有点特殊，因为这个if语句不会被执行，所以只能保证 arr[low, low+1, ..., i-1] <= pivot, arr[i] >= pivot, arr[j+1, ..., high] >= pivot, arr[j] <= pivot, i >= j
            //所以 arr[low, low+1, ..., j] <= pivot, arr[j+1, ..., high] >= pivot, 此时arr[j, i] == pivot
            if (i < j) {  // <= 也行，无所谓
                swap(array, i, j);
            }
        }
        //要小心边界问题，以免造成无穷分治，即sort(0,n)划分为sort(0,0)和sort(0,n)
        //当pivot = arr[low + high >> 2]时，j的取值范围是[low, high-1]，证明见下
        //假设 j 最终的值为 high，说明只有一轮循环(两轮的话 j 至少会自减两次)
        //说明arr[high] <= x (因为要跳出do-while循环)
        //说明 i >= high (while循环的结束条件)， i 为 high 或 high + 1(必不可能成立)，说明 i 是**自增**到了 high，即 arr[low, ..., high-1] < pivot，arr[high] = pivot，但这与 pivot = arr[low + high >> 1]矛盾。
        sort2(array, low, j);
        sort2(array, j + 1, high);
        //若pivot取上界，则采用下面的分治边界
        //sort2(array, low, i - 1)
        //sort2(array, i, high);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = sc.nextInt();
        }
        sort2(array, 0, n - 1);
        System.out.print(array[0]);
        for (int i = 1; i < n; i++)
        {
            System.out.print(" " + array[i]);
        }
    }
}