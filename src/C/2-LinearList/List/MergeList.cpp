/**
 * 合并两个递增有序的链表为一个非递减有序的链表（含头结点），因为是要非递减有序，所以要尾插，若是要非递增，即头插
 *
 * 解1：
 * 以链表1的头结点作为新链表的头结点，设出一个指针C始终指向链表1的头结点，
 * 再设出两个指针BC分别指向两个链表下一个需要比较的结点。最后返回链表1的头结点。
 */
#include "ListBasic.cpp"

/*
 * 尾插法初始化链表
 *
 * list 需要初始化的链表的头结点
 * B 链表中存储的值
 * n 链表的长度（除结点外）
 */
void initialTail(List *&list, int array[], int n) {
    list = (List*) malloc(sizeof (List));
    list->next = nullptr;
    list->val = n;
    List *now = list;
    for (int i = 0; i < n; i++) {
        List *newList = (List*) malloc(sizeof (List));
        newList->val = array[i];
        now->next = newList;
        now = now->next;
    }
    now->next = nullptr;
}

/*
 * list1 链表1
 * list2 链表2
 */
void mergeTwoLists(List *l1, List *l2, List *&l3 ) {
    List *L1 = l1->next;
    List *L2 = l2->next;
    l3 = l1;
    l3->next = nullptr;
    free(l2);
    while (L1 != nullptr && L2 != nullptr) {
        if (L1->val >= L2->val) {
            l1->next = L2;
            l1 = l1->next;
            L2 = L2->next;
        } else {
            l1->next = L1;
            l1 = L1;
            L1 = L1->next;
        }
    }
    //如果一个链表遍历到最末了 直接把另一个链表接上
    if (L1 != nullptr) {
        l1->next = L1;
    }
    if (L2 != nullptr) {
        l1->next = L2;
    }
}

int main() {
    List *list;
    int array[3] = {1, 2, 4};
    initialTail(list, array, 3);

    List *list2;
    int array1[4] = {1, 3, 4};
    initialTail(list2, array1, 3);

    List *list3;
    mergeTwoLists(list, list2, list3);
    output_head(list3);

}
