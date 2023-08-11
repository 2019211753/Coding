/**
 * 请利用两个栈s1，s2来模拟一个队列，假设队列中元素为int型，栈中元素最多为maxSize，实现该队列的入队，出队和判空
 */

#include "StackBasic.cpp"

int inQueue(Stack &s1, Stack &s2, int x)
{
    int temp;
    // 如果s1和s2均满，则返回0，入队失败
    if (s1.top == MAXSIZE - 1 && s2.top == MAXSIZE - 1)
    {
        return 0;
    } else {
        // 如果s1不满，直接入栈
        if (s1.top != MAXSIZE - 1)
        {
            push(s1, x);
            return 1;
        } else {
            // 如果s1满，s2空，把s1全入到s2
            if (isEmpty(s2))
            {
                while (s2.top != MAXSIZE - 1 && !isEmpty(s1))
                {
                    pop(s1, temp);
                    push(s2, temp);
                }
                push(s1, x);
                return 1;
            } else {
                // 如果s1满，s2不空，则说明之前有s1的部分入到了s2，再转移到s2的话，队列的顺序就乱了
                return 0;
            }
        }
    }
}

int deQueue(Stack &s1, Stack &s2, int &x)
{
    int temp;
    if (s1.top == -1 && s2.top == -1)
    {
        return 0;
    } else {
        if (s2.top != -1)
        {
            pop(s2, x);
            return 1;
        } else {
            while (!isEmpty(s1)) {
                pop(s1, temp);
                push(s2, temp);
            }
            pop(s2, x);
            return 1;
        }
    }
}