#include "iostream"

using namespace std;

#define MAXSIZE 100

void printf(int R[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

int *B = (int*) malloc(MAXSIZE * sizeof (int ));
/**
 * �������������й鲢��һ���������������
 * ʱ�临�Ӷ�ΪO(m+n) ���ٱȽ�min(m+n)�Σ����Ƚ�m+n-1��
 * @param A ����
 * @param low ǰһ���������е���ʼλ��
 * @param mid ǰһ���������е���ֹλ�ã�Ҳ��ǰ��ֽ��
 * @param high ��һ�����������������е���ֹλ��
 */
void merge(int A[], int low, int mid, int high) {
    int i, j, k;
    //��A��������Ԫ�ظ��Ƶ�B
    for (k = low; k <= high; k++)
    {
        B[k] = A[k];
    }
    //�Ƚ�Aǰ��κͺ��ε�Ԫ�أ�С�ĸ�ֵ��B������
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i++];
        } else {
            A[k] = B[j++];
        }
    }
    //��������û��������ֱ�Ӹ��Ƽӵ�B����
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= high)
    {
        A[k++] = B[j++];
    }
}

/**
 * 2-·�鲢����
 * ��ȵݹ鵽������Ϊһ�ԣ���ÿһ�Խ�������Ȼ�����ϵ��ĸ���һ�ԣ�������������
 * �ȶ��ԣ��ȶ� ��
 * ʱ�临�Ӷȣ�
 *      ÿ�˹鲢����Ҫ������ȫ��Ԫ�ط������򣬹�ʱ�临�Ӷ�ΪO(n)������[log2_n]��ȡ�Ͻ磩��
 *      ��ʱ�临�Ӷ�Ϊ O(nlog(2_n))���ҹ鲢����ʱ�临�Ӷ����ʼ�����޹أ�������Ϊ O(nlog2_n)
 *      m-·�鲢ʱ�临��ΪΪO[logm_n]��ȡ�Ͻ磩
 * �ռ临�Ӷȣ�
 *      merge����Ҫת�������������У��ʿռ临�Ӷ�Ϊ O(n)
 * @param R ����
 * @param low ��һ�����е���ʼλ��
 * @param high �ڶ������е���ʼλ��
 */

void mergeSort(int R[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(R, low, mid);
        mergeSort(R, mid + 1, high);
        merge(R, low, mid, high);
    }
}



int main() {
    int array[MAXSIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = 8;
    mergeSort(array, 0, n - 1);
    printf(array, n);
}