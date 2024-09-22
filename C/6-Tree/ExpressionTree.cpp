/**
 * �ַ�����
 * �����һ���㷨���������ı��ʽ��(������)ת��Ϊ�ȼ۵���׺���ʽ(ͨ�����ŷ�ӳ�������ļ������)�������
 * ע�⣺
   �������ٰ���һ���������
   ��������Ǹ���ʱ�������Ϊ�գ��Ҷ���Ϊ��Ҫȡ���ı��ʽ��
   ��������Ҷ�ڵ��ֵ��Ϊ�Ǹ�������
   Ҷ�ӽ���Ϊ��������
 * ������
 * ���룺������[+, 12, *, null, null, 6, 4, null, null, null, null]����ͼ��ʾ��
        +
       / \
      12  *
         / \
        6   4

 * �����12+(6*4)
 * ���ݷ�Χ
   �����������ķǿս��������֤������ 1000��
   ������������֤�ܹ�ת��Ϊ�Ϸ�����׺���ʽ��
 */
#include "TreeBasic.cpp"

void btreeToExp(Tree *root, int deep)
{
    //�ս�㷵��
    if (root == nullptr)
    {
        return;
    //��ΪҶ�ӽ�� ��������� ��������
    } else if (root->lchild == nullptr && root->rchild == nullptr)
    {
        cout << root->val;
    } else {
        //������ӱ��ʽ���һ������
        if (deep > 1)
        {
            cout << "(";
        }
        btreeToExp(root->lchild, deep+1);
        //���������
        cout << root->val;
        btreeToExp(root->rchild, deep+1);
        //������ӱ��ʽ���һ������
        if (deep > 1)
        {
            cout << ")";
        }
    }
}

void btreeToe(Tree *root)
{
    btreeToExp(root, 1);
}
