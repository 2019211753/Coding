#include "../TreeBasic.cpp"

using namespace std;

/**
 * ���ý����Һ���ָ��rchild��һ�ö�������Ҷ�ӽ������ҵ�˳�򴮳�һ������������Ŀ�ж�����ָ��head��tail������headָ���һ��Ҷ�ӽ��
 * head��ֵΪnull��tailָ�����һ�����
 */
void tandem(Tree *root, Tree *&head, Tree *&tail) {
    if (root != nullptr) {
        tandem(root->lchild, head, tail);
        tandem(root->rchild, head, tail);
        if (root->lchild == nullptr && root->rchild == nullptr) {
            if (head == nullptr) {
                head = root;
                tail = root;
            } else {
                tail->rchild = root;
                tail = root;
            }
        }
    }
}
void tandemLeafNode(Tree *root) {
    Tree *head = create(-1);
    Tree *tail = create(-1);
    tandem(root, head, tail);
}

