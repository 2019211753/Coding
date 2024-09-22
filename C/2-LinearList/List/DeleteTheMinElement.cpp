/**
 * 设计一个算法删除单链表L(有头结点）中的一个最小值结点。
 *
 * 注意单链表的删除操作一定要记住它的前驱结点。
 */

#include "ListBasic.cpp"

void deleteElement(List *l) {
    //最小值的前驱结点
    List *minPrior = l;
    List *now = l;
    while(now->next != nullptr) {
        if(minPrior->next->val > now->next->val) {
            minPrior = now;
        }
        now = now->next;
    }

    List *min = minPrior->next;
    minPrior->next = min->next;
    free(min);
}

int main() {
    List *l;
    int array[5] = {1, 5, -1, 4 ,7};
    initial_head(l, array, 5);
    output_head(l);
    deleteElement(l);
    output_head(l);
}

