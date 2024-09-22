/**
 * ����������
 * �ص㣺
 *      ������������С�ڵ��ڸ���㣬�����������ڵ��ڸ����
 *      �����������������ʱ���õ����ǵ������У�����������һ�����������������ܻ�ԭ�������������飬�����������
 *      ����ͨ���������������дӶ��ж�һ�����Ƿ��Ƕ���������
 */
#include "../../6-Tree/TreeBasic.cpp"

#define INF (-10000)

using namespace std;

/**
 * ���Ҷ���������
 * @param bt �����
 * @param key �ؼ���
 * @return �Ƿ���ҵ�
 */
Tree* BSTSearch(Tree *bt, int key) {
    if (bt == nullptr) {
        return nullptr;
    } else {
        if (bt->val == key) {
            return bt;
        } else if (bt->val > key){
            return BSTSearch(bt->lchild, key);
        } else {
            return BSTSearch(bt->rchild, key);
        }
    }
}

/**
 * �������������
 * @param bt ����� ע��ʹ�������������� �Ϳ��Բ���Ҫ֪�� bt �ĸ��ڵ�
 * @param key �ؼ���
 * @return �Ƿ����ɹ�
 */
int BSTInsert(Tree *&bt, int key) {
    //���������ս�������ʧ�ܣ�Ҳ˵��û�� key ��Ӧ�Ľ�㣬������null��㣨ĳĳ����ԭ��ָ��null���ӽ�㣩��ֵ
    if (bt == nullptr) {
        bt = (Tree*) malloc(sizeof(Tree));
        bt->val = key;
        bt->lchild = nullptr;
        bt->rchild = nullptr;
        return 1;
    } else {
        if (bt->val == key) {
            return -1;
        } else if (bt->val > key ){
            return BSTInsert(bt->lchild, key);
        } else {
            return BSTInsert(bt->rchild, key);
        }
    }
}

/**
 * �������齨������������
 * �� 5 2 1 4 3 6
 *          5
 *        /  \
 *       2    6
 *     /   \
 *   1      4
 *         /
 *       3
 * @param bt �����
 * @param array ����
 * @param n ���鳤��
 */
void CreateBST(Tree *&bt, int array[], int n) {
    int i;
    bt = nullptr;
    for (i = 0; i < n; ++i) {
        BSTInsert(bt, array[i]);
    }
}

/**
 * ɾ��ĳ���
 * ������һ����ֲ���� ��ɾ�� 5 ��� 4�������������Ҷˣ� ���� 5 �������Ұ� 4 ���������ӵ� 2 ����������
 * �� 4 ���� 5 �����ӽڵ㣩
 *          5                 4
 *        /  \              /  \
 *       2    6   ��        2    6
 *     /   \   \         /  \    \
 *   1      4   7      1     3    7
 *         /
 *       3
 * ����һ��Ϊ ɾ�� 5 ��� 6��������������ˣ� ���� 5 ������ 6 ���������ӵ� 4 ���������ϣ� 6 �� 5 �����ӽ�㣩
 * @param p ��ɾ���Ľ��ڵ�
 * @return ɾ���ɹ�
 */
int Delete(Tree *&p) {
    Tree *q, *s;
    //��� p ��������Ϊ�գ��� p ���������ӵ� p ��˫�׽����������ϣ���ֱ���� p = p->lchild
    if (p->rchild == nullptr) {
        q = p;
        p = p->lchild;
        free(q);
    //������Ϊ��ͬ��
    } else if(p->lchild == nullptr) {
        q = p;
        p = p->rchild;
        free(q);
    //�����������������
    } else {
        q = p;
        //�ҵ� p �������������Ҷ˽�� s���� p ��������������㣬s ��������������
        s = p->lchild;
        while (s->rchild != nullptr) {
            //��¼ q Ϊ s ��˫�׽��
            q = s;
            s = s->rchild;
        }
        //�� p ��ֵ�滻�� s ��ֵ
        p->val = s->val;
        //��� s ���� p �����ӽ�㣬�� s ����������Ϊ q ��������
        if (q != p) {
            q->rchild = s->lchild;
        //��� s �� p �����ӽ�㣬�� s ����������Ϊ p ��������
        } else {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return 1;
}

int BSTDelete(Tree *&bt, int key) {
    Tree *p = BSTSearch(bt, key);
    if (p == nullptr) {
        return -1;
    } else {
        return Delete(p);
    }
}


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

