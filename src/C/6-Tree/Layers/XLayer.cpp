/**
 * 求结点值为x的结点在树中的层数
 */
#include "../TreeBasic.cpp"

/**
 * 解法一：层次遍历
 */
typedef struct ST {
    Tree *tree;
    int lay;
};

ST* create(Tree *tree, int lay) {
    ST *st = (ST*) malloc(sizeof(ST));
    st->tree = tree;
    st->lay = lay;
}

void getLayer(int &layer, int num, Tree *root) {
    layer = -1;
    ST *st[MAXSIZE];
    int head = 0;
    int tail = 0;
    //将根节点入队
    st[++tail] = create(root, 1);
    while (head != tail) {
        if (layer == -1) {
            //将队头结点出队
            ST *btNode = st[++head % MAXSIZE];
            //如果队头结点的值等于x，得到层数
            if (btNode->tree->val == num) {
                layer = btNode->lay;
            }
            //否则将左右子树入队，由于是队列，先入左子树，并且将结点层数+1
            if (btNode->tree->lchild != nullptr) {
                st[++tail] = create(btNode->tree->lchild, btNode->lay + 1);
            }
            if (btNode->tree->rchild != nullptr) {
                st[++tail] = create(btNode->tree->rchild, btNode->lay + 1);
            }
        } else {
            break;
        }
    }
}

//解法2：递归
//设置全局变量的话需要回溯
int L = 1;
void getLayer_0(Tree *root, int x) {
    if (root != nullptr) {
        if (root->val == x) {
            cout << L << endl;
        }
        //到下一层 层数+1
        ++L;
        getLayer_0(root->lchild, x);
        getLayer_0(root->rchild, x);
        //左右子树都遍历完成 返回上一层 层数-1 回溯
        --L;
    }
}
//不回溯 都差不多
void getLayer_1(Tree *root, int x, int l) {
    if (root != nullptr) {
        if (root->val == x) {
            cout << l << endl;
        }
        //到下一层 层数+1
        getLayer_1(root->lchild, x, L+1);
        getLayer_1(root->rchild, x, L+1);
    }
}

