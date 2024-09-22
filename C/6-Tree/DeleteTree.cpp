#include "TreeBasic.cpp"

//删除X及X的子树 递归
void deleteX(Tree *&tree)
{
    if (tree != nullptr)
    {
        deleteX(tree->lchild);
        deleteX(tree->rchild);
        free(tree);
    }
}

//在树中找到值为x的结点 递归
void find_del_X(Tree *tree, int x)
{
    if (tree != nullptr)
    {
        if (tree->lchild != nullptr)
        {
            if (tree->lchild->val == x)
            {
                deleteX(tree->lchild);
                tree->lchild = nullptr;
            } else {
                find_del_X(tree->lchild, x);
            }
        }
        if (tree->rchild != nullptr)
        {
            if (tree->rchild->val == x)
            {
                deleteX(tree->rchild);
                tree->rchild = nullptr;
            } else {
                find_del_X(tree->rchild, x);
            }
        }
    }
}

/**
 * 删除以二叉链表存储的二叉树中每个元素值为x的结点以及以它为根的子树，并释放相应的空间。
 */
void del(Tree *tree, int x)
{
    if (tree->val == x)
    {
        deleteX(tree);
    } else {
        find_del_X(tree, x);
    }
}



int main()
{
    Tree *root = initial();
    //方便调试
    cout << 1;
}