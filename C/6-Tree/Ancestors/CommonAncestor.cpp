#include "../TreeBasic.cpp"

/**
 * �ݹ�
 * ����һ�ö������������������p��q�������������
 * Ҳ���Էֱ�õ��������Ĺ��������б�Ȼ��ȡ���Ľ�����㡣
 */
Tree* lowestCommonAncestor(Tree *root, Tree *p, Tree *q)
{
    //���������Ҷ�ӽڵ㣬����null��˵�������֧û�ҵ�p��q
    if (root == nullptr)
    {
        return nullptr;
    }
    //�ҵ�p��q�����̷���
    if (root==p || root==q) {
        return root;
    }
    //�ֱ���������������������㣬���ص�right��left����������p��q���
    Tree *left = lowestCommonAncestor(root->lchild, p, q);
    Tree *right = lowestCommonAncestor(root->rchild, p, q);
    //�����ǰ�������Ҷ��ҵ���p��q����p��q���ֵܣ����ظý�㣬��������㣬���ڵݹ飬Խ�緵��Խ��������
    if (left && right) {
        return root;
    }
    //��������ұ��ҵ�һ���������ұ�
    //��p��q����һ������һ�����ӽ�㣬���Ͽ�֪�������ݹ�
    //���ص��������ĸ����ʱ��right��leftһ��Ϊnullһ����Ϊnull��Ϊnull��Ϊp��q�ϸߵ�һ�㣬�����Ƚڵ㡣
    if (left == nullptr) {
        return right;
    } else {
        return left;
    }
}