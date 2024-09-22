/**
 * ����������Ӧ��
 * 809��������������
 */
#include "TreeBasic.cpp"

//����������
typedef struct TBTnode {
    //�ж�һ�������������Ľ�������Ӧ�ý�� �����ӽ���Ƿ�Ϊnull �� ltag��rtag
    //��ltag == 0 && lchild != null ʱ�����������ӽڵ㲻��
    //��ltag == 1 && lchild != null ʱ�����������ӽڵ�գ�����ǰ�����
    //��ltag == 1 && lchild == null ʱ�����������ӽڵ�գ����Ǹ�������ĵ�һ����㣬��ǰ��
    //��rtag == 0 && rchild != null ʱ�����������ӽڵ㲻��
    //��rtag == 1 && rchild != null ʱ�����������ӽڵ�գ����к�̽��
    //��rtag == 1 && rchild == null ʱ�����������ӽڵ�գ����Ǹ�����������һ����㣬�޺��
    //�� tag Ϊ 0 ʱ��������ζ�Ӧ���ӽ��Ҳ�ǿգ��淴���۳������� tag Ϊ 1ʱ����Ӧ�ӽ�㲻һ���ǿ�
    int ltag;
    int rtag;
    int val;
    TBTnode *lchild;
    TBTnode *rchild;
} TBTnode;

//��ʼ����ʱ����Ҫ������tag����Ϊ0
TBTnode* create_Thread(int val) {
    TBTnode *tree = (TBTnode*) malloc(sizeof (TBTnode));
    tree->lchild = nullptr;
    tree->rchild = nullptr;
    tree->ltag = 0;
    tree->rtag = 0;
    tree->val = val;
    return tree;
}

TBTnode* initial_Thread() {
    TBTnode *root = create_Thread(1);
    root->lchild = create_Thread(2);
    root->lchild->lchild = create_Thread(3);
    root->lchild->rchild = create_Thread(4);
    root->lchild->rchild->lchild = create_Thread(5);
    root->lchild->rchild->rchild = create_Thread(6);

    root->rchild = create_Thread(7);
    root->rchild->lchild = create_Thread(8);
    return root;
}

//������������������
void buildInThread(TBTnode *p, TBTnode *&pre) {
    if (p != nullptr) {
        //�������
        buildInThread(p->lchild, pre);
        //����ý���������Ϊ�� ���� ltag Ϊ 1�����ӽڵ�Ϊȫ���µ���һ�����
        if (p->lchild == nullptr) {
            p->ltag = 1;
            p->lchild = pre;
        }

        //����дҲ���ԣ�ֱ�ӶԵ�ǰ�������ӽڵ㸳ֵ������Ҫ������ⲿ���������ˡ���Ȼ�����ܲ�̫���ϡ������������˼��
        //�����ӽ��Ϊ�գ��� rtag = 1
        if (p->rchild == nullptr) {
            p->rtag = 1;
        }
        //����һ����㲻Ϊ�������ӽ��Ϊ�գ�����һ���������ӽ����Ϊ��ǰ���
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = p;
        }

        //����������д�� ������Ҫ�ڱ��ⲿ��������ʱ�����һ�������������pre->rtag = 1;
//        if (pre != nullptr && pre->rchild == nullptr) {
//            pre->rtag = 1;
//            pre->rchild = p;
//        }

        pre = p;
        p = p->rchild;
        buildInThread(p, pre);
    }
}

//�������������������н��t�������������µ����һ���ڵ�
//�������������ҽ�� ��û�����ӽڵ� ������
TBTnode* getInLast(TBTnode *root) {
    while(root != nullptr && root->rtag == 0) {
        root = root->rchild;
    }
    return root;
}

//�������������������н��t�������������µĵ�һ��
//���������������� ��û�����ӽڵ� ������
TBTnode* getInFirst(TBTnode *root) {
    while(root != nullptr && root->ltag == 0) {
        root = root->lchild;
    }
    return root;
}

//�������������������н��t�������������µĺ��
TBTnode* getInNext(TBTnode *root) {
    if (root->rtag != 0) {
        return root->rchild;
    } else {
        return getInFirst(root->rchild);
    }
}

//������������������
void inOrder(TBTnode *root) {
    for (TBTnode *p = getInFirst(root); p != nullptr; p = getInNext(p)) {
        cout << p->val;
    }
}

//�������������������н��t�������µ�ǰ��
//��������������Ϊ�����������ҽ�㣬�������ltag = 1�µ�lchild����֮����lchild
TBTnode *getInBefore(TBTnode *root) {
    if (root != nullptr && root->ltag == 0) {
        return getInLast(root->lchild);
    } else {
        return root->lchild;
    }
}

//�������������������н��t��ǰ���µĺ��
//�����ӽ�㣬��û�У������ӽ�㣬��û�У��򸸽ڵ�����ӽ�㣬��t.rchild.rchild�������ڵ�û���ӽ�㣬��Ϊ�����ӽڵ�����Ƚ������ӽڵ�
TBTnode *getInBeforeAfter(TBTnode *node) {
    //����ǰ���������ж��ǲ���null�� ����Ͳ���null
    if (node->ltag == 0) {
        return node->lchild;
    }
    if (node->rtag == 0) {
        return node->rchild;
    }
    while (node != nullptr && node->rtag != 0) {
        node = node->rchild;
    }
    //�������ôһ�������ӽ������ȣ�������������ӽ�㣬�����û��̽���ˣ�����null
    if (node != nullptr) {
        return node->rchild;
    } else {
        return nullptr;
    }
}

//����ǰ������������
void buildPreThread(TBTnode *p, TBTnode *&pre) {
    if (p != nullptr) {
        if (p->lchild == nullptr) {
            p->ltag = 1;
            p->lchild = pre;
        }
        //����дҲ���� ����Ҫ������ⲿ����������
//        if (p->rchild == nullptr) {
//            p->rtag = 1;
//        }
//        if (pre != nullptr && pre->rchild == nullptr) {
//            pre->rchild = p;
//        }
//        ����������д�� ������Ҫ�ڱ��ⲿ��������ʱ�����һ�������������pre->rtag = 1;
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rtag = 1;
            pre->rchild = p;
        }

        pre = p;
        //�����ж�ltag == 0�����ж�p->lchild =! null
        //����Ϊ���û�������� ����Ĵ���ᵼ��p->lchild = pre�������ǰ��㲻�Ǹ��ڵ㣬��ô��Ϊnull�����³�����󣬽�����ѭ��
        //ͬ�ṹ�崦�������� p->ltag == 0����ô���ӽ��϶��ǿ�
        if (p->ltag == 0) {
            buildPreThread(p->lchild, pre);
        }
        //����ͬ�ϣ������ǰ�������ӽ��ԭ��Ϊ�գ��ڱ�������������������ӽ�㲻Ϊ�գ�
        //�����ӽ��ָ���������ӽڵ㣬��Ϊnull���ֻ���ѭ��
        if (p->rtag == 0) {
            buildPreThread(p->rchild, pre);
        }
    }
}

//����ǰ������������
void preorder(TBTnode *root) {
    if (root != nullptr) {
        TBTnode *p = root;
        while(p != nullptr) {
            while (p->ltag == 0) {
                p = p->lchild;
                //do something
            }
            //do something
            p = p->rchild;
        }
    }
}

//������������������
void buildPostThread(TBTnode *p, TBTnode *&pre) {
    if (p != nullptr) {
        buildPostThread(p->lchild, pre);
        buildPostThread(p->rchild, pre);
        //����һ��������ʱ �Ŷ�ǰ������rtag��rchild���иı䣬��������������һ����㣨���ң���rtag��ȻΪ0
        //���ǵ�һ������ltag��lchild��ı�
        if (p->lchild == nullptr) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
    }
}

int main() {
    TBTnode *root = initial_Thread();
    TBTnode *pre = nullptr;
    buildInThread(root, pre);
    inOrder(root);
}

