/**
 * 二叉排序树
 * 特点：
 *      树的左子树均小于等于根结点，右子树均大于等于根结点
 *      当对树进行中序遍历时，得到的是递增序列，反过来，由一个二叉排序树不可能还原出构成他的数组，利用这个性质
 *      可以通过输出中序遍历序列从而判断一棵树是否是二叉排序树
 */
#include "../../6-Tree/TreeBasic.cpp"

#define INF (-10000)

using namespace std;

/**
 * 查找二叉排序树
 * @param bt 根结点
 * @param key 关键字
 * @return 是否查找到
 */
Tree* BSTSearch(Tree *bt, int key) {
    if (bt == nullptr) {
        return nullptr;
    } else {
        if (bt->val == key) {
            return bt;
        } else if (bt->val > key){
            return BSTSearch(bt->lchild, key);
        } else {
            return BSTSearch(bt->rchild, key);
        }
    }
}

/**
 * 插入二叉排序树
 * @param bt 根结点 注意使用引用数据类型 就可以不需要知道 bt 的父节点
 * @param key 关键字
 * @return 是否插入成功
 */
int BSTInsert(Tree *&bt, int key) {
    //当遍历到空结点则查找失败，也说明没有 key 对应的结点，则对这个null结点（某某结点的原本指向null的子结点）赋值
    if (bt == nullptr) {
        bt = (Tree*) malloc(sizeof(Tree));
        bt->val = key;
        bt->lchild = nullptr;
        bt->rchild = nullptr;
        return 1;
    } else {
        if (bt->val == key) {
            return -1;
        } else if (bt->val > key ){
            return BSTInsert(bt->lchild, key);
        } else {
            return BSTInsert(bt->rchild, key);
        }
    }
}

/**
 * 根据数组建立二叉排序树
 * 如 5 2 1 4 3 6
 *          5
 *        /  \
 *       2    6
 *     /   \
 *   1      4
 *         /
 *       3
 * @param bt 根结点
 * @param array 数组
 * @param n 数组长度
 */
void CreateBST(Tree *&bt, int array[], int n) {
    int i;
    bt = nullptr;
    for (i = 0; i < n; ++i) {
        BSTInsert(bt, array[i]);
    }
}

/**
 * 删除某结点
 * 下面是一种移植方法 即删除 5 后把 4（左子树的最右端） 换到 5 处，并且把 4 的左子树接到 2 的右子树上
 * （ 4 不是 5 的左子节点）
 *          5                 4
 *        /  \              /  \
 *       2    6   →        2    6
 *     /   \   \         /  \    \
 *   1      4   7      1     3    7
 *         /
 *       3
 * 另外一种为 删除 5 后把 6（右子树的最左端） 换到 5 处，把 6 的右子树接到 4 的右子树上（ 6 是 5 的右子结点）
 * @param p 被删除的结点节点
 * @return 删除成功
 */
int Delete(Tree *&p) {
    Tree *q, *s;
    //如果 p 的右子树为空，把 p 的左子树接到 p 的双亲结点的左子树上，即直接令 p = p->lchild
    if (p->rchild == nullptr) {
        q = p;
        p = p->lchild;
        free(q);
    //左子树为空同理
    } else if(p->lchild == nullptr) {
        q = p;
        p = p->rchild;
        free(q);
    //如果左右子树都不空
    } else {
        q = p;
        //找到 p 的左子树的最右端结点 s，即 p 的左子树的最大结点，s 仅可能有左子树
        s = p->lchild;
        while (s->rchild != nullptr) {
            //记录 q 为 s 的双亲结点
            q = s;
            s = s->rchild;
        }
        //把 p 的值替换成 s 的值
        p->val = s->val;
        //如果 s 不是 p 的左子结点，把 s 的左子树接为 q 的右子树
        if (q != p) {
            q->rchild = s->lchild;
        //如果 s 是 p 的左子结点，把 s 的左子树接为 p 的左子树
        } else {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return 1;
}

int BSTDelete(Tree *&bt, int key) {
    Tree *p = BSTSearch(bt, key);
    if (p == nullptr) {
        return -1;
    } else {
        return Delete(p);
    }
}


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

