#include "../../6-Tree/TreeBasic.cpp"

using namespace std;

//从大到小输出二叉排序树中所有值不小于k的关键字
void outNoLowerThanK(Tree *tree, int k)
{
    if (tree == nullptr)
    {
        return;
    } else {
        outNoLowerThanK(tree->rchild, k);
        if (tree->val >= k)
        {
            cout << tree->val;
        } else {
            return;
        }
        outNoLowerThanK(tree->lchild, k);
    }
}

/**
 * 编写一个递归算法，在一棵有n个结点，随机建立起来的二叉排序树上查找第k（1<=k<=n）小的元素，并返回指向该结点的指针。要求算法的平均时间复杂度为O(log2_n)
 * 二叉排序树的每个节点中除data, lchild, rchild等数据成员外，增加一个count成员，保存以该节点为根的子树上的结点个数。（本答案直接把val当作count了）
 * 思路：设二叉排序树的根结点为*t，根据结点存储的信息，有以下几种情况：
 *      t->lchild为空时：
 *          1)若t->rchild非空且k==1，则*t为第k小的元素，查找成功
 *          2)若t->rchild非空且k！=1，则第k小的元素在*t的右子树上
*       t->lchild非空时
 *          1)若t->lchild->count==k-1，*t即为第k小的元素，查找成功
 *          2)若t->lchild->count>k-1，第k小的元素必在*t的左子树，继续到*t的左子树种查找。
 *          3)若t->child->count<k-1，第k小的元素必在右子树，继续搜索右子树，寻找第k-(t->lchild->count+1)小的元素
 * 是递归思想不是分治思想
 */
Tree* searchSmallKth(Tree* tree, int k)
{
    if (k < 1 || k > tree->val)
    {
        return nullptr;
    }
    if (tree->lchild == nullptr)
    {
        if (k == 1)
        {
            return tree;
        } else {
            return searchSmallKth(tree->rchild, k - 1);
        }
    } else {
        if (tree->lchild->val == k - 1)
        {
            return tree;
        }
        if (tree->lchild->val > k - 1)
        {
            return searchSmallKth(tree->lchild, k);
        }
        if (tree->lchild->val < k - 1)
        {
            return searchSmallKth(tree->rchild, k - (tree->lchild->val + 1));
        }
    }
}