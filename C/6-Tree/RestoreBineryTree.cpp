/**
 * 还原二叉树
 */
#include "TreeBasic.cpp"

//k = pos[i]，i为结点值，k为该结点在中序遍历数组中的位置 、
int pos[MAXSIZE];

int length_0 = 8;
int pre_0[] = {1, 2, 3, 4, 5, 6, 7, 8};
int in_0[] = {3, 2, 5, 4, 6, 1, 8, 7};
//前中
//          1
//        /   \
//      2      7
//    /  \    /
//  3     4  8
//      /  \
//     5    6

int length_1 = 10;
int in_1[] = {4, 2, 8, 5, 9, 1 , 6, 10,3 ,7};
int post_1[] = {4, 8, 9, 5, 2, 10, 6, 7, 3, 1};
//后中
//              1
//           /    \
//         /       \
//       2          3
//     /   \       /  \
//   4      5    6     7
//         / \    \
//       8    9    10

int length_full = 7;
int full[] = {1, 2, 3, 4, 5, 6, 7};
//            1
//          /  \
//        /     \
//      2        5
//    /  \     /  \
//  3     4  6     7

/**
 * 记住中序遍历是遍历完左子树，然后根结点，然后右子树
 * 前序遍历是根结点，左子树，右子树
 *
 * pl为以当前遍历的结点为根结点的树的子结点的序号 在前序遍历数组中 的左区间 以此类推
 *
 * 先假设左孩子存在，右孩子存在，直接return写逻辑，然后再在逻辑中加入边界条件中断递归
 *
 * @param pl 当前结点在前序遍历数组中的左区间
 * @param pr 当前结点在前序遍历数组中的右区间
 * @param il 当前结点在中序遍历数组中的右区间
 * @param ir 当前结点在中序遍历数组中的右区间
 * @return
 */
Tree* dfs_pre_in(int pl, int pr, int il, int ir) {
    //如果在前序遍历中的左区间大于了右区间，则这个区间没有结点
    if (pl > pr || pl < 0 || pr > length_1 - 1) {
        return nullptr;
    }
    //当前结点在中序遍历数组中的索引
    int k = pos[pre_0[pl]];
    Tree* root = create(pre_0[pl]);
    //左孩子在前序遍历数组中的左区间自增 1 即 pl + 1
    //左孩子在前序遍历数组中的右区间为前序遍历数组的左区间 + 以当前结点左子树的结点个数（即 k - il）
    //即 pl + k - il
    //在中序遍历数组中的左区间不变
    //在中序遍历数组中的右区间为当前结点的索引 - 1
    root->lchild = dfs_pre_in(pl + 1, pl + k - il, il, k - 1);
    //右孩子在前序遍历数组中的左区间为左孩子右区间 + 1
    //右孩子在前序遍历数组中的右区间不变
    //在中序遍历数组中的左区间为当前结点的索引 + 1
    //在中序遍历数组中的右区间不变
    root->rchild = dfs_pre_in(pl + k - il + 1, pr, k + 1, ir);
    return root;
}

Tree* buildTree_pre_in() {
    for (int i = 0; i < length_0; ++i) {
        pos[in_0[i]] = i;
    }
    return dfs_pre_in(0, length_0 - 1, 0, length_0 - 1);
}

/**
 * 后序遍历的顺序为左子树→右子树→根结点
 */
Tree* dfs_post_in(int pl, int pr, int il, int ir) {
    if (pl > pr || pl < 0 || pr > length_1 - 1) {
        return nullptr;
    }
    int k = pos[post_1[pr]];
    Tree* root = create(post_1[pr]);
    root->lchild = dfs_post_in(pl, pr - 1 - (ir - k), il, k - 1);
    root->rchild = dfs_post_in(pr - (ir - 1), pr - 1, k + 1, ir);
    return root;
}

Tree* buildTree_post_in() {
    for (int i = 0; i < length_1; ++i) {
        pos[in_1[i]] = i;
    }
    return dfs_post_in(0, length_1 - 1, 0, length_1 - 1);
}

/**
 * 由满二叉树的前序遍历得到后序遍历
 * 模仿一般二叉树前+中的代码，确定左右子树的区间，递归到叶子结点。让左子树先存进去，然后左子树，然后根。
 * 满二叉树之所以不需要中序区间，是因为他能得到左右子树分别的结点数。起的作用和中序遍历序列的一样。
 * 或者这样想：前序遍历是根左右，后序遍历是左右根。将前序遍历的根不变，左右子树颠倒，最后再将整个颠倒即可得到后序遍历。
 * @param pre 前序遍历数组
 * @param begin 当前结点所在树 在前序遍历数组中的左区间
 * @param end 右区间
 * @param post 后序遍历栈
 * @param bottom 栈底
 */
void dfs_pre(int pre[], int begin, int end, int post[], int &bottom)
{
    if (begin == end) {
        post[++bottom] = pre[begin];
        return;
    }
    int leftBegin = begin + 1;
    int leftEnd = begin + (end - 1 - begin) / 2 + 1;
    int rightBegin = leftEnd + 1;
    int rightEnd = end;
    if (leftBegin <= leftEnd) {
        dfs_pre(pre, leftBegin, leftEnd, post, bottom);
    }

    if (rightBegin <= rightEnd) {
        dfs_pre(pre, rightBegin, rightEnd, post, bottom);
    }
    post[++bottom] = pre[begin];

}

void build_FullBinary_pre(int pre[], int post[], int n) {
    int stack_bottom = -1;
    dfs_pre(pre, 0, n - 1, post, stack_bottom);
}

int main() {
    int post[length];
    build_FullBinary_pre(full, post, length_full);
}
