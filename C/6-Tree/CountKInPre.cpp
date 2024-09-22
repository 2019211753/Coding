/**
 * ����ǰ����������е�k������ֵ��
 * ����ֵ>0���Ӷ���-1��Ϊû�ҵ��ı�־��
 * Ӧ�������+��֦��
 */
#include "TreeBasic.cpp"

int i = 1;
int PreNode(Tree *tree, int k)
{
    //-1��Ϊ��־���������������û�ҵ���k������֮���ҵ��ˣ��Ӷ���֦��
    if (tree == nullptr)
    {
        return -1;
    }
    //������ҵ���k��ֱ����ֹ�ݹ�
    if (i == k)
    {
        return tree->val;
    }
    //�������ҵ���k��ͬ����ֹ�ݹ�
    int left = PreNode(tree->lchild, k);
    if (left != -1)
    {
        return left;
    } else {
        return PreNode(tree->rchild, k);
    }

}