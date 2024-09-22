/**
 * Acwing.788 逆序对的数量 https://www.acwing.com/problem/content/790/
 * 归并排序不影响逆序对
 */
package Java.ArraysSort;

import java.io.*;

public class CountInversionPairs {
    //注意一定要返回long型数据
    static long sort(int[] arr, int begin, int l1, int l2, int[] array) {
        int i = begin, k = 0, j = begin + l1;
        long swap = 0;
        while (i != begin + l1 && j != begin + l1 + l2) {
            if (arr[j] >= arr[i]) {
                array[k++] = arr[i++];
            }
            if (arr[j] < arr[i]) {
                array[k++] = arr[j++];
                swap += begin + l1 - i;
            }
        }

        while (j != begin + l1 + l2) {
            array[k++] = arr[j++];
        }

        while (i != begin + l1) {
            array[k++] = arr[i++];
        }

        for (int l = 0; l < l1 + l2;) {
            arr[l + begin] = array[l++];
        }
        return swap;
    }

    static long mergeSort(int[] arr, int begin, int end, int array[]) {
        if (begin >= end) {
            return 0;
        }
        int mid = (begin + end) / 2;
        long l = mergeSort(arr, begin, mid, array);
        long r = mergeSort(arr, mid + 1, end, array);
        long k = sort(arr, begin, mid - begin + 1, end - mid, array);
        return l + r + k;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[] arr = new int[n];
        int[] array = new int[n];

        String numbers = in.readLine();
        if (numbers == null) {
            return;
        }
        String[] strNumbers = numbers.split(" ");
        for (int i = 0; i < strNumbers.length; i++) {
            arr[i] = Integer.parseInt(strNumbers[i]);
        }
        in.close();

        long nums = mergeSort(arr, 0, n - 1, array);

        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        out.write(Long.toString(nums));
        out.newLine();
        out.flush();
        out.close();
    }
}
