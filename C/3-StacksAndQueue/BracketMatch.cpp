/**
 * ����ƥ�� ֻƥ��(
 * ��Ҫ���ʲôʱ����ջ ���ڽ������Ĺ����г�����һ�������⣬
 * ��ƾ���������޷����������Ҫ���£��ȴ��Ժ���ֿ��Խ�������������ٷ��������
 * ջ������ǵȴ����������
 */
#include "iostream"

#define MAXNUM 100

using namespace std;

//ƥ�����0 �������1
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