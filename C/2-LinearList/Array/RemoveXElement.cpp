#include "iostream"
using namespace std;

typedef struct List {
    int *array;
    int length;
} L;

/**
 * ɾ��������ֵΪx��Ԫ��
 * ʹ�� k ��¼��ֹ��ǰ����Ϊ i ��Ԫ�أ��Ѿ������˼���ֵΪ x ��Ԫ�ء��õ�ǰԪ����ǰ�ƶ� k ��λ�á�
 * @param l ����
 * @param x ��ɾ����Ԫ��
 */
void remove_1(L &l, int x)
{
    int k = 0;
    int i = 0;
    while (i < l.length)
    {
        if (l.array[i] != x)
        {
            l.array[i - k] = l.array[i];
        } else {
            k++;
        }
        i++;
    }
    l.length = l.length - k;
}

/**
 * ɾ��������ֵΪx��Ԫ��
 * ��ָ�������Ϊ ָ�����û�е��� x ��Ԫ��
 * ��ָ�������Ϊ ָ���Ҳ�ȫ�ǵ��� x ��Ԫ��
 * ��̫�� ���ڿ���˼�� ���ȶ�
 */
void remove_2(L &l, int x)
{
    int i = 0, j = l.length - 1;
    while (i <= j)
    {
        while (i <= j && l.array[i] != x)
        {
            i++;
        }
        if (i <= j)
        {
            while (i <= j && l.array[j] == x)
            {
                j--;
            }
            if (i <= j)
            {
                l.array[i] = l.array[j];
                //�������ÿ�һ��
                l.array[j] = x;
                i++;
                j--;
            }
        }
    }
    l.length = j + 1;
}

/**
 * ������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ��������Ԫ�ص�ֵ����ͬ��
 * �����������������Ϊ����ɾ��Ԫ���ƶ������Ƚ϶࣬������ֻ��Ҫo(1)���ɡ�
 */
bool removeDuplicate(List &l)
{
    if (l.length == 0)
    {
        return false;
    }
    // ָ�� i ʼ��ָ��һ����ͬ���е�һ������Ҳ�������ظ����е����һ����
    int i = 0, j = 1;
    for (; j < l.length;)
    {
        // ��� j �� i ָ�������ͬ��˵�� j ָ���������һ�������� j ָ�����Ҳ�ǵ�ǰһ�����ĵ�һ����
        // ֱ���ƶ� j �� i+1 ����ͬʱ i��j ����
        // �� j �� i ָ�������ͬ����ֻ�� j ������ɨ����һ����
        if (l.array[i] != l.array[j])
        {
            l.array[++i] = l.array[j];
        }
        j++;
    }
    l.length = i + 1;
    return true;
}


void output(L l) {
    for (int i = 0; i < l.length; ++i) {
        cout << l.array[i] << " ";
    }
}

int main()
{
    List l;
    int array[] = {1 , 2, 7, 1, 2, 6, 7, 2};
    l.array = array;
    l.length = 8;
    removeDuplicate(l);
    output(l);
}