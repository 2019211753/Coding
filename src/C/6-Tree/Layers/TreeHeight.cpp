#include "../TreeBasic.cpp"

/**
 * 假设二叉树采用二叉链表存储结构，设计一个非递归算法求二叉树的高度。
 * 这个算法可以知道当前访问结点的层数，即知道每层的结点状态，所以可以用来求某层/每层的结点个数，树的最大宽度等
 */
int btDepth1(Tree *tree)
{
    //树空直接输出高度0
    if(tree == nullptr)
    {
        return 0;
    }
    //队列首位
    int front = -1, rear = -1;
    Tree *nodes[MAXSIZE];
    //last标记当前遍历的结点所在的层的最右结点 level表示最高层数
    int last = 0, level = 0;
    nodes[++rear] = tree;
    Tree *p;
    while (front < rear)
    {
        //将某节点的左右子结点入队，是一层一层的入
        p = nodes[++front];
        if (p->lchild != nullptr)
        {
            nodes[++rear] = p->lchild;
        }
        if (p->rchild != nullptr)
        {
            nodes[++rear] = p->rchild;
        }
        //当遍历到某层最后一个结点，那么下一层的结点也全都入队了
        //增加层数的标志，一层中只有一次，避免同一层的结点遍历过程中加了好几次level
        if (front == last)
        {
            //遍历完一层后再让树的层数+1
            level++;
            //更新最右结点序号为下一层最右结点序号
            last = rear;
        }
    }
    return level;
}

//分治
int btDepth2(Tree *tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    int left = btDepth2(tree->lchild);
    int right = btDepth2((tree->rchild));
    if (left < right)
    {
        return right + 1;
    } else {
        return left + 1;
    }
}

//递归
int H1 = 0;
void btDepth3(Tree *tree, int h)
{
    if (tree == nullptr)
    {
        h--;
        if (h > H1)
        {
            H1 = h;
        }
        return;
    }
    btDepth3(tree->lchild, h+1);
    btDepth3(tree->rchild, h+1);
}

//求以孩子兄弟表示法存储的森林的叶子节点数。
int H2 = 0;
void forestDepth(Tree *tree, int h)
{
    if (tree == nullptr)
    {
        h--;
        if (h > H2)
        {
            H2 = h;
        }
        return;
    }
    btDepth3(tree->lchild, h+1);
    btDepth3(tree->rchild, h);
}

int main()
{
    Tree *tree = initial();
    cout << btDepth2(tree) << endl;
    btDepth3(tree, 1);
    cout << H1;
}