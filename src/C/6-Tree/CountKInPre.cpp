/**
 * 查找前序遍历序列中第k个结点的值。
 * 本题值>0。从而用-1作为没找到的标志。
 * 应该算分治+剪枝？
 */
#include "TreeBasic.cpp"

int i = 1;
int PreNode(Tree *tree, int k)
{
    //-1作为标志，代表在这棵树下没找到第k个，反之则找到了，从而剪枝。
    if (tree == nullptr)
    {
        return -1;
    }
    //根结点找到第k个直接终止递归
    if (i == k)
    {
        return tree->val;
    }
    //左子树找到第k个同理终止递归
    int left = PreNode(tree->lchild, k);
    if (left != -1)
    {
        return left;
    } else {
        return PreNode(tree->rchild, k);
    }

}