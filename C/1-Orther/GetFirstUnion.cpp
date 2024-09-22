/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int data;
 *     ListNode *next;
 *     ListNode(int x) : data(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while(p != q) {
            if(p) p = p->next;
            else p = headB;
            if (q) q = q->next;
            else q = headA;
        }
        return p;
    }
};

作者：邓泽军
        链接：https://www.acwing.com/solution/content/1773/
来源：AcWing
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。