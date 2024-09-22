/**
 * �ַ��������ܽ�
 * �ַ����������һλ�ǵð���'\0'
 * cin �õ����ַ�����char�������һλ�Զ�����'\0'
 * clion��ָ��ָ���ַ����׶˿�����ʾ�����ַ�
 * *x   x = x + 1��xָ����һλ   *a = *b ��bָ�뵱ǰָ���ֵ����aָ�뵱ǰָ���λ��
 * �����ָ����ַ��� ��'0' + x
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * �߾����㷨�����㷨
 * @param A һ����
 * @param b ���� ����Ϊ 2
 */
vector<int> divide(vector<int> A, int b) {
    //�����Ŀ�ͷ��ʼ�����������β����Ϊ������洢��
    //��ʵ����������洢Ҳ���ԣ���ΪԽ������Խ�٣����Ǽӷ��ͳ˷���Ҫ������Ϊ���ܼ�������ֱ��
    vector<int> C;
    for (int i = A.size() - 1, r = 0; i >= 0; i--) {
        //����ԭ�� ������һ�γ�������� * 10 + ��λ�� ��Ϊ��������ı�����
        r = r * 10 + A[i];
        //���������Ϊ�µ�A
        C.push_back(r / b);
        //�õ���γ�������� ���������´�����
        r %= b;
    }
    //��ʱC�е����ǰ����������У���Ҫת��Ϊ������ջ��ջ������
    reverse(C.begin(), C.end());
    //ȥ�����ܴ��ڵ�ǰ����0������12 / 2  = 06 reverse���� 60��0��ջ����ȥ��
    while (C.size() && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    string s;

    while (cin >> s) {
        // ����������λ��ŵ�������
        int len = s.size();
        vector<int> A;
        for (int i = 0; i < len; i++) {
            // ���ڶ���string���ͣ��洢��int�������Ҫ��ȥ'0'
            A.push_back(s[len - i - 1] - '0');
        }

        string res;
        if (s == "0") {
            //���ټ���0
            res = "0";
        } else {
            //�̳�����ÿ�ν������һλ���������һλ��MOD 2�������浽res��
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