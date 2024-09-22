#include "../../6-Tree/TreeBasic.cpp"

#define INF (-10000)

using namespace std;

//��¼��ǰ�����ʽ������������µ�ǰ��
int predt = INF;
/**
 * �ж�һ�����Ƿ��Ƕ���������
 * �����÷����㷨��Ҳ��������������������Ƿ�������������
 * @param bt ���ĸ����
 * @return ��/��
 */
int judBST(Tree *bt) {
    int b1, b2;
    //���� �Ƕ���������
    if (bt == nullptr) {
        return 1;
    } else {
        b1 = judBST(bt->lchild);
        if (b1 == 0 || predt > bt->val) {
            return 0;
        }
        predt = bt->val;
        b2 = judBST(bt->rchild);
        return b2;
    }
}