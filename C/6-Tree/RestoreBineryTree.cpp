/**
 * ��ԭ������
 */
#include "TreeBasic.cpp"

//k = pos[i]��iΪ���ֵ��kΪ�ý����������������е�λ�� ��
int pos[MAXSIZE];

int length_0 = 8;
int pre_0[] = {1, 2, 3, 4, 5, 6, 7, 8};
int in_0[] = {3, 2, 5, 4, 6, 1, 8, 7};
//ǰ��
//          1
//        /   \
//      2      7
//    /  \    /
//  3     4  8
//      /  \
//     5    6

int length_1 = 10;
int in_1[] = {4, 2, 8, 5, 9, 1 , 6, 10,3 ,7};
int post_1[] = {4, 8, 9, 5, 2, 10, 6, 7, 3, 1};
//����
//              1
//           /    \
//         /       \
//       2          3
//     /   \       /  \
//   4      5    6     7
//         / \    \
//       8    9    10

int length_full = 7;
int full[] = {1, 2, 3, 4, 5, 6, 7};
//            1
//          /  \
//        /     \
//      2        5
//    /  \     /  \
//  3     4  6     7

/**
 * ��ס��������Ǳ�������������Ȼ�����㣬Ȼ��������
 * ǰ������Ǹ���㣬��������������
 *
 * plΪ�Ե�ǰ�����Ľ��Ϊ�����������ӽ������ ��ǰ����������� �������� �Դ�����
 *
 * �ȼ������Ӵ��ڣ��Һ��Ӵ��ڣ�ֱ��returnд�߼���Ȼ�������߼��м���߽������жϵݹ�
 *
 * @param pl ��ǰ�����ǰ����������е�������
 * @param pr ��ǰ�����ǰ����������е�������
 * @param il ��ǰ�����������������е�������
 * @param ir ��ǰ�����������������е�������
 * @return
 */
Tree* dfs_pre_in(int pl, int pr, int il, int ir) {
    //�����ǰ������е�����������������䣬���������û�н��
    if (pl > pr || pl < 0 || pr > length_1 - 1) {
        return nullptr;
    }
    //��ǰ�����������������е�����
    int k = pos[pre_0[pl]];
    Tree* root = create(pre_0[pl]);
    //������ǰ����������е����������� 1 �� pl + 1
    //������ǰ����������е�������Ϊǰ���������������� + �Ե�ǰ����������Ľ��������� k - il��
    //�� pl + k - il
    //��������������е������䲻��
    //��������������е�������Ϊ��ǰ�������� - 1
    root->lchild = dfs_pre_in(pl + 1, pl + k - il, il, k - 1);
    //�Һ�����ǰ����������е�������Ϊ���������� + 1
    //�Һ�����ǰ����������е������䲻��
    //��������������е�������Ϊ��ǰ�������� + 1
    //��������������е������䲻��
    root->rchild = dfs_pre_in(pl + k - il + 1, pr, k + 1, ir);
    return root;
}

Tree* buildTree_pre_in() {
    for (int i = 0; i < length_0; ++i) {
        pos[in_0[i]] = i;
    }
    return dfs_pre_in(0, length_0 - 1, 0, length_0 - 1);
}

/**
 * ���������˳��Ϊ���������������������
 */
Tree* dfs_post_in(int pl, int pr, int il, int ir) {
    if (pl > pr || pl < 0 || pr > length_1 - 1) {
        return nullptr;
    }
    int k = pos[post_1[pr]];
    Tree* root = create(post_1[pr]);
    root->lchild = dfs_post_in(pl, pr - 1 - (ir - k), il, k - 1);
    root->rchild = dfs_post_in(pr - (ir - 1), pr - 1, k + 1, ir);
    return root;
}

Tree* buildTree_post_in() {
    for (int i = 0; i < length_1; ++i) {
        pos[in_1[i]] = i;
    }
    return dfs_post_in(0, length_1 - 1, 0, length_1 - 1);
}

/**
 * ������������ǰ������õ��������
 * ģ��һ�������ǰ+�еĴ��룬ȷ���������������䣬�ݹ鵽Ҷ�ӽ�㡣���������ȴ��ȥ��Ȼ����������Ȼ�����
 * ��������֮���Բ���Ҫ�������䣬����Ϊ���ܵõ����������ֱ�Ľ������������ú�����������е�һ����
 * ���������룺ǰ������Ǹ����ң�������������Ҹ�����ǰ������ĸ����䣬���������ߵ�������ٽ������ߵ����ɵõ����������
 * @param pre ǰ���������
 * @param begin ��ǰ��������� ��ǰ����������е�������
 * @param end ������
 * @param post �������ջ
 * @param bottom ջ��
 */
void dfs_pre(int pre[], int begin, int end, int post[], int &bottom)
{
    if (begin == end) {
        post[++bottom] = pre[begin];
        return;
    }
    int leftBegin = begin + 1;
    int leftEnd = begin + (end - 1 - begin) / 2 + 1;
    int rightBegin = leftEnd + 1;
    int rightEnd = end;
    if (leftBegin <= leftEnd) {
        dfs_pre(pre, leftBegin, leftEnd, post, bottom);
    }

    if (rightBegin <= rightEnd) {
        dfs_pre(pre, rightBegin, rightEnd, post, bottom);
    }
    post[++bottom] = pre[begin];

}

void build_FullBinary_pre(int pre[], int post[], int n) {
    int stack_bottom = -1;
    dfs_pre(pre, 0, n - 1, post, stack_bottom);
}

int main() {
    int post[length];
    build_FullBinary_pre(full, post, length_full);
}
