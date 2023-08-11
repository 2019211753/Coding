/**
 * 计算后缀表达式 仅支持+-*÷ 前/后缀表达式是不含()的
 * 后缀表达式的计算方式为"从左到右"扫描到数字入栈 扫描到运算符取栈顶两个元素或一个计算(由运算符是单目还是双目的决定) 将结果再放入栈顶
 * 前缀表达式正好反过来

 */
#include "iostream"

using namespace std;

int calculate(int a, int b, char c) {
    if (c == '*') {
        return a * b;
    }
    if (c == '/') {
        return a / b;
    }
    if (c == '+') {
        return a + b;
    }
    if (c == '-') {
        return a - b;
    }
}

int calculatePostFix(char *s, int len) {
    // 数字栈
    int top_number = -1;
    int number[len];
    for (int i = 0; i < len; ++i) {
        if (s[i] <= '9' && s[i] >= '0') {
            number[++top_number] = s[i] - '0';
        } else {
            int b = number[top_number--];
            int a = number[top_number--];
            number[++top_number] = calculate(a, b, s[i]);
        }
    }
    return number[top_number];
}


int main() {
    char exp[11] = {'6', '5', '2', '3', '+', '8', '*', '+', '3', '+', '*'};
    cout << calculatePostFix(exp, 11) << endl;
}