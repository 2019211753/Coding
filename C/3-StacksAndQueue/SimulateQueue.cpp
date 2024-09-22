/**
 * ����������ջs1��s2��ģ��һ�����У����������Ԫ��Ϊint�ͣ�ջ��Ԫ�����ΪmaxSize��ʵ�ָö��е���ӣ����Ӻ��п�
 */

#include "StackBasic.cpp"

int inQueue(Stack &s1, Stack &s2, int x)
{
    int temp;
    // ���s1��s2�������򷵻�0�����ʧ��
    if (s1.top == MAXSIZE - 1 && s2.top == MAXSIZE - 1)
    {
        return 0;
    } else {
        // ���s1������ֱ����ջ
        if (s1.top != MAXSIZE - 1)
        {
            push(s1, x);
            return 1;
        } else {
            // ���s1����s2�գ���s1ȫ�뵽s2
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
                // ���s1����s2���գ���˵��֮ǰ��s1�Ĳ����뵽��s2����ת�Ƶ�s2�Ļ������е�˳�������
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