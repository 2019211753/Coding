#include "../TreeBasic.cpp"

using namespace std;

/**
 * 利用结点的右孩子指针rchild将一棵二叉树的叶子结点从左到右的顺序串成一个单链表（在题目中定义量指针head与tail，其中head指向第一个叶子结点
 * head初值为null，tail指向最后一个结点
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

