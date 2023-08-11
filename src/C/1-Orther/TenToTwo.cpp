/**
 * 字符串处理总结
 * 字符串数组最后一位记得包含'\0'
 * cin 得到的字符串的char数组最后一位自动包含'\0'
 * clion的指针指向字符串首端可以显示所有字符
 * *x   x = x + 1，x指向下一位   *a = *b 把b指针当前指向的值赋给a指针当前指向的位置
 * 把数字赋给字符串 用'0' + x
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 高精度算法整除算法
 * @param A 一个数
 * @param b 除数 本题为 2
 */
vector<int> divide(vector<int> A, int b) {
    //从数的开头开始操作（数组结尾，因为是逆序存储）
    //其实除法用正序存储也可以，因为越除数字越少，但是加法和乘法需要逆序，因为可能计算后数字变多
    vector<int> C;
    for (int i = A.size() - 1, r = 0; i >= 0; i--) {
        //除法原理 就是上一次除完的余数 * 10 + 本位数 作为本次运算的被除数
        r = r * 10 + A[i];
        //被除结果作为新的A
        C.push_back(r / b);
        //得到这次除完的余数 保存用来下次运算
        r %= b;
    }
    //此时C中的数是按照正序排列，需要转化为逆序，则栈底栈顶调换
    reverse(C.begin(), C.end());
    //去除可能存在的前导“0”。如12 / 2  = 06 reverse后变成 60，0在栈顶，去除
    while (C.size() && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    string s;

    while (cin >> s) {
        // 将数倒着逐位存放到数组中
        int len = s.size();
        vector<int> A;
        for (int i = 0; i < len; i++) {
            // 由于读入string类型，存储是int，因此需要减去'0'
            A.push_back(s[len - i - 1] - '0');
        }

        string res;
        if (s == "0") {
            //快速计算0
            res = "0";
        } else {
            //短除法，每次将数组第一位（数的最后一位）MOD 2的余数存到res中
            while (A.size()) {
                res += to_string(A[0] % 2);
                A = divide(A, 2);
            }
            reverse(res.begin(), res.end());
        }
        cout << res << endl;
    }

    return 0;
}