/**
 * 把非零元素 依次 提到数组前面，要求顺序
 * 解1：
 * 典型的将矩阵分割为两类
 */

#include "iostream"

using namespace std;

#define endl '\n'
#define MAXSIZE 100

void prenzs(int array[], int length) {
    //zs意为有多少个非0元素（-1表示位置）
    int zs = -1;
    int temp;
    for (int i = 0; i < length; ++i) {
        if (array[i] != 0) {
            zs++;
            //此时的zs为第一个0元素的位置或最后一个非0元素的位置（如果在此之前没有出现过0元素）
            if (array[zs] != array[i]) {
                temp = array[zs];
                array[zs] = array[i];
                array[i] = temp;
            }
        }
    }
}


int main() {
    int length0 = 11;
    int array[MAXSIZE] = {1, 2, 3, 0, 0, 1, 0, 1, 1, 0, 1};
    prenzs(array, length0);
    for (int i = 0; i < length0; ++i) {
        cout << array[i] << endl;
    }
}