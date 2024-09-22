/**
 * 以某个序列输入栈，判断栈输出是否合法
 */

#include "iostream"

using namespace std;

int getSite(int num, int array[], int length) {
    for (int i = 0; i < length; ++i) {
        if (array[i] == num) {
            return i;
        }
    }
    return -1;
}

int check(int in[], int out[], int length) {
    int stack[length];
    int top = -1;

    //输出序列中第1个元素在输入序列中的位置
    int site = getSite(out[0], in, length);
    int maxsite = site;
    //复制到stack里，不包含这个元素
    for (int i = 0; i < site; ++i) {
        stack[++top] = in[i];
    }

    for (int i = 1; i < length; ++i) {
        int nowsite = getSite(out[i], in, length);
        //如果这次的元素在输入序列中先于上一个输出，且在栈顶，则是正确输出，出栈，否则错误
        if (nowsite < site) {
            if (stack[top] == out[i]) {
                 top--;
            } else {
                return -1;
            }
        } else {
            if (nowsite > maxsite) {
                for (int j = maxsite + 1; j < nowsite ; ++j) {
                    stack[++top] = in[j];
                }
            }
            maxsite = nowsite;
        }
        site = nowsite;
    }
    return 1;
}

int main() {
    int in[5] = {1, 4, 2 ,3 ,5};
    int out[5] = {1, 3, 4, 2 ,5};
    cout << check(in, out, 5);
}