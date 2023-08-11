/**
 * 假设二叉树采用二叉链表存储结构，判别给定二叉树是否是完全二叉树。
 *
 */
#include "../TreeBasic.cpp"

bool isComplete(Tree *tree)
{
    //树空则为满二叉树
    if(tree == nullptr)
    {
        return true;
    }
    int front = -1, rear = -1;
    Tree *nodes[MAXSIZE];
    nodes[++rear] = tree;
    Tree *p;
    while (front < rear)
    {
        p = nodes[++front];
        //当遍历到空结点时，如果是完全二叉树说明这一行右边所有的结点都为空，这是充要条件。并且之前的结点都不为空。
        if (p != nullptr)
        {
            //即使是空结点也纳入队列
            nodes[++rear] = p->lchild;
            nodes[++rear] = p->rchild;
        } else {
            while (front < rear)
            {
                p = nodes[++front];
                if (p == nullptr)
                {
                    return false;
                }
            }
        }
    }
    return true;
}