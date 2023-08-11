//利用栈实现递归函数的非递归计算 把递归中最后计算的放在栈顶

#include "iostream"

#define MAXSIZE 100

double p(int n, double x)
{
    struct stack {
        int no;
        double val;
    } st[MAXSIZE];
    int top = -1, i;
    double f1 = 1, f2 = 2*x;
    for (i = n; i > 2; i--)
    {
        st[++top].no = i;
    }
    while (top >= 0)
    {
        st[top].val = 2*x*f2 - 2*(st[top].no - 1)*f1;
        f1 = f2;
        f2 = st[top].val;
        top--;
    }
    if (n == 0)
    {
        return f1;
    }
    return f2;
}
int main()
{

}