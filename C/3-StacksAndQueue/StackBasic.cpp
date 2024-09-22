#include "iostream"

using namespace std;

#define MAXSIZE 100
#define ELEMENTTYPE int
#define endl '\n'

typedef struct Stack {
    int top;
    ELEMENTTYPE data[MAXSIZE];
} Stack;

void initial(Stack &stack, ELEMENTTYPE exp[], int size) {
    stack.top = size - 1;
    for (int i = 0; i < size; i++) {
        stack.data[i] = exp[i];
    }
}

//��ʼ��һ����ջ
void initial(Stack &stack)
{
    stack.top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack stack) {
    if (stack.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

//��ջ
int push(Stack &stack, ELEMENTTYPE c) {
    if ((stack.top + 1) == MAXSIZE) {
        return 0;
    } else {
        stack.data[++stack.top] = c;
        return 1;
    }
}

//��ջ
int pop(Stack &stack, ELEMENTTYPE &c) {
    if (isEmpty(stack)) {
        return 0;
    } else {
        c = stack.data[stack.top--];
        return 1;
    }
}

//��ջ��Ԫ��
int GetTop(Stack stack, ELEMENTTYPE &c)
{
    if (stack.top == -1)
    {
        return 0;
    } else {
        c = stack.data[stack.top];
        return 1;
    }
}