#include "ListBasic.cpp"

/**
 * 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
 * @param list 单链表
 * @param x 要删除的x值
 */
void deleteX(List *&list, int x)
{
    List *p;
    if (list == nullptr)
    {
        return;
    }
    if (list->val == x)
    {
        // 这里不会断链，因为deleteX(&list, x) 传进去的list实际上是前驱结点的next指针域，而不是list的后继结点
        // free(p)释放了这个指针域
        p = list;
        list = list->next;
        free(p);
        deleteX(list, x);
    } else {
        deleteX(list->next, x);
    }
}

/*
 * 逆序输出每个节点的值（不含头结点，在外部函数预先处理）
 */
void print(List *list)
{
    if (list->next != nullptr)
    {
        print(list->next);
    }
    cout << list->val << endl;
}

void Ignore_Head(List *l)
{
    if (l->next != nullptr)
    {
        print(l->next);
    }
}

int main() {
    List *l;
    int array[5] = {1, 5, -1, 4 ,7};
    initial_head(l, array, 5);
    print(l->next);
}
