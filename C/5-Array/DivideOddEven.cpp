/**
 * �����������������Ƶ�ż��֮ǰ����ʱ�临�Ӷ�Ϊo(n) ��Ҫ��˳�� ���ڶ��µ�DivideArray����
 */
#include "iostream"

using namespace std;

#define MAXSIZE 100

void divide(int array[], int length) {
    int i = 0;
    int j = length - 1;
    int temp;
    while (i < j)
    {
        if (array[i] % 2 == 0 && array[j] % 2 == 1) {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            i++;
            j--;
        } else if (array[i] % 2 == 0 && array[j] % 2 == 0) {
            j--;
        } else if (array[i] % 2 == 1 && array[j] % 2 == 0) {
            i++;
            j--;
        } else if (array[i % 2 == 1 && array[j] % 2 == 1]) {
            i++;
        }
    }
}

int main() {
    int array[8] = {1, 2, 2, 3, 3, 5, 6, 6};
    int length = 8;
    divide(array, 8);
    int i = 0;
    while (i < length) {
        cout << array[i] << " ";
        i++;
    }
}