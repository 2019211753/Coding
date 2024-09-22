#include "../TreeBasic.cpp"

/**
 * 查找值为x的结点，并打印它的所有祖先
 */
void printAncestor(Tree *root, int x)
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
                if (p->val == x)
                {
                    for (int i = 0; i <= top; ++i) {
                        cout << nodes[i]->val << " ";
                    }
                    cout << endl;
                }
                //记录最近访问的结点
                r = p;
                //结点访问完后相当于遍历完以该节点为根的子树，将p置null
                //不同于前中序遍历，后序遍历在一棵树上遍历结束时是在根结点，而不为null，所以要手动置null，别重新遍历左子树了
                p = nullptr;
            }
        }
    }
}

Tree *B[MAXSIZE];
int j = -1;
/**
 * 输出根结点到每个叶子结点的路径
 * 下为递归法。也可用非递归后序遍历得到。
 */
void getLeafNodePath(Tree *root) {
    if (root != nullptr) {
        //访问到某个结点 录入路径
        B[++j] = root;
        if (root->rchild == nullptr && root->lchild == nullptr) {
            for (int i = 0; i <= j; ++i) {
                cout << B[i]->val << " ";
            }
            cout << endl;
            return;
        }
        getLeafNodePath(root->lchild);
        getLeafNodePath(root->rchild);
        //左右结点都遍历完了 则这颗树上的结点路径已经输出完了，输出另一条路的路径
        j--;
    }
}

