/**
 * Acwing.787 逆序对的数量 https://www.acwing.com/problem/content/789/
 */
package Java.ArraysSort.Base;

import java.io.*;

public class MergeSort {
    static void sort(int[] arr, int begin, int l1, int l2, int[] array) {
        int i = begin, k = 0, j = begin + l1;
        while (i != begin + l1 && j != begin + l1 + l2) {
            if (arr[j] >= arr[i]) {
                array[k++] = arr[i++];
            }
            if (arr[j] < arr[i]) {
                array[k++] = arr[j++];
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
    }

    static void mergeSort(int[] arr, int begin, int end, int array[]) {
        if (begin >= end) {
            return;
        }
        int mid = (begin + end) / 2;
        mergeSort(arr, begin, mid, array);
        mergeSort(arr, mid + 1, end, array);
        sort(arr, begin, mid - begin + 1, end - mid, array);
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

        mergeSort(arr, 0, n - 1, array);

        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        out.write(Integer.toString(arr[0]));
        for (int i = 1; i < n; i++) {
            out.write(" " + arr[i]);
        }
        out.newLine();
        out.flush();
        out.close();
    }
}