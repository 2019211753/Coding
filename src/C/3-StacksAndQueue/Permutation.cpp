/**
 * 全排列，输出数字 n，输出所有 1, 2, ..., n的全排列
 * dfs 重点：恢复现场和回溯的条件
 * dfs 的格式一般是
 * void dfs(int 当前状态)
{
      if(当前状态为边界状态)
      {
        记录或输出
        return
      }
      for(i=0;i<n;i++)       //横向遍历解答树所有子节点
      {
           //扩展出一个子状态。
           修改了全局变量
           if(子状态满足约束条件)
            {
              dfs(子状态)
           }
           恢复全局变量//回溯部分
      }
}
 */

#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N];

void dfs(int u) {
    //如果n个位置都有数了，就输出
    if (u == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", path[i]);
        }
        puts("");
    } else {
        //如果没走到树的叶子节点
        for (int i = 1; i <= n; i++) {
            //如果该数字没有进路径
            if (!st[i]){
                //进路径
                path[u] = i;
                //设为已读取
                st[i] = true;
                //进入下一级
                dfs(u + 1);
                //这一级读取完，回溯到上一级，将这一级选择的数字的状态还原为false
                st[i] = false;
            }
        }
    }
}


int main() {
    cin >> n;
    dfs(0);
    return 0;
}
