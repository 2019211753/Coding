// 测试传参
// *p = x 是改变指向的指向，即改变p指向的空间的 指向的空间（值） p = &x是改变指向，即改变p指向的空间
// p = c 是改变指向的空间。
// 在函数参数中，要改变p的空间不能p = c，那样是改变拷贝的指向，需要传参&p
#include "iostream"

using namespace std;

typedef struct List {
    int value;
    List *next;
} List;

typedef struct TestList {
    List list;
} TestList;

//改变普通数据内容
//不加&不生效
void test(int &a) {
    a++;
}

//改变数组内容
//生效
void testArray(int a[]) {
    a[0] = 1000;
}

//改变结构体内容
//不加&不生效
void test(List &l) {
    l.value++;
}

//改变结构体本身
//不加&不生效
void test(List &l1, List l2) {
    l1 = l2;
}

//改变指向普通数据的指针的内容
//不加&也生效 修改a指向的地址 的内容的值
void test(int *a)
{
    (*a)++;
}

//改变指向结构体数据的指针的 普通数据内容
//不加&也生效
void test(List *l)
{
    l->value++;
}

//改变指向结构体数据的指针本身
//不加&不生效
void test(List *&l1, List *l2)
{
    l1 = l2;
}

void test_next(List *&l1, List *l2)
{
    l1->next = l2;
}


//改变指向结构体数据的指针的 指向结构体数据的指针内容
//和改普通数据一样 不用加&
void test(TestList *tlist, List list) {
    tlist->list = list;
}

//综上 对于普通int变量 在函数中改变它们的值必须用& 对于普通结构体变量 在函数中改变它们的值和地址都必须用&
//而指针存储的是指向数据的地址 你通过这个地址修改它地址指向的内容的值 注意 数组引用也是指针
//比如指针指向某非指针结构体数组 那么可以直接改变结构体中的任何元素的值或地址 指向基本类型变量 可以直接改变它的值
//即通过指针可以改变任何值 不受函数的限制
//但是如果要修改指针的值 即指向的位置就必须要用&
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
    /** 下面这三个不要同时测试 **/
    //改变list_1的指针 可以
//    test(list_1, list_10);
//    cout << list_1->value << endl;

    //改变list_3.next的指针 也可以
//    test(list_3->next, list_1);
//    cout << list_3->next->value << endl;

    //将list_3.next拷贝给另外一个指针变量test 不可以改变list_3.next 说明这实际上是两个不同的指针
    List *list_test = list_3->next;
    //但可以改变test
    test(list_test, list_1);
    //可以改变next指针域，在递归删除结点中使用效果很好。且本次改变也可以改变list3的next
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