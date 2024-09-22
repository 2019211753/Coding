#include "ListBasic.cpp"

/**
 * 给定两个有头结点的单链表，编写算法找出两个链表的公共结点
 * @param l1 第一个链表
 * @param l2 第二个链表
 * @return 公共结点
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
