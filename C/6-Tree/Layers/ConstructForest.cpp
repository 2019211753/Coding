/**
 * ��֪һ�����Ĳ�α������м�ÿ�����Ķȣ���д�㷨��������ĺ���-�ֵ�����
 */
#include "../TreeBasic.cpp"

void construct(Tree *&root, int layer[], int degree[], int n)
{
    Tree **p = new Tree *[MAXSIZE];
    //i�����Բ�α�������������
    //j������¼�Ե�ǰ�����ӽ����б���
    //d������¼��ǰ�����ӽ������
    //k������¼��ǰ�����ӽ����ţ����䣩
    int i, j, d, k = 0;
    //��ʼ��
    for (i = 0; i < n; i++)
    {
        p[i] = new Tree ();
        p[i]->val = layer[i];
        p[i]->lchild = p[i]->rchild = nullptr;
    }
    for (i = 0; i < n; i++)
    {
        d = degree[i];
        //����Ȳ�����0
        if (d != 0)
        {
            k++;
            //��ʱkΪ��ǰ���ĵ�һ���ӽ�� ���뵱ǰ�������ӽڵ�
            //�����ӽ�����β��뵽��һ���ӽ������ӽڵ㣨�ֵܣ�
            p[i]->lchild = p[k];
            for (j = 2; j <= d; j++)
            {
                k++;
                p[k-1]->rchild = p[k];
            }
        }
    }
    root = p[0];
    delete []p;
}

//ԭ����
//          1
//        /   \
//      2      7
//    /  \    /
//  3     4  8
//      /  \
//     5    6
//ת���ɶ������洢
//         1
//        /
//       2
//     /   \
//    3     7
//    \    /
//     4  8
//     /
//    5
//     \
/       6

int main()
{
    int array[] = {1, 2, 7, 3, 4, 8, 5, 6};
    int degree[] = {2, 2, 1, 0, 2, 0, 0, 0};
    int n = 8;
    Tree *root = create(8);
    construct(root, array, degree, n);
    cout << 1;
}


