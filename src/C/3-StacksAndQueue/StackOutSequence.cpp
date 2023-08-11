/**
 * 已知入栈序列为 1,2,...,n 求字典序前20种出栈顺序
 * 卡特兰数 C(n, 2n) / (n + 1)
 * 1. 应用于普通的已知入栈序列，求所有出栈序列。
 * 2. 已知二叉树前序遍历，有多少种树形。把前序遍历理解为入栈时的序列（入栈就打印），中序遍历理解为出栈时的序列。
 */
#include "iostream"

using namespace std;

// 限制输出前20个
int cnt = 20;
// 令序列长度为3
const int n = 3;
// 输出栈
int out[n];
int top_out = -1;
// 输入栈
int ready[n];
int top_ready = -1;
// 当前输入序号
int in = 1;

void dfs() {
    // 输出了20个时，退出
    if (cnt == 0) {
        return;
    }
    // 输出栈满时输出
    if (top_out == n - 1) {
        cnt--;
        for (int i : out) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    // 为什么不符合模板——用for{ if() }循环横向遍历解答树所有子节点？
    //本体解答树即为当前是入栈还是出栈，只有两个解答，故用if() if()即可
    // 只要输入栈不为空，就入输出栈（因为要字典序，若逆字典序，两个if互换）
    if (top_ready >= 0) {
        int temp = ready[top_ready];
        out[++top_out] = ready[top_ready--];
        dfs();
        top_out--;
        ready[++top_ready] = temp;
    }
    // 若输入栈未满，则入输入栈
    if (in <= n) {
        ready[++top_ready] = in++;
        dfs();
        top_ready--;
        in--;
    }
}

int main() {
    dfs();
}