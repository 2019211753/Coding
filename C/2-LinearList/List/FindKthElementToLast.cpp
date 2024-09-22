/**
 * 双指针
 * 已知一个带有表头结点的单链表，假设该链表只给出了头指针head。
 * 在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第k(k为正整数）个位置上的结点。
 * 若查找成功，算法输出该结点的data值，并返回1；否则，只返回0。
 */

#include "ListBasic.cpp"

int findTheElement(List *list, int k) {
    List *list1 = list;
    List *list2 = list;
    int num = 0;
    while (list2->next != nullptr) {
        list2 = list2->next;
        //注意 如果用list.next != null判断的话，这里的边界条件为k - 1
        //num指list2指针在list1后的第num个指针
        if (num < k - 1) {
            ++num;
        } else {
            list1 = list1->next;
        }
    }
    if (list1 == list) {
        return 0;
    } else {
        cout << list1->val << endl;
        return 1;
    }
}

int main() {
    int array[] = {1, 4, 7, 5, 6, 9};
    List *list;
    initial_head(list, array, 6);
    findTheElement(list, 7);
}
