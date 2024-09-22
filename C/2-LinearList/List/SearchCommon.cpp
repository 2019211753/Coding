#include "ListBasic.cpp"

/**
 * ����������ͷ���ĵ�������д�㷨�ҳ���������Ĺ������
 * @param l1 ��һ������
 * @param l2 �ڶ�������
 * @return �������
 */
List* searchFirstCommonNode(List *l1, List *l2)
{
    List *s, *l;
    int diff_length;
    if (l1->val > l2->val)
    {
        diff_length = l1->val - l2->val;
        l = l1->next;
        s = l2->next;
    } else {
        diff_length = l2->val - l1->val;
        l = l2->next;
        s = l1->next;
    }
    while (diff_length--)
    {
        l = l->next;
    }
    while (l != nullptr && l != s )
    {
        l = l->next;
        s = s->next;
    }
    return l;
}
