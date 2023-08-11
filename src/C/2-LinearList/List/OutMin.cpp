#include "ListBasic.cpp"

#define MAX 10000000

/**
 * 设一个带头结点的循环单链表，其结点值均为正整数，设计一个算法，反复找出单链表中结点值最小的结点并输出，
 * 然后将该节点从中删除，直到单链表空为止，再删除表头结点。
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
    // 整成循环单链表
    List *q = l;
    while (q->next != nullptr)
    {
        q = q->next;
    }
    q->next = l;
    output_delete(l);
    cout << 1;
}