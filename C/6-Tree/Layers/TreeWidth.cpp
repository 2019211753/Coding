#include "../treeBasic.cpp"

/**
 * 求非空二叉树b的宽度（即具有节点数最多的那一层的结点个数）
 */
int W = 0;
int B[MAXSIZE] = {0};
void getWidth(Tree *root)
{
    if (root != nullptr) {
        B[W] = B[W] + 1;
        W++;
        getWidth(root->lchild);
        getWidth(root->rchild);
        W--;
    }
}

int main() {
    Tree *root = initial();
    getWidth(root);
    int x = -1;
    for (int i = 0; i < 10; ++i) {
        if (x < B[i])
        {
            x = B[i];
        }
    }
    cout << x;
}