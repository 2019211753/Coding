#include "iostream"
using namespace std;
#define endl '\n'

typedef struct List {
    int val;
    List *next;
} List;

// ��ͷ���ĳ�ʼ��
void initial_head(List *&list, int array[], int length) {
    list = (List*) malloc(sizeof (List));
    list->val = length;
    list->next = nullptr;
    List *temp = list;
    for (int i = 0; i < length; ++i) {
        List *newList = (List*) malloc(sizeof (List));
        newList->val = array[i];
        newList->next = nullptr;
        temp->next = newList;
        temp = temp->next;
    }
}

// ��ͷ���ĳ�ʼ��
void initial_no_head(List *&list, int array[], int length) {
    list = (List*) malloc(sizeof (List));
    list->val = array[0];
    list->next = nullptr;
    List *temp = list;
    for (int i = 1; i < length; ++i) {
        List *newList = (List*) malloc(sizeof (List));
        newList->val = array[i];
        newList->next = nullptr;
        temp->next = newList;
        temp = temp->next;
    }
}


// ��ͷ�������
void output_head(List *list) {
    list = list->next;
    while (list != nullptr) {
        cout << list->val << endl;
        list = list->next;
    }
    cout << "********" << endl;
}

// ��ͷ�������
void output_no_head(List *list) {
    while (list != nullptr) {
        cout << list->val << endl;
        list = list->next;
    }
    cout << "********" << endl;
}