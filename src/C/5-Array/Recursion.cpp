/**
 * 递归实现数组的加和求最大值
 */
#include "iostream"

using namespace std;

#define endl '\n'
#define MAXSIZE 100

float findMaxNum(float array[], int i, int j) {
    float max;
    if (i == j) {
        return array[i];
    } else {
        max = findMaxNum(array, i + 1, j);
        if (array[i] > max) {
            return array[i];
        } else {
            return max;
        }
    }
}

float sum(float array[], int i, int j) {
    if (i == j) {
        return array[i];
    } else {
        return array[i] + sum(array, i + 1, j);
    }
}

int main() {
    float array[6]= {1, 2, 0, 4, 3, -1};
    printf("%f", sum(array, 0, 5));
}