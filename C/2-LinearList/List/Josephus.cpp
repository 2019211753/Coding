#include "ListBasic.cpp"

void josephus(List *list, int k)
{
    List *p = list;
    List *q;
    int i = 1;
    while (p->next != p)
    {
        if (i == k - 1)
        {
            q = p->next;
            p->next = q->next;
            cout << q->val << " ";
            free(q);
            q = nullptr;
            i = 1;
        } else {
            i++;
        }
        p = p->next;
    }
    cout << p->val;
    free(p);
    p = nullptr;
}

int main()
{
    List *list;
    int n = 10;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    initial_no_head(list, array, n);
    List *tlist = list;
    while (tlist->next != nullptr)
    {
        tlist = tlist->next;
    }
    tlist->next = list;
    int k = 3;
    josephus(list, k);

}