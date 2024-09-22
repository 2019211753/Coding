/**
 * 字符串树
 * 请设计一个算法，将给定的表达式树(二叉树)转换为等价的中缀表达式(通过括号反映操作符的计算次序)并输出。
 * 注意：
   树中至少包含一个运算符。
   当运算符是负号时，左儿子为空，右儿子为需要取反的表达式。
   树中所有叶节点的值均为非负整数。
   叶子结点均为操作数。
 * 样例：
 * 输入：二叉树[+, 12, *, null, null, 6, 4, null, null, null, null]如下图所示：
        +
       / \
      12  *
         / \
        6   4

 * 输出：12+(6*4)
 * 数据范围
   给定二叉树的非空结点数量保证不超过 1000。
   给定二叉树保证能够转化为合法的中缀表达式。
 */
#include "TreeBasic.cpp"

void btreeToExp(Tree *root, int deep)
{
    //空结点返回
    if (root == nullptr)
    {
        return;
    //若为叶子结点 输出操作数 不加括号
    } else if (root->lchild == nullptr && root->rchild == nullptr)
    {
        cout << root->val;
    } else {
        //如果有子表达式则加一层括号
        if (deep > 1)
        {
            cout << "(";
        }
        btreeToExp(root->lchild, deep+1);
        //输出操作符
        cout << root->val;
        btreeToExp(root->rchild, deep+1);
        //如果有子表达式则加一层括号
        if (deep > 1)
        {
            cout << ")";
        }
    }
}

void btreeToe(Tree *root)
{
    btreeToExp(root, 1);
}
