/**
 * 一个包含 n 个元素的线性链表 L=(a1,a2,…,an-2,an-1,an)。

  * 现在要对其中的结点进行重新排序，得到一个新链表 L′=(a1,an,a2,an-1,a3,an-2…)
  * 样例1：
    输入：1->2->3->4

    输出：1->4->2->3
    样例2：
    输入：1->2->3->4->5

    输出：1->5->2->4->3
  * 数据范围
    1≤n≤1000,
    1≤ai≤10000
 */
#include "iostream"

typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode;

class Solution {
public:
    void rearrangedList(ListNode* head) {
        ListNode *p = head;
        ListNode *q = (ListNode*)malloc(sizeof(ListNode));
        q->next = nullptr;
        ListNode *w;

        //链表的长度
        int k = 1;
        while(p->next != nullptr)
        {
            p = p->next;
            k++;
        }
        //取一半 将剩下的一半通过头插法逆序
        int l = 1;
        p = head;
        while(l < (k + 1) / 2)
        {
            p = p->next;
            l++;
        }
        w = p->next;
        p->next = nullptr;
        //头插法逆序
        p = w;
        while(p != nullptr)
        {
            w = p->next;
            p->next = q->next;
            q->next = p;
            p = w;
        }

        //合并链表
        p = head;
        q = q->next;
        while(p != nullptr && q != nullptr)
        {
            w = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = w;
        }

    }
};