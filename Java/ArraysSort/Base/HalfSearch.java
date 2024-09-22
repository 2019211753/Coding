package Java.ArraysSort.Base;

public class HalfSearch {
    /**
     * @param arr 原数组
     * @param re 查询数组
     * @param n 数组长度
     * @param k 查询个数
     * @param j 结果的索引
     * 如果没查到，l = h + 1。查到的话，l = h
     */
    static void half(int[] arr, int[] re, int n, int k, int j)
    {
        int l = 0, h = n - 1, mid = h / 2;
        while (l <= h)
        {
            if (arr[mid] > k)
            {
                h = mid - 1;
            } else if (arr[mid] < k){
                l = mid + 1;
            } else {
                l = mid;
                break;
            }
            mid = (l + h) / 2;
        }
        if (l >= n || arr[l] != k)
        {
            re[j++] = -1;
            re[j] = -1;
            return;
        }
        int m = l, z = l;
        while (m >= 0 && arr[m] == k)
        {
            m--;
        }
        while (z <= n - 1 && arr[z] == k)
        {
            z++;
        }
        re[j++] = ++m;
        re[j] = --z;
    }
}
