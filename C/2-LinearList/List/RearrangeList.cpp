/**
 * һ������ n ��Ԫ�ص��������� L=(a1,a2,��,an-2,an-1,an)��

  * ����Ҫ�����еĽ������������򣬵õ�һ�������� L��=(a1,an,a2,an-1,a3,an-2��)
  * ����1��
    ���룺1->2->3->4

    �����1->4->2->3
    ����2��
    ���룺1->2->3->4->5

    �����1->5->2->4->3
  * ���ݷ�Χ
    1��n��1000,
    1��ai��10000
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

        //����ĳ���
        int k = 1;
        while(p->next != nullptr)
        {
            p = p->next;
            k++;
        }
        //ȡһ�� ��ʣ�µ�һ��ͨ��ͷ�巨����
        int l = 1;
        p = head;
        while(l < (k + 1) / 2)
        {
            p = p->next;
            l++;
        }
        w = p->next;
        p->next = nullptr;
        //ͷ�巨����
        p = w;
        while(p != nullptr)
        {
            w = p->next;
            p->next = q->next;
            q->next = p;
            p = w;
        }

        //�ϲ�����
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