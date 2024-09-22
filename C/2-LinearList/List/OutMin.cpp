#include "ListBasic.cpp"

#define MAX 10000000

/**
 * ��һ����ͷ����ѭ������������ֵ��Ϊ�����������һ���㷨�������ҳ��������н��ֵ��С�Ľ�㲢�����
 * Ȼ�󽫸ýڵ����ɾ����ֱ���������Ϊֹ����ɾ����ͷ��㡣
 * @param l
 */
void output_delete(List *&l)
{
    while (l->next != l)
    {
        List *pre = l;
        List *p = l;
        int min = MAX;
        while (p->next != l)
        {
            if (p->next->val < min)
            {
               pre = p;
               min = p->next->val;
            }
            p = p->next;
        }
        cout << pre->next->val << " ";
        List *m = pre->next;
        pre->next = pre->next->next;
        free(m);
    }
    free(l);
}

int main()
{
    List *l;
    int array1[7] = {1, 2, 4, 3, 10, 5, 12};
    initial_head(l, array1, 7);
    // ����ѭ��������
    List *q = l;
    while (q->next != nullptr)
    {
        q = q->next;
    }
    q->next = l;
    output_delete(l);
    cout << 1;
}