#include "ListBasic.cpp"

/**
 * ���һ���ݹ��㷨��ɾ������ͷ���ĵ�����L������ֵΪx�Ľ��
 * @param list ������
 * @param x Ҫɾ����xֵ
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
        // ���ﲻ���������ΪdeleteX(&list, x) ����ȥ��listʵ������ǰ������nextָ���򣬶�����list�ĺ�̽��
        // free(p)�ͷ������ָ����
        p = list;
        list = list->next;
        free(p);
        deleteX(list, x);
    } else {
        deleteX(list->next, x);
    }
}

/*
 * �������ÿ���ڵ��ֵ������ͷ��㣬���ⲿ����Ԥ�ȴ���
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
