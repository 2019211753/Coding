/**
 * 二叉树的代码无非就是研究：什么时候入栈，什么时候出栈，什么时候访问，这三个的时机有时出栈和访问相同，有时均不相同。
 *
 * 递归三要素：
 *  定义：要做什么事情，比如二叉树的前序遍历是先遍历父亲节点，然后左节点、右节点
 *  拆分：差分成“同样”的问题，但规模变小，二叉树的前序遍历就是拆成左子树和右子树，对左子树和右子树分别做前序遍历
 *  结束条件：遇到空节点停止。
 *
 * 分治：
 * 通常来说，分治法的函数是有返回值的。
 * 分治法三要素：
 *  定义：要做什么事情
 *  拆分与合并问题：
 *  结束条件。
 * 分治思想与二叉树的后序遍历模板极其相似。因为分治算法的套路是 分解 -> 解决（触底）-> 合并（回溯），
 * 先左右分解，再处理合并，回溯就是在退栈，即相当于后序遍历。
 *
 * 总之，递归拆分成子问题，要相信这个函数“必定能完成它的任务”。而不要细想每一次完成的细节。
 */
#include "iostream"

#define MAXSIZE 100

using namespace std;

typedef struct Tree {
    int val;
    Tree *lchild;
    Tree *rchild;
} Tree;

Tree* create(int val) {
    Tree *tree = (Tree*) malloc(sizeof (Tree));
    tree->lchild = nullptr;
    tree->rchild = nullptr;
    tree->val = val;
    return tree;
}

int length = 8;
Tree* initial() {
    Tree *root = create(1);
    root->lchild = create(2);
    root->lchild->lchild = create(3);
    root->lchild->rchild = create(4);
    root->lchild->rchild->lchild = create(5);
    root->lchild->rchild->rchild = create(6);
    //原来是7 改成4用来测试其他代码
    root->rchild = create(7);
    root->rchild->lchild = create(8);
    return root;
}


//树型
//          1
//        /   \
//      2      7
//    /  \    /
//  3     4  8
//      /  \
//     5    6
//前序遍历序列：
//1 2 3 4 5 6 7 8
//中序遍历序列：
//3 2 5 4 6 1 8 7
//后序遍历序列：
//3 5 6 4 2 8 7 1

void visit(Tree *node)
{

}

//递归模板
void recurse(Tree *root)
{
    //结束条件
    if (root != nullptr)
    {
        //在这对root操作为前序 根结点入栈时访问
        //visit(root);
        recurse(root->lchild);
        //在这为中序 左子树全部出栈后 第一次返回到根结点时访问
        //visit(root);
        recurse(root->rchild);
        //在这为后序 左右子树全部出栈时访问 第二次返回到根结点时访问
        //visit(root);
        //当左右根子树均遍历完且出栈时，根结点出栈
    }
}

//天勤的这三种写法有点取巧，栈怪怪的，尤其是这种实现方式的后序遍历，不能做输出祖先的题
//非递归实现前序遍历二叉树
//根-左-右
void preorderNonRecursion_1(Tree *root) {
    cout << "前序遍历序列：" << endl;
    if (root != nullptr) {
        Tree *node[MAXSIZE];
        int top = -1;
        Tree *p;
        node[++top] = root;
        while (top != -1) {
            //当访问到某结点时，直接出栈
            p = node[top--];
            visit(p);
            //先让右子树入栈
            if (p->rchild != nullptr)
            {
                node[++top] = p->rchild;
            }
            //再让左子树入栈，在栈顶
            if (p->lchild != nullptr) {
                node[++top] = p->lchild;
            }
        }
    }
    cout << endl;
}

//非递归实现中序遍历二叉树
//左-根-右
void inorderNonRecursion_1(Tree *root) {
    cout << "中序遍历序列：" << endl;
    if (root != nullptr) {
        Tree *node[MAXSIZE];
        int top = -1;
        Tree *p;
        p = root;
        //当栈不为空且p不为null时循环继续
        //和前序遍历的非递归形式不一样，需要加 p!=null，因为当遍历到整棵树的根节点且根节点有右子树时，
        //此时栈为空，但还需要继续遍历
        while (p != nullptr || top != -1) {
            while (p != nullptr) {
                node[++top] = p;
                p = p->lchild;
            }
            //当左子树为null或左子树遍历完 该结点出栈
            //不必判断top空不空，肯定不空
            //因为若空 那么说明本次循环之前栈就是空的，且当前p没入栈，则p==nullptr
            //那么就不可能进入本次循环
            p = node[top--];
            //对结点的某操作
            visit(p);
            //遍历该结点的右子树
            p = p->rchild;
        }
    }
    cout << endl;
}

//非递归实现后序遍历二叉树
//左-右-根，和前序遍历的根-左-右相比，如果将前序遍历的先左后右变成先右后左遍历，即根-右-左，
//最后将这样最终输出的顺序逆序，即得到后序遍历
void postorderNonRecursion_1(Tree *root) {
    cout << "后序遍历序列：" << endl;
    if (root != nullptr) {
        Tree *array[MAXSIZE];
        int j = -1;
        Tree *node[MAXSIZE];
        int top = -1;
        Tree *p;
        node[++top] = root;
        while (top != -1) {
            p = node[top--];
            array[++j] = p;
            if (p->lchild != nullptr) {
                node[++top] = p->lchild;
            }
            if (p->rchild != nullptr)
            {
                node[++top] = p->rchild;
            }
        }
        while (j != -1) {
            visit(array[j--]);
        }
    }
    cout << endl;
}

//王道版本前序遍历二叉树非递归版
//栈和递归版的一致
void preorderNonRecursion_2(Tree *root)
{
    Tree *p = root;
    Tree *nodes[MAXSIZE];
    int top = -1;
    while (p != nullptr || top != -1)
    {
        //走到最左边
        if (p != nullptr)
        {
            visit(p);
            nodes[++top] = p;
            p = p->lchild;
        } else {
        //左子树访问完，第一次返回到根结点，根结点出栈，向右走访问右子树
            p = nodes[top--];
            p = p->rchild;
        }
    }
}

//跟前序的栈相同，只是访问顺序变了
void inorderNonRecursion_2(Tree *root)
{
    Tree *p = root;
    Tree *nodes[MAXSIZE];
    int top = -1;
    while (p != nullptr || top != -1)
    {
        if (p != nullptr)
        {
            nodes[++top] = p;
            p = p->lchild;
        } else {
            p = nodes[top--];
            visit(p);
            p = p->rchild;
        }
    }
}

//后序遍历需要把握根结点出栈的时机，是第一次返回到根结点出还是第二次，所以要加一个判断条件。
//本代码使用一个辅助指针r指向最近访问过的结点。也可以在结点中增加一个标志域，记录是否已被访问。
void postorderNonRecursion_2(Tree *root)
{
    Tree *p = root;
    Tree *r = nullptr;
    Tree *nodes[MAXSIZE];
    int top = -1;
    while (p != nullptr || top != -1)
    {
        if (p != nullptr)
        {
            nodes[++top] = p;
            p = p->lchild;
        } else {
            //读栈顶结点（非出栈）需要判断是第一次返回的还是第二次返回的 再决定是否出栈
            p = nodes[top];
            //若右子树存在，且未被访问过
            if (p->rchild != nullptr && p->rchild != r)
            {
                //转向右
                p = p->rchild;
            } else {
                p = nodes[top--];
                visit(p);
                //记录最近访问的结点
                r = p;
                //结点访问完后相当于遍历完以该节点为根的子树，将p置null
                //不同于前中序遍历，后序遍历在一棵树上遍历结束时是在根结点，而不为null，所以要手动置null，别重新遍历左子树了
                p = nullptr;
            }
        }
    }
}

//int main() {
//    Tree *root = initial_head();
//    preorderNonRecursion(root);
//    inorderNonRecursion(root);
//    postorderNonRecursion(root);
//}