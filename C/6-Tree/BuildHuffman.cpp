/**
 * 构建哈夫曼树及计算WPL
 * 809不考代码
 */
#include "TreeBasic.cpp"

void insert(Tree *node[], int &bottom, int &top, Tree *root) {
    int i = bottom;
    for (; i <= top; ++i) {
        if (node[i]->val > root->val) {
            for (int j = ++top; j > i; --j) {
                node[j] = node[j - 1];
            }
            break;
        }

    }
    if (i == top + 1) {
        top++;
    }
    node[i] = root;
}

void getTwoMinimum(Tree *&one, Tree *&two, int &bottom, Tree *node[]) {
    one = node[++bottom];
    two = node[++bottom];
}

Tree* buildHuffman(int data[], int len) {
    Tree *node[MAXSIZE];
    for (int i = 0; i < len; ++i) {
        node[i] = create(data[i]);
    }
    int bottom = -1;
    int top = len - 1;
    while (bottom < top - 1) {
        Tree *one;
        Tree *two;
        getTwoMinimum(one, two, bottom, node);
        Tree *parent = create(one->val + two->val);
        parent->lchild = one;
        parent->rchild = two;
        insert(node, bottom, top, parent);
    }
    return node[top];
}

int calculateWPL(Tree *root, int len) {
    if (root->lchild == nullptr && root->rchild == nullptr)
    {
        return root->val * len;
    } else {
        return calculateWPL(root->lchild, len + 1) + calculateWPL(root->rchild, len + 1);
    }
}

int main() {
    int data[] = {2, 5, 7, 9, 13};
    int len = 5;
    Tree *root = buildHuffman(data, len);
    cout << calculateWPL(root, 0) << endl;
}