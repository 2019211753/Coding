#include "../TreeBasic.cpp"

/**
 * 递归
 * 返回一棵二叉树中任意两个结点p、q的最近公共祖先
 * 也可以分别得到两个结点的公共祖先列表，然后取最靠后的交集结点。
 */
Tree* lowestCommonAncestor(Tree *root, Tree *p, Tree *q)
{
    //如果遍历到叶子节点，返回null，说明这个分支没找到p或q
    if (root == nullptr)
    {
        return nullptr;
    }
    //找到p或q，立刻返回
    if (root==p || root==q) {
        return root;
    }
    //分别在左右子树找这两个结点，返回的right和left即搜索到的p或q结点
    Tree *left = lowestCommonAncestor(root->lchild, p, q);
    Tree *right = lowestCommonAncestor(root->rchild, p, q);
    //如果当前结点的左右都找到了p和q，即p和q是兄弟，返回该结点，即公共结点，由于递归，越早返回越深，则最近。
    if (left && right) {
        return root;
    }
    //如果仅在右边找到一个，返回右边
    //若p或q其中一个是另一个的子结点，由上可知不继续递归
    //返回到整棵树的根结点时，right和left一个为null一个不为null，为null的为p或q较高的一层，即祖先节点。
    if (left == nullptr) {
        return right;
    } else {
        return left;
    }
}