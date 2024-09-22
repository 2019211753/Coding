/**
 * ������������ö�������洢�ṹ���б�����������Ƿ�����ȫ��������
 *
 */
#include "../TreeBasic.cpp"

bool isComplete(Tree *tree)
{
    //������Ϊ��������
    if(tree == nullptr)
    {
        return true;
    }
    int front = -1, rear = -1;
    Tree *nodes[MAXSIZE];
    nodes[++rear] = tree;
    Tree *p;
    while (front < rear)
    {
        p = nodes[++front];
        //���������ս��ʱ���������ȫ������˵����һ���ұ����еĽ�㶼Ϊ�գ����ǳ�Ҫ����������֮ǰ�Ľ�㶼��Ϊ�ա�
        if (p != nullptr)
        {
            //��ʹ�ǿս��Ҳ�������
            nodes[++rear] = p->lchild;
            nodes[++rear] = p->rchild;
        } else {
            while (front < rear)
            {
                p = nodes[++front];
                if (p == nullptr)
                {
                    return false;
                }
            }
        }
    }
    return true;
}