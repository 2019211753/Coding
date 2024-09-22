/**
 * 使用三元组实现对矩阵的转置
 * 注意，按行优先，三元组中的顺序就对应着矩阵中非0元素出现的顺序。
 * 原本的三元组是对原矩阵的行优先，转置后的三元组是对转置后的矩阵的行优先，也即对原矩阵的列优先。
 */
#include "iostream"

using namespace std;

#define endl '\n'
#define MAXSIZE 100

typedef struct Triple {
    int val;
    int row;
    int col;
} Triple;

void initial(int array[][MAXSIZE], int row, int col, Triple triple[]) {
    int k = 1;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (array[i][j] != 0) {
                triple[k].val = array[i][j];
                triple[k].row = i;
                triple[k++].col = j;
            }
        }
    }
    triple[0].val = k - 1;
    triple[0].row = row;
    triple[0].col = col;

}

Triple* transpose(Triple A[]) {
    Triple* B = (Triple*) malloc(sizeof (Triple) * A[0].val + 1);
    B[0].val = A[0].val;
    B[0].row = A[0].col;
    B[0].col = A[0].row;
    int m = 1;
    for (int i = 0; i < B[0].col; ++i) {
        for (int j = 0; j <= B[0].val; ++j) {
            if (i == A[j].col) {
                B[m].val = A[j].val;
                B[m].row = A[j].col;
                B[m].col = A[j].row;
                m++;
            }
        }
    }
    return B;
}

void output(Triple triple[]) {
    int k = 1;
    for (int i = 0; i < triple[0].row; ++i) {
        for (int j = 0; j < triple[0].col; ++j) {
            if (i == triple[k].row && j == triple[k].col) {
                cout << triple[k++].val << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    int array[MAXSIZE][MAXSIZE] = {{1, 2}, {2, 3}, {3, 4}};
    Triple A[MAXSIZE * MAXSIZE];
    initial(array, 3, 2, A);
    output(A);
    Triple* B = transpose(A);
    output(B);
}
