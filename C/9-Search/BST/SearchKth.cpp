#include "../../6-Tree/TreeBasic.cpp"

using namespace std;

//�Ӵ�С�������������������ֵ��С��k�Ĺؼ���
void outNoLowerThanK(Tree *tree, int k)
{
    if (tree == nullptr)
    {
        return;
    } else {
        outNoLowerThanK(tree->rchild, k);
        if (tree->val >= k)
        {
            cout << tree->val;
        } else {
            return;
        }
        outNoLowerThanK(tree->lchild, k);
    }
}

/**
 * ��дһ���ݹ��㷨����һ����n����㣬������������Ķ����������ϲ��ҵ�k��1<=k<=n��С��Ԫ�أ�������ָ��ý���ָ�롣Ҫ���㷨��ƽ��ʱ�临�Ӷ�ΪO(log2_n)
 * ������������ÿ���ڵ��г�data, lchild, rchild�����ݳ�Ա�⣬����һ��count��Ա�������Ըýڵ�Ϊ���������ϵĽ�������������ֱ�Ӱ�val����count�ˣ�
 * ˼·��������������ĸ����Ϊ*t�����ݽ��洢����Ϣ�������¼��������
 *      t->lchildΪ��ʱ��
 *          1)��t->rchild�ǿ���k==1����*tΪ��kС��Ԫ�أ����ҳɹ�
 *          2)��t->rchild�ǿ���k��=1�����kС��Ԫ����*t����������
*       t->lchild�ǿ�ʱ
 *          1)��t->lchild->count==k-1��*t��Ϊ��kС��Ԫ�أ����ҳɹ�
 *          2)��t->lchild->count>k-1����kС��Ԫ�ر���*t����������������*t���������ֲ��ҡ�
 *          3)��t->child->count<k-1����kС��Ԫ�ر���������������������������Ѱ�ҵ�k-(t->lchild->count+1)С��Ԫ��
 * �ǵݹ�˼�벻�Ƿ���˼��
 */
Tree* searchSmallKth(Tree* tree, int k)
{
    if (k < 1 || k > tree->val)
    {
        return nullptr;
    }
    if (tree->lchild == nullptr)
    {
        if (k == 1)
        {
            return tree;
        } else {
            return searchSmallKth(tree->rchild, k - 1);
        }
    } else {
        if (tree->lchild->val == k - 1)
        {
            return tree;
        }
        if (tree->lchild->val > k - 1)
        {
            return searchSmallKth(tree->lchild, k);
        }
        if (tree->lchild->val < k - 1)
        {
            return searchSmallKth(tree->rchild, k - (tree->lchild->val + 1));
        }
    }
}