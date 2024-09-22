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

//³õÊ¼»¯Ò»¸ö¿ÕÕ»
void initial(Stack &stack)
{
    stack.top = -1;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
int isEmpty(Stack stack) {
    if (stack.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

//ÈëÕ»
int push(Stack &stack, ELEMENTTYPE c) {
    if ((stack.top + 1) == MAXSIZE) {
        return 0;
    } else {
        stack.data[++stack.top] = c;
        return 1;
    }
}

//³öÕ»
int pop(Stack &stack, ELEMENTTYPE &c) {
    if (isEmpty(stack)) {
        return 0;
    } else {
        c = stack.data[stack.top--];
        return 1;
    }
}

//¶ÁÕ»¶¥ÔªËØ
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