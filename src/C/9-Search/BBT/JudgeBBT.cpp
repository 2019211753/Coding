//判断一棵树是否是二叉平衡树
#include "../../6-Tree/TreeBasic.cpp"

#define INF (-10000)

using namespace std;

//很有意义的一道题，让我猛然发现分治和后序遍历是思路是完全一致的。另外，递归的，需要用到下一层返回的两个数据
//（需要两个返回值）的情况可以用&传两个参
void judge(Tree *tree, int &height, int &balance)
{
    //左右子树的高度和是否平衡
    int b1, b2;
    int h1, h2;
    //如果是空树，平衡，且高度为0
    if (tree == nullptr)
    {
        height = 0;
        balance = 1;
    } else {
        //分治判断左右子树，分别得到左右子树的高度，判断子树是否平衡
        judge(tree->lchild, h1, b1);
        judge(tree->rchild, h2, b2);
        //左右子树有一个不平衡则总体不平衡
        if (!b1 || !b2)
        {
            balance = 0;
        }
        //当前树不平衡
        if (abs(h1 -h2) > 1)
        {
            balance = 0;
        //平衡
        } else {
            balance = 1;
            height = max(h1, h2) + 1;
        }
    }
}

int jud(Tree *tree)
{
    if (judge(tree) != -1)
    {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    Tree *tree = initial();
}