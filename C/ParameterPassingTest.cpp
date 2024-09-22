// ���Դ���
// *p = x �Ǹı�ָ���ָ�򣬼��ı�pָ��Ŀռ�� ָ��Ŀռ䣨ֵ�� p = &x�Ǹı�ָ�򣬼��ı�pָ��Ŀռ�
// p = c �Ǹı�ָ��Ŀռ䡣
// �ں��������У�Ҫ�ı�p�Ŀռ䲻��p = c�������Ǹı俽����ָ����Ҫ����&p
#include "iostream"

using namespace std;

typedef struct List {
    int value;
    List *next;
} List;

typedef struct TestList {
    List list;
} TestList;

//�ı���ͨ��������
//����&����Ч
void test(int &a) {
    a++;
}

//�ı���������
//��Ч
void testArray(int a[]) {
    a[0] = 1000;
}

//�ı�ṹ������
//����&����Ч
void test(List &l) {
    l.value++;
}

//�ı�ṹ�屾��
//����&����Ч
void test(List &l1, List l2) {
    l1 = l2;
}

//�ı�ָ����ͨ���ݵ�ָ�������
//����&Ҳ��Ч �޸�aָ��ĵ�ַ �����ݵ�ֵ
void test(int *a)
{
    (*a)++;
}

//�ı�ָ��ṹ�����ݵ�ָ��� ��ͨ��������
//����&Ҳ��Ч
void test(List *l)
{
    l->value++;
}

//�ı�ָ��ṹ�����ݵ�ָ�뱾��
//����&����Ч
void test(List *&l1, List *l2)
{
    l1 = l2;
}

void test_next(List *&l1, List *l2)
{
    l1->next = l2;
}


//�ı�ָ��ṹ�����ݵ�ָ��� ָ��ṹ�����ݵ�ָ������
//�͸���ͨ����һ�� ���ü�&
void test(TestList *tlist, List list) {
    tlist->list = list;
}

//���� ������ͨint���� �ں����иı����ǵ�ֵ������& ������ͨ�ṹ����� �ں����иı����ǵ�ֵ�͵�ַ��������&
//��ָ��洢����ָ�����ݵĵ�ַ ��ͨ�������ַ�޸�����ַָ������ݵ�ֵ ע�� ��������Ҳ��ָ��
//����ָ��ָ��ĳ��ָ��ṹ������ ��ô����ֱ�Ӹı�ṹ���е��κ�Ԫ�ص�ֵ���ַ ָ��������ͱ��� ����ֱ�Ӹı�����ֵ
//��ͨ��ָ����Ըı��κ�ֵ ���ܺ���������
//�������Ҫ�޸�ָ���ֵ ��ָ���λ�þͱ���Ҫ��&
int main() {
    int num_1 = 1;
    int *x = &num_1;
    test(x);
    cout << *x << endl;

    int num1[2];
    num1[0] = 1;
    testArray(num1);
    cout << num1[0] << endl;

    List *list_1 = (List*) malloc(sizeof(List));
    list_1->value = -100;
    list_1->next = nullptr;
    test(list_1);
    cout << list_1->value << endl;

    List *list_3 = (List*) malloc(sizeof(List));
    list_3->value = 3;
    list_3->next = nullptr;
    List *list_10 = (List*) malloc(sizeof(List));
    list_10->value = 10;
    list_10->next = nullptr;
    list_3->next = list_10;
    /** ������������Ҫͬʱ���� **/
    //�ı�list_1��ָ�� ����
//    test(list_1, list_10);
//    cout << list_1->value << endl;

    //�ı�list_3.next��ָ�� Ҳ����
//    test(list_3->next, list_1);
//    cout << list_3->next->value << endl;

    //��list_3.next����������һ��ָ�����test �����Ըı�list_3.next ˵����ʵ������������ͬ��ָ��
    List *list_test = list_3->next;
    //�����Ըı�test
    test(list_test, list_1);
    //���Ըı�nextָ�����ڵݹ�ɾ�������ʹ��Ч���ܺá��ұ��θı�Ҳ���Ըı�list3��next
    list_test = list_3->next;
    test_next(list_test, list_1);
    cout << list_3->next->value << endl;

    int num2 = 1;
    test(num2);
    cout << num2;

    List list2;
    list2.value = 3;
    test(list2);
    cout << list2.value << endl;

    List list3;
    list3.value = 100;
    test(list2, list3);
    cout << list2.value << endl;

    TestList *tlist = (TestList*) malloc(sizeof (TestList));
    tlist->list = *list_1;
    test(tlist, list3);
    cout << tlist->list.value << endl;

}