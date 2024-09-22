#include "../TreeBasic.cpp"

/**
 * �������������������Ҷ�ӽ����
 * �ݹ鲻Ӱ��num��������
 * @param root �����
 * @param num Ҷ�ӽ����
 */
void count(Tree *root, int &num) {
    if (root != nullptr) {
        count(root->lchild, num);
        count(root->rchild, num);
        if (root->lchild == nullptr && root->rchild == nullptr) {
            num++;
        }
    }
}
int countLeafNode(Tree *root) {
    int num = 0;
    count(root, num);
    return num;
}