/**
 * �������Ĵ����޷Ǿ����о���ʲôʱ����ջ��ʲôʱ���ջ��ʲôʱ����ʣ���������ʱ����ʱ��ջ�ͷ�����ͬ����ʱ������ͬ��
 *
 * �ݹ���Ҫ�أ�
 *  ���壺Ҫ��ʲô���飬�����������ǰ��������ȱ������׽ڵ㣬Ȼ����ڵ㡢�ҽڵ�
 *  ��֣���ֳɡ�ͬ���������⣬����ģ��С����������ǰ��������ǲ�����������������������������������ֱ���ǰ�����
 *  ���������������սڵ�ֹͣ��
 *
 * ���Σ�
 * ͨ����˵�����η��ĺ������з���ֵ�ġ�
 * ���η���Ҫ�أ�
 *  ���壺Ҫ��ʲô����
 *  �����ϲ����⣺
 *  ����������
 * ����˼����������ĺ������ģ�弫�����ơ���Ϊ�����㷨����·�� �ֽ� -> ��������ף�-> �ϲ������ݣ���
 * �����ҷֽ⣬�ٴ���ϲ������ݾ�������ջ�����൱�ں��������
 *
 * ��֮���ݹ��ֳ������⣬Ҫ��������������ض�������������񡱡�����Ҫϸ��ÿһ����ɵ�ϸ�ڡ�
 */
#include "iostream"

#define MAXSIZE 100

using namespace std;

typedef struct Tree {
    int val;
    Tree *lchild;
    Tree *rchild;
} Tree;

Tree* create(int val) {
    Tree *tree = (Tree*) malloc(sizeof (Tree));
    tree->lchild = nullptr;
    tree->rchild = nullptr;
    tree->val = val;
    return tree;
}

int length = 8;
Tree* initial() {
    Tree *root = create(1);
    root->lchild = create(2);
    root->lchild->lchild = create(3);
    root->lchild->rchild = create(4);
    root->lchild->rchild->lchild = create(5);
    root->lchild->rchild->rchild = create(6);
    //ԭ����7 �ĳ�4����������������
    root->rchild = create(7);
    root->rchild->lchild = create(8);
    return root;
}


//����
//          1
//        /   \
//      2      7
//    /  \    /
//  3     4  8
//      /  \
//     5    6
//ǰ��������У�
//1 2 3 4 5 6 7 8
//����������У�
//3 2 5 4 6 1 8 7
//����������У�
//3 5 6 4 2 8 7 1

void visit(Tree *node)
{

}

//�ݹ�ģ��
void recurse(Tree *root)
{
    //��������
    if (root != nullptr)
    {
        //�����root����Ϊǰ�� �������ջʱ����
        //visit(root);
        recurse(root->lchild);
        //����Ϊ���� ������ȫ����ջ�� ��һ�η��ص������ʱ����
        //visit(root);
        recurse(root->rchild);
        //����Ϊ���� ��������ȫ����ջʱ���� �ڶ��η��ص������ʱ����
        //visit(root);
        //�����Ҹ��������������ҳ�ջʱ��������ջ
    }
}

//���ڵ�������д���е�ȡ�ɣ�ջ�ֵֹģ�����������ʵ�ַ�ʽ�ĺ��������������������ȵ���
//�ǵݹ�ʵ��ǰ�����������
//��-��-��
void preorderNonRecursion_1(Tree *root) {
    cout << "ǰ��������У�" << endl;
    if (root != nullptr) {
        Tree *node[MAXSIZE];
        int top = -1;
        Tree *p;
        node[++top] = root;
        while (top != -1) {
            //�����ʵ�ĳ���ʱ��ֱ�ӳ�ջ
            p = node[top--];
            visit(p);
            //������������ջ
            if (p->rchild != nullptr)
            {
                node[++top] = p->rchild;
            }
            //������������ջ����ջ��
            if (p->lchild != nullptr) {
                node[++top] = p->lchild;
            }
        }
    }
    cout << endl;
}

//�ǵݹ�ʵ���������������
//��-��-��
void inorderNonRecursion_1(Tree *root) {
    cout << "����������У�" << endl;
    if (root != nullptr) {
        Tree *node[MAXSIZE];
        int top = -1;
        Tree *p;
        p = root;
        //��ջ��Ϊ����p��Ϊnullʱѭ������
        //��ǰ������ķǵݹ���ʽ��һ������Ҫ�� p!=null����Ϊ���������������ĸ��ڵ��Ҹ��ڵ���������ʱ��
        //��ʱջΪ�գ�������Ҫ��������
        while (p != nullptr || top != -1) {
            while (p != nullptr) {
                node[++top] = p;
                p = p->lchild;
            }
            //��������Ϊnull�������������� �ý���ջ
            //�����ж�top�ղ��գ��϶�����
            //��Ϊ���� ��ô˵������ѭ��֮ǰջ���ǿյģ��ҵ�ǰpû��ջ����p==nullptr
            //��ô�Ͳ����ܽ��뱾��ѭ��
            p = node[top--];
            //�Խ���ĳ����
            visit(p);
            //�����ý���������
            p = p->rchild;
        }
    }
    cout << endl;
}

//�ǵݹ�ʵ�ֺ������������
//��-��-������ǰ������ĸ�-��-����ȣ������ǰ�������������ұ�����Һ������������-��-��
//����������������˳�����򣬼��õ��������
void postorderNonRecursion_1(Tree *root) {
    cout << "����������У�" << endl;
    if (root != nullptr) {
        Tree *array[MAXSIZE];
        int j = -1;
        Tree *node[MAXSIZE];
        int top = -1;
        Tree *p;
        node[++top] = root;
        while (top != -1) {
            p = node[top--];
            array[++j] = p;
            if (p->lchild != nullptr) {
                node[++top] = p->lchild;
            }
            if (p->rchild != nullptr)
            {
                node[++top] = p->rchild;
            }
        }
        while (j != -1) {
            visit(array[j--]);
        }
    }
    cout << endl;
}

//�����汾ǰ������������ǵݹ��
//ջ�͵ݹ���һ��
void preorderNonRecursion_2(Tree *root)
{
    Tree *p = root;
    Tree *nodes[MAXSIZE];
    int top = -1;
    while (p != nullptr || top != -1)
    {
        //�ߵ������
        if (p != nullptr)
        {
            visit(p);
            nodes[++top] = p;
            p = p->lchild;
        } else {
        //�����������꣬��һ�η��ص�����㣬������ջ�������߷���������
            p = nodes[top--];
            p = p->rchild;
        }
    }
}

//��ǰ���ջ��ͬ��ֻ�Ƿ���˳�����
void inorderNonRecursion_2(Tree *root)
{
    Tree *p = root;
    Tree *nodes[MAXSIZE];
    int top = -1;
    while (p != nullptr || top != -1)
    {
        if (p != nullptr)
        {
            nodes[++top] = p;
            p = p->lchild;
        } else {
            p = nodes[top--];
            visit(p);
            p = p->rchild;
        }
    }
}

//���������Ҫ���ո�����ջ��ʱ�����ǵ�һ�η��ص����������ǵڶ��Σ�����Ҫ��һ���ж�������
//������ʹ��һ������ָ��rָ��������ʹ��Ľ�㡣Ҳ�����ڽ��������һ����־�򣬼�¼�Ƿ��ѱ����ʡ�
void postorderNonRecursion_2(Tree *root)
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
                visit(p);
                //��¼������ʵĽ��
                r = p;
                //����������൱�ڱ������Ըýڵ�Ϊ������������p��null
                //��ͬ��ǰ������������������һ�����ϱ�������ʱ���ڸ���㣬����Ϊnull������Ҫ�ֶ���null�������±�����������
                p = nullptr;
            }
        }
    }
}

//int main() {
//    Tree *root = initial_head();
//    preorderNonRecursion(root);
//    inorderNonRecursion(root);
//    postorderNonRecursion(root);
//}