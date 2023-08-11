/**
 * 已知一个整数序列A。主元素定义为在序列中出现次数最多且超过序列长度的一半的元素。即一个人打你们所有人。
 * 假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，
 * 找出A的主元素。若存在主元素，则输出该元素。否则输出-1。
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
        printf("主元素为：%d", answer);
    } else {
        printf("无主元素");
    }
}