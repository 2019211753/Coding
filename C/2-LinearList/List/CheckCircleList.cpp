#include "ListBasic.cpp"

/**
 * 判断单链表是否有环，如果有环返回环的起始点。
 * 设置快慢两个指针，快指针一次挪两个结点，慢指针一次一个。
 * 如果有环，那么这两个指针一定会在环上相遇。否则当快指针遇到null时就可以确定无环。
 * 易知相遇时，慢指针必然没有走过一整圈。设头结点到环的入口的距离为a，环的入口点沿着环的方向到相遇点的距离为x，
 * 环长为r，相遇时fast绕过了n圈。可列得 2(a+x) = a+n*r+X，即a = n*r-x。
 * 故可令一结点A在头结点处，一结点B在相遇处，当二者相遇时，就是环的入口处。
 * （当相遇时，A走过a距离，AB速度一样，由a = n*r-x，B肯定走了了n*r-x距离，n多少无所谓，肯定在入口处相遇。
 * @param l 链表
 * @return nullptr则无环，否则返回入口处结点。
 */
List* checkCircle(List *l)
{
    List *fast = l, *slow = l;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr)
    {
        return nullptr;
    }
    List *p1 = l, *p2 = slow;
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}