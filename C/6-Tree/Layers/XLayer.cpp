/**
 * ����ֵΪx�Ľ�������еĲ���
 */
#include "../TreeBasic.cpp"

/**
 * �ⷨһ����α���
 */
typedef struct ST {
    Tree *tree;
    int lay;
};

ST* create(Tree *tree, int lay) {
    ST *st = (ST*) malloc(sizeof(ST));
    st->tree = tree;
    st->lay = lay;
}

void getLayer(int &layer, int num, Tree *root) {
    layer = -1;
    ST *st[MAXSIZE];
    int head = 0;
    int tail = 0;
    //�����ڵ����
    st[++tail] = create(root, 1);
    while (head != tail) {
        if (layer == -1) {
            //����ͷ������
            ST *btNode = st[++head % MAXSIZE];
            //�����ͷ����ֵ����x���õ�����
            if (btNode->tree->val == num) {
                layer = btNode->lay;
            }
            //��������������ӣ������Ƕ��У����������������ҽ�������+1
            if (btNode->tree->lchild != nullptr) {
                st[++tail] = create(btNode->tree->lchild, btNode->lay + 1);
            }
            if (btNode->tree->rchild != nullptr) {
                st[++tail] = create(btNode->tree->rchild, btNode->lay + 1);
            }
        } else {
            break;
        }
    }
}

//�ⷨ2���ݹ�
//����ȫ�ֱ����Ļ���Ҫ����
int L = 1;
void getLayer_0(Tree *root, int x) {
    if (root != nullptr) {
        if (root->val == x) {
            cout << L << endl;
        }
        //����һ�� ����+1
        ++L;
        getLayer_0(root->lchild, x);
        getLayer_0(root->rchild, x);
        //����������������� ������һ�� ����-1 ����
        --L;
    }
}
//������ �����
void getLayer_1(Tree *root, int x, int l) {
    if (root != nullptr) {
        if (root->val == x) {
            cout << l << endl;
        }
        //����һ�� ����+1
        getLayer_1(root->lchild, x, L+1);
        getLayer_1(root->rchild, x, L+1);
    }
}

