/**
 * ��֪һ����������A����Ԫ�ض���Ϊ�������г��ִ�������ҳ������г��ȵ�һ���Ԫ�ء���һ���˴����������ˡ�
 * ����A�е�n��Ԫ�ر�����һ��һά�����У������һ�������ܸ�Ч���㷨��
 * �ҳ�A����Ԫ�ء���������Ԫ�أ��������Ԫ�ء��������-1��
 */

#include "iostream"

using namespace std;

#define endl '\n'

using namespace std;

typedef struct Arr {
    int size;
    int array[];
} Arr;

void initial(Arr *&arr, int array[], int n) {
    arr = (Arr*)malloc(sizeof(Arr));
    arr->size = n;
    for (int i = 0; i < n; i++) {
        arr->array[i] = array[i];
    }
}

int pick(Arr *arr) {
    int* array = arr->array;
    int size = arr->size;
    int most = array[0];
    int count = 1;
    for (int i = 1; i < size; ++i) {
        if (most != array[i]) {
            if (count > 0) {
                --count;
            }
            if (count == 0) {
                most = array[i];
            }
        } else {
            if (most == array[i]) {
                ++count;
            }
        }

    }
    if (count > 0) {
        return most;
    }
    return -1;
}

int main() {
    int array[] = {1, 1, 1, 8, 8, 1, 1, 8, 8};
    Arr *arr;
    initial(arr, array, 9);
    int answer = pick(arr);
    if (answer != -1) {
        printf("��Ԫ��Ϊ��%d", answer);
    } else {
        printf("����Ԫ��");
    }
}