#include "iostream"
#include "cmath"

using namespace std;

#define MAXSIZE 100
//����Ͱ�ӣ������ĸ�������Ϊ��ĸ�� 26����Ϊ������ 10��
#define RADIX 10

void printf(int R[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

/**
 * �õ��� num �ĳ���
 * @param num һ������
 * @return ����
 */
int getLen(int num) {
    int len = 0;
    //���������� 0��ֱ�ӷ��س��� 1
    if (num == 0) {
        return 1;
    }
    while (num != 0) {
        num = num / RADIX;
        len++;
    }
    return len;
}

/**
 * ����� num ��������� k λ����
 * @param num һ������
 * @param k ���
 * @return ��
 */
int getNum(int num, int k)
{
    int i;
    //����
    int rem;
    for (i = 0; i < k; i++) {
        rem = num % RADIX;
        num = num - rem;
        //ȥ��һλ��
        num = num / RADIX;
    }
    return rem;
}

/**
 * ����� i ������ RADIX ��Ͱ����
 * @param array ����
 * @param n ���鳤��
 * @param bucket Ͱ��
 * @param queue ��Ͱ�ӵĶ�ͷ�Ͷ�β
 * @param i �� i ����
 */
void distribute(int array[], int n, int **bucket, int **queue, int i) {
    int j;
    //����
    int rem;
    //��ʼ������
    for (j = 0; j < RADIX; j++) {
        queue[j][0] = -1;
        queue[j][1] = -1;
    }
    for (j = 0; j < n; j++) {
        //�õ��ؼ���
        rem = getNum(array[j], i);
        //��ӣ��ŵ�Ͱ����
        bucket[rem][++queue[rem][1]] = array[j];
    }
}

/**
 * �� RADIX ��Ͱ������������ռ���������
 * @param array ����
 * @param bucket Ͱ��
 * @param queue ��Ͱ�ӵĶ�ͷ�Ͷ�β
 */
void collect(int array[], int **bucket, int **queue) {
    int j, k;
    //�ռ����� l ��λ��
    int l = 0;
    for (j = 0; j < RADIX; j++) {
        for (k = queue[j][0]; k != queue[j][1];) {
            array[l++] = bucket[j][++k];
        }
    }
}

/**
 * ��������
 * ÿ�η�����ռ��󣬶���ȷ��һ���ؼ��ֵ�˳�������������ȳ��ģ��ʶ������ؼ��ֵ�����Ҳ����֮ǰ�ؼ��ֵ�˳��
 * �����йؼ��ֶ��������������
 * �ȶ��ԣ��ȶ� �� ������ʽ���Ƚ��ȳ�
 * ʱ�临�Ӷȣ�
 *      n Ϊ�����еĹؼ�������maxLen Ϊ�ؼ��ֵĹؼ�λ����RADIX Ϊ����Ͱ���ĸ�����
 *      ��������ÿһ�ζ���Ҫ������ռ���������Ҫɨ���������У��ռ���Ҫ���ζ�ÿ��Ͱ���С����һ���ռ��ͷ���
 *      ��Ҫ n + RADIX ����������������Ҫ maxLen �η�����ռ�����ʱ�临�Ӷ�Ϊ O(maxLen * (n + RADIX))
 *      ����ú����� O(maxLen * (n + RADIX))
 * �ռ临�Ӷȣ�
 *      �� RADIX ��Ͱ�ӣ���Ҫ 2 * RADIX ��ָ�룬��Ϊ O(RADIX)
 * @param R ����
 * @param n ���鳤��
 */
void radixSort(int array[], int n) {
    int i;
    int maxLen = 0;
    //�õ�������ĳ���
    for (i = 0; i < n; ++i) {
        if (getLen(array[i]) > maxLen) {
            maxLen = getLen(array[i]);
        }
    }
    //��ʼ��Ͱ�ӺͶ���
    int **bucket = (int**) malloc(RADIX * sizeof(int*));
    for (i = 0; i < RADIX; i++) {
        bucket[i] = (int*) malloc(n * sizeof(int*));
    }
    int **queue = (int**)malloc(RADIX * sizeof(int*));
    for (i = 0; i < RADIX; i++) {
        queue[i] = (int*) malloc(2 * sizeof(int*));
    }

    for (i = 1; i <= maxLen; i++) {
        distribute(array, n, bucket, queue, i);
        collect(array, bucket, queue);
    }
}


int main() {
    int array[MAXSIZE] = {49, 3, 65, 971, 76, 13, 27, 49};
    int n = 8;
    radixSort(array, n);
    printf(array, n);

}