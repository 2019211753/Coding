/**
 * 线索二叉树应用
 * 809不考线索二叉树
 */
#include "TreeBasic.cpp"

//线索二叉树
typedef struct TBTnode {
    //判断一个线索二叉树的结点的特征应该结合 左右子结点是否为null 及 ltag和rtag
    //当ltag == 0 && lchild != null 时，二叉树左子节点不空
    //当ltag == 1 && lchild != null 时，二叉树左子节点空，但有前驱结点
    //当ltag == 1 && lchild == null 时，二叉树左子节点空，但是该序遍历的第一个结点，无前驱
    //当rtag == 0 && rchild != null 时，二叉树右子节点不空
    //当rtag == 1 && rchild != null 时，二叉树右子节点空，且有后继结点
    //当rtag == 1 && rchild == null 时，二叉树右子节点空，但是该序遍历的最后一个结点，无后继
    //当 tag 为 0 时，无论如何对应的子结点也非空，逆反结论成立，但 tag 为 1时，对应子结点不一定非空
    int ltag;
    int rtag;
    int val;
    TBTnode *lchild;
    TBTnode *rchild;
} TBTnode;

//初始化的时候需要将所有tag都置为0
TBTnode* create_Thread(int val) {
    TBTnode *tree = (TBTnode*) malloc(sizeof (TBTnode));
    tree->lchild = nullptr;
    tree->rchild = nullptr;
    tree->ltag = 0;
    tree->rtag = 0;
    tree->val = val;
    return tree;
}

TBTnode* initial_Thread() {
    TBTnode *root = create_Thread(1);
    root->lchild = create_Thread(2);
    root->lchild->lchild = create_Thread(3);
    root->lchild->rchild = create_Thread(4);
    root->lchild->rchild->lchild = create_Thread(5);
    root->lchild->rchild->rchild = create_Thread(6);

    root->rchild = create_Thread(7);
    root->rchild->lchild = create_Thread(8);
    return root;
}

//构建中序线索二叉树
void buildInThread(TBTnode *p, TBTnode *&pre) {
    if (p != nullptr) {
        //中序遍历
        buildInThread(p->lchild, pre);
        //如果该结点的左子树为空 则令 ltag 为 1，左子节点为全局下的上一个结点
        if (p->lchild == nullptr) {
            p->ltag = 1;
            p->lchild = pre;
        }

        //这样写也可以，直接对当前结点的右子节点赋值，不需要最后在外部函数操作了。当然，可能不太符合“中序遍历”的思想
        //若右子结点为空，令 rtag = 1
        if (p->rchild == nullptr) {
            p->rtag = 1;
        }
        //若上一个结点不为空且右子结点为空，则上一个结点的右子结点设为当前结点
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = p;
        }

        //天勤是这样写的 但是需要在被外部函数调用时对最后一个结点做操作：pre->rtag = 1;
//        if (pre != nullptr && pre->rchild == nullptr) {
//            pre->rtag = 1;
//            pre->rchild = p;
//        }

        pre = p;
        p = p->rchild;
        buildInThread(p, pre);
    }
}

//查找中序线索二叉树中结点t的子树上中序下的最后一个节点
//即右子树的最右结点 若没有右子节点 则自身
TBTnode* getInLast(TBTnode *root) {
    while(root != nullptr && root->rtag == 0) {
        root = root->rchild;
    }
    return root;
}

//查找中序线索二叉树中结点t的子树上中序下的第一个
//即左子树的最左结点 若没有左子节点 则自身
TBTnode* getInFirst(TBTnode *root) {
    while(root != nullptr && root->ltag == 0) {
        root = root->lchild;
    }
    return root;
}

//查找中序线索二叉树中结点t的子树上中序下的后继
TBTnode* getInNext(TBTnode *root) {
    if (root->rtag != 0) {
        return root->rchild;
    } else {
        return getInFirst(root->rchild);
    }
}

//遍历中序线索二叉树
void inOrder(TBTnode *root) {
    for (TBTnode *p = getInFirst(root); p != nullptr; p = getInNext(p)) {
        cout << p->val;
    }
}

//查找中序线索二叉树中结点t的中序下的前驱
//若有左子树，则为左子树的最右结点，否则就是ltag = 1下的lchild，总之都是lchild
TBTnode *getInBefore(TBTnode *root) {
    if (root != nullptr && root->ltag == 0) {
        return getInLast(root->lchild);
    } else {
        return root->lchild;
    }
}

//查找中序线索二叉树中结点t的前序下的后继
//即左子结点，若没有，则右子结点，若没有，则父节点的右子结点，则t.rchild.rchild，若父节点没右子结点，则为有右子节点的祖先结点的右子节点
TBTnode *getInBeforeAfter(TBTnode *node) {
    //这里前两个不用判断是不是null了 题设就不是null
    if (node->ltag == 0) {
        return node->lchild;
    }
    if (node->rtag == 0) {
        return node->rchild;
    }
    while (node != nullptr && node->rtag != 0) {
        node = node->rchild;
    }
    //如果有这么一个有右子结点的祖先，就输出它的右子结点，否则就没后继结点了，返回null
    if (node != nullptr) {
        return node->rchild;
    } else {
        return nullptr;
    }
}

//构建前序线索二叉树
void buildPreThread(TBTnode *p, TBTnode *&pre) {
    if (p != nullptr) {
        if (p->lchild == nullptr) {
            p->ltag = 1;
            p->lchild = pre;
        }
        //这样写也可以 不需要最后在外部函数操作了
//        if (p->rchild == nullptr) {
//            p->rtag = 1;
//        }
//        if (pre != nullptr && pre->rchild == nullptr) {
//            pre->rchild = p;
//        }
//        天勤是这样写的 但是需要在被外部函数调用时对最后一个结点做操作：pre->rtag = 1;
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rtag = 1;
            pre->rchild = p;
        }

        pre = p;
        //这里判断ltag == 0而不判断p->lchild =! null
        //是因为如果没有左子树 上面的代码会导致p->lchild = pre，如果当前结点不是根节点，那么不为null，导致程序错误，进入死循环
        //同结构体处论述，若 p->ltag == 0，那么左子结点肯定非空
        if (p->ltag == 0) {
            buildPreThread(p->lchild, pre);
        }
        //理由同上，如果当前结点的右子结点原本为空，在遍历完左子树后，如果左子结点不为空，
        //则右子结点指向它的左子节点，不为null，又会死循环
        if (p->rtag == 0) {
            buildPreThread(p->rchild, pre);
        }
    }
}

//遍历前序线索二叉树
void preorder(TBTnode *root) {
    if (root != nullptr) {
        TBTnode *p = root;
        while(p != nullptr) {
            while (p->ltag == 0) {
                p = p->lchild;
                //do something
            }
            //do something
            p = p->rchild;
        }
    }
}

//构建后序线索二叉树
void buildPostThread(TBTnode *p, TBTnode *&pre) {
    if (p != nullptr) {
        buildPostThread(p->lchild, pre);
        buildPostThread(p->rchild, pre);
        //对下一个结点操作时 才对前驱结点的rtag和rchild进行改变，则中序遍历下最后一个结点（最右）的rtag仍然为0
        //但是第一个结点的ltag和lchild会改变
        if (p->lchild == nullptr) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
    }
}

int main() {
    TBTnode *root = initial_Thread();
    TBTnode *pre = nullptr;
    buildInThread(root, pre);
    inOrder(root);
}

