/**
 * 已知递增有序的单链表A、B(A、B中元素个数分别为m、n，且A、B都带有头结点)分别存储了一个集合，
 * 请设计算法，以求出两个集合A和B的差集A-B。将差集保存在单链表A中，并保持元素的递增有序性。
 *
 * 复杂度分析：
 * 时间复杂度：最差情况即B最大比A的最大还大，但B的第二大没A的最大大，即两个链表都走一遍, o(m + n) = o(max(m, n),
 * 最好情况为A或B走了其中一条的一边，如B的所有元素都比A大 时间复杂度为o(min(m, n))。空间复杂度：o(1)
 */

#include "ListBasic.cpp"

void remove(List *l1, List *l2) {
    while(l2->next != nullptr && l1->next != nullptr) {
        if(l2->next->val == l1->next->val) {
            List *p = l1->next;
            l2 = l2->next;
            l1->next = l1->next->next;
            free(p);
        } else if(l2->next->val > l1->next->val){
            l1 = l1->next;
        } else {
            l2 = l2->next;
        }
    }
}

int main() {
    List *l1;
    List *l2;
    int array0[5] = {1,    4, 6 ,7, 10};
    int array1[7] = {1, 2, 4,    7, 10, 11, 12};

    initial_head(l1, array1, 7);
    initial_head(l2, array0, 5);

    remove(l1, l2);

    output_head(l1);
}