/**
 * 括号匹配 只匹配(
 * 主要体会什么时候用栈 即在解决问题的过程中出现了一个子问题，
 * 但凭现有条件无法解决它，需要记下，等待以后出现可以解决他的条件后再返回来解决
 * 栈问题就是等待后处理的问题
 */
#include "iostream"

#define MAXNUM 100

using namespace std;

//匹配输出0 错误输出1
int checkBracket(char expression[], int n)
{
    char brackets[MAXNUM] = "";
    int top = -1;
    for (int i = 0; i < n; ++i) {
        if (expression[i] == '(') {
            brackets[++top] = '(';
        } else if(expression[i] == ')')
        {
            if (top == -1) {
                return 1;
            }
            top--;
        }
    }

    if (top != -1) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    char expression[MAXNUM] = "()2)23112";
    int len = 9;
    cout << checkBracket(expression, len) << endl;
}