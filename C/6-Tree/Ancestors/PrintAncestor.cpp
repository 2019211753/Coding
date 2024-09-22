#include "../TreeBasic.cpp"

/**
 * ����ֵΪx�Ľ�㣬����ӡ������������
 */
void printAncestor(Tree *root, int x)
{
    Tree *p = root;
    Tree *r = nullptr;
    Tree *nodes[MAXSIZE];
    int top = -1;
    while (p != nullptr || top != -1)
    {
        if (p != nullptr)
        {
            nodes[++top] = p;
            p = p->lchild;
        } else {
            //��ջ����㣨�ǳ�ջ����Ҫ�ж��ǵ�һ�η��صĻ��ǵڶ��η��ص� �پ����Ƿ��ջ
            p = nodes[top];
            //�����������ڣ���δ�����ʹ�
            if (p->rchild != nullptr && p->rchild != r)
            {
                //ת����
                p = p->rchild;
            } else {
                p = nodes[top--];
                if (p->val == x)
                {
                    for (int i = 0; i <= top; ++i) {
                        cout << nodes[i]->val << " ";
                    }
                    cout << endl;
                }
                //��¼������ʵĽ��
                r = p;
                //����������൱�ڱ������Ըýڵ�Ϊ������������p��null
                //��ͬ��ǰ������������������һ�����ϱ�������ʱ���ڸ���㣬����Ϊnull������Ҫ�ֶ���null�������±�����������
                p = nullptr;
            }
        }
    }
}

Tree *B[MAXSIZE];
int j = -1;
/**
 * �������㵽ÿ��Ҷ�ӽ���·��
 * ��Ϊ�ݹ鷨��Ҳ���÷ǵݹ��������õ���
 */
void getLeafNodePath(Tree *root) {
    if (root != nullptr) {
        //���ʵ�ĳ����� ¼��·��
        B[++j] = root;
        if (root->rchild == nullptr && root->lchild == nullptr) {
            for (int i = 0; i <= j; ++i) {
                cout << B[i]->val << " ";
            }
            cout << endl;
            return;
        }
        getLeafNodePath(root->lchild);
        getLeafNodePath(root->rchild);
        //���ҽ�㶼�������� ��������ϵĽ��·���Ѿ�������ˣ������һ��·��·��
        j--;
    }
}

