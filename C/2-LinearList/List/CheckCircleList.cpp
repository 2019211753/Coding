#include "ListBasic.cpp"

/**
 * �жϵ������Ƿ��л�������л����ػ�����ʼ�㡣
 * ���ÿ�������ָ�룬��ָ��һ��Ų������㣬��ָ��һ��һ����
 * ����л�����ô������ָ��һ�����ڻ������������򵱿�ָ������nullʱ�Ϳ���ȷ���޻���
 * ��֪����ʱ����ָ���Ȼû���߹�һ��Ȧ����ͷ��㵽������ڵľ���Ϊa��������ڵ����Ż��ķ���������ľ���Ϊx��
 * ����Ϊr������ʱfast�ƹ���nȦ�����е� 2(a+x) = a+n*r+X����a = n*r-x��
 * �ʿ���һ���A��ͷ��㴦��һ���B��������������������ʱ�����ǻ�����ڴ���
 * ��������ʱ��A�߹�a���룬AB�ٶ�һ������a = n*r-x��B�϶�������n*r-x���룬n��������ν���϶�����ڴ�������
 * @param l ����
 * @return nullptr���޻������򷵻���ڴ���㡣
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