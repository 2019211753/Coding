/**
 * 将中缀表达式（正常人理解的式子）转换为后缀表达式/前缀表达式
 * 中缀表达式转换成后缀表达式的结果不一定一样，如a+b+c可以是先算a+b，即ab+c+。也可以是先算b+c，即abc++
 * 示例数据：
 * 19
 * a+b-a*((c+d)/e-f)+g
 */

#include "iostream"

#define MAXSIZE 100

using namespace std;

/**
 * 将中缀表达式转换为后缀表达式 计算字母
 *
 * @param infix 中缀表达式数组
 * @param length 数组长度（式子长度）
 * @param postfix 后缀表达式数组
 */
void infixToPostfix(char *infix, int length, char postfix[]) {
    int top_post = -1;
    char symbols[MAXSIZE];
    int top_sym = -1;
    //有数字直接入栈，前面的数字在栈底
    for (int i = 0; i < length; ++i) {
        if (infix[i] <= 'z' && infix[i] >= 'a') {
            postfix[++top_post] = infix[i];
            continue;
        }
        //有符号进入时，将符号栈中在'('之前的，优先级大于等于这个符号的所有符号依次出栈，然后再将这个符号入栈
        //'('比较特殊 操作就是直接入栈
        if (infix[i] == '+' || infix[i] == '-')
        {
            while (top_sym != -1 && symbols[top_sym] != '(')
            {
                postfix[++top_post] = symbols[top_sym--];
            }
            symbols[++top_sym] = infix[i];
            continue;
        }
        if (infix[i] == '*' || infix[i] == '/')
        {
            while (top_sym != -1 && symbols[top_sym] != '('
                && symbols[top_sym] != '+' && symbols[top_sym] != '-') {
                postfix[++top_post] = symbols[top_sym--];
            }
            symbols[++top_sym] = infix[i];
            continue;
        }
        if (infix[i] == '(') {
            symbols[++top_sym] = infix[i];
            continue;
        }
        if (infix[i] == ')') {
            while (symbols[top_sym] != '(') {
                postfix[++top_post] = symbols[top_sym--];
            }
            top_sym--;
            continue;
        }
    }
    while (top_sym != -1) {
        postfix[++top_post] = symbols[top_sym--];
    }
}

int main() {
    int length;
    cin >> length;
    char expression[MAXSIZE];
    cin >> expression;
    char postfix[MAXSIZE];
    infixToPostfix(expression, length, postfix);
    postfix[length] = '\0';
    cout << postfix;
}