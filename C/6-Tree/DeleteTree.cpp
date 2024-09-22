#include "TreeBasic.cpp"

//ɾ��X��X������ �ݹ�
void deleteX(Tree *&tree)
{
    if (tree != nullptr)
    {
        deleteX(tree->lchild);
        deleteX(tree->rchild);
        free(tree);
    }
}

//�������ҵ�ֵΪx�Ľ�� �ݹ�
void find_del_X(Tree *tree, int x)
{
    if (tree != nullptr)
    {
        if (tree->lchild != nullptr)
        {
            if (tree->lchild->val == x)
            {
                deleteX(tree->lchild);
                tree->lchild = nullptr;
            } else {
                find_del_X(tree->lchild, x);
            }
        }
        if (tree->rchild != nullptr)
        {
            if (tree->rchild->val == x)
            {
                deleteX(tree->rchild);
                tree->rchild = nullptr;
            } else {
                find_del_X(tree->rchild, x);
            }
        }
    }
}

/**
 * ɾ���Զ�������洢�Ķ�������ÿ��Ԫ��ֵΪx�Ľ���Լ�����Ϊ�������������ͷ���Ӧ�Ŀռ䡣
 */
void del(Tree *tree, int x)
{
    if (tree->val == x)
    {
        deleteX(tree);
    } else {
        find_del_X(tree, x);
    }
}



int main()
{
    Tree *root = initial();
    //�������
    cout << 1;
}