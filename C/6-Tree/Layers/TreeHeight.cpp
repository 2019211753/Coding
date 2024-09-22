#include "../TreeBasic.cpp"

/**
 * ������������ö�������洢�ṹ�����һ���ǵݹ��㷨��������ĸ߶ȡ�
 * ����㷨����֪����ǰ���ʽ��Ĳ�������֪��ÿ��Ľ��״̬�����Կ���������ĳ��/ÿ��Ľ���������������ȵ�
 */
int btDepth1(Tree *tree)
{
    //����ֱ������߶�0
    if(tree == nullptr)
    {
        return 0;
    }
    //������λ
    int front = -1, rear = -1;
    Tree *nodes[MAXSIZE];
    //last��ǵ�ǰ�����Ľ�����ڵĲ�����ҽ�� level��ʾ��߲���
    int last = 0, level = 0;
    nodes[++rear] = tree;
    Tree *p;
    while (front < rear)
    {
        //��ĳ�ڵ�������ӽ����ӣ���һ��һ�����
        p = nodes[++front];
        if (p->lchild != nullptr)
        {
            nodes[++rear] = p->lchild;
        }
        if (p->rchild != nullptr)
        {
            nodes[++rear] = p->rchild;
        }
        //��������ĳ�����һ����㣬��ô��һ��Ľ��Ҳȫ�������
        //���Ӳ����ı�־��һ����ֻ��һ�Σ�����ͬһ��Ľ����������м��˺ü���level
        if (front == last)
        {
            //������һ����������Ĳ���+1
            level++;
            //�������ҽ�����Ϊ��һ�����ҽ�����
            last = rear;
        }
    }
    return level;
}

//����
int btDepth2(Tree *tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    int left = btDepth2(tree->lchild);
    int right = btDepth2((tree->rchild));
    if (left < right)
    {
        return right + 1;
    } else {
        return left + 1;
    }
}

//�ݹ�
int H1 = 0;
void btDepth3(Tree *tree, int h)
{
    if (tree == nullptr)
    {
        h--;
        if (h > H1)
        {
            H1 = h;
        }
        return;
    }
    btDepth3(tree->lchild, h+1);
    btDepth3(tree->rchild, h+1);
}

//���Ժ����ֵܱ�ʾ���洢��ɭ�ֵ�Ҷ�ӽڵ�����
int H2 = 0;
void forestDepth(Tree *tree, int h)
{
    if (tree == nullptr)
    {
        h--;
        if (h > H2)
        {
            H2 = h;
        }
        return;
    }
    btDepth3(tree->lchild, h+1);
    btDepth3(tree->rchild, h);
}

int main()
{
    Tree *tree = initial();
    cout << btDepth2(tree) << endl;
    btDepth3(tree, 1);
    cout << H1;
}