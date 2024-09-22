//�ж�һ�����Ƿ��Ƕ���ƽ����
#include "../../6-Tree/TreeBasic.cpp"

#define INF (-10000)

using namespace std;

//���������һ���⣬������Ȼ���ַ��κͺ��������˼·����ȫһ�µġ����⣬�ݹ�ģ���Ҫ�õ���һ�㷵�ص���������
//����Ҫ��������ֵ�������������&��������
void judge(Tree *tree, int &height, int &balance)
{
    //���������ĸ߶Ⱥ��Ƿ�ƽ��
    int b1, b2;
    int h1, h2;
    //����ǿ�����ƽ�⣬�Ҹ߶�Ϊ0
    if (tree == nullptr)
    {
        height = 0;
        balance = 1;
    } else {
        //�����ж������������ֱ�õ����������ĸ߶ȣ��ж������Ƿ�ƽ��
        judge(tree->lchild, h1, b1);
        judge(tree->rchild, h2, b2);
        //����������һ����ƽ�������岻ƽ��
        if (!b1 || !b2)
        {
            balance = 0;
        }
        //��ǰ����ƽ��
        if (abs(h1 -h2) > 1)
        {
            balance = 0;
        //ƽ��
        } else {
            balance = 1;
            height = max(h1, h2) + 1;
        }
    }
}

int jud(Tree *tree)
{
    if (judge(tree) != -1)
    {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    Tree *tree = initial();
}