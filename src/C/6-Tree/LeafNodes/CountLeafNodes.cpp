#include "../TreeBasic.cpp"

/**
 * 计算给定二叉树的所有叶子结点数
 * 递归不影响num正常增加
 * @param root 根结点
 * @param num 叶子结点树
 */
void count(Tree *root, int &num) {
    if (root != nullptr) {
        count(root->lchild, num);
        count(root->rchild, num);
        if (root->lchild == nullptr && root->rchild == nullptr) {
            num++;
        }
    }
}
int countLeafNode(Tree *root) {
    int num = 0;
    count(root, num);
    return num;
}