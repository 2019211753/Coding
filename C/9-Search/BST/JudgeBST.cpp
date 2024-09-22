#include "../../6-Tree/TreeBasic.cpp"

#define INF (-10000)

using namespace std;

//记录当前所访问结点在中序遍历下的前驱
int predt = INF;
/**
 * 判断一个树是否是二叉排序树
 * 可以用分治算法，也可以用中序遍历看序列是否递增，本题后者
 * @param bt 树的根结点
 * @return 是/否
 */
int judBST(Tree *bt) {
    int b1, b2;
    //空树 是二叉排序树
    if (bt == nullptr) {
        return 1;
    } else {
        b1 = judBST(bt->lchild);
        if (b1 == 0 || predt > bt->val) {
            return 0;
        }
        predt = bt->val;
        b2 = judBST(bt->rchild);
        return b2;
    }
}