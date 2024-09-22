/**
 * 已知一棵树的层次遍历序列及每个结点的度，编写算法构造此树的孩子-兄弟链表
 */
#include "../TreeBasic.cpp"

void construct(Tree *&root, int layer[], int degree[], int n)
{
    Tree **p = new Tree *[MAXSIZE];
    //i用来对层次遍历数组做遍历
    //j用来记录对当前结点的子结点进行遍历
    //d用来记录当前结点的子结点数量
    //k用来记录当前结点的子结点序号（区间）
    int i, j, d, k = 0;
    //初始化
    for (i = 0; i < n; i++)
    {
        p[i] = new Tree ();
        p[i]->val = layer[i];
        p[i]->lchild = p[i]->rchild = nullptr;
    }
    for (i = 0; i < n; i++)
    {
        d = degree[i];
        //如果度不等于0
        if (d != 0)
        {
            k++;
            //此时k为当前结点的第一个子结点 插入当前结点的左子节点
            //其它子结点依次插入到上一个子结点的右子节点（兄弟）
            p[i]->lchild = p[k];
            for (j = 2; j <= d; j++)
            {
                k++;
                p[k-1]->rchild = p[k];
            }
        }
    }
    root = p[0];
    delete []p;
}

//原树型
//          1
//        /   \
//      2      7
//    /  \    /
//  3     4  8
//      /  \
//     5    6
//转化成二叉树存储
//         1
//        /
//       2
//     /   \
//    3     7
//    \    /
//     4  8
//     /
//    5
//     \
/       6

int main()
{
    int array[] = {1, 2, 7, 3, 4, 8, 5, 6};
    int degree[] = {2, 2, 1, 0, 2, 0, 0, 0};
    int n = 8;
    Tree *root = create(8);
    construct(root, array, degree, n);
    cout << 1;
}


