/**
 * 反转二叉树的左右子树
 */
#include "TreeBasic.cpp"

void reverseLeftRightChild(Tree *root)
{
    if (root != nullptr) {
        Tree *p = root->rchild;
        root->rchild = root->lchild;
        root->lchild = p;
        reverseLeftRightChild(root->lchild);
        reverseLeftRightChild(root->rchild);

    }
}

int main()
{
    Tree *r = initial();
    reverseLeftRightChild(r);
    cout << 1;
}