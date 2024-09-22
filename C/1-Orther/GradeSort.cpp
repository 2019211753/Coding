/**
 * 给定学生的成绩单，成绩单中包含每个学生的姓名和分数，请按照要求将成绩单按成绩从高到低或从低到高的顺序进行重新排列。
 * 对于成绩相同的学生，无论以哪种顺序排列，都要按照原始成绩单中靠前的学生排列在前的规则处理。
 * 输入格式：
 * 第一行包含整数 N，表示学生个数。
 * 第二行包含一个整数 0 或 1，表示排序规则，0 表示从高到低，1 表示从低到高。
 * 接下来 N 行，每行描述一个学生的信息，包含一个长度不超过 10 的小写字母构成的字符串表示姓名以及一个范围在 0?100 的整数表示分数。
 * 输出格式：
 * 输出重新排序后的成绩单。
 * 每行输出一个学生的姓名和成绩，用单个空格隔开。
 * 数据范围：
 * 1≤N≤1000
 * 输入样例1：
    4
    0
    jack 70
    peter 96
    Tom 70
    smith 67
 * 输出样例1：
    peter 96
    jack 70
    Tom 70
    smith 67
 */
#include "iostream"

using namespace std;

#define endl '\n'
#define MAXSIZE 100

typedef struct student
{
    int score;
    //这里需要先把name确定大小，不然cin不进去。
    //cin到char数组里，最后一个字符后面有'/000'，从而输出时自动截止。
    char name[MAXSIZE];
} Student;


int main()
{
    int num;
    int type;
    cin >> num;
    cin >> type;
    Student students[num];
    int i, j, k, l;
    Student temp;
    for (i = 0; i < num; i++)
    {
        Student student;
        cin >> student.name;
        cin >> student.score;
        students[i] = student;
    }
    for (j = 0; j < num - 1; j++)
    {
        for (k = 0; k < num - 1; k++)
        {
            if (type == 0)
            {
                if (students[k].score < students[k + 1].score)
                {
                    temp = students[k];
                    students[k] = students[k + 1];
                    students[k + 1] = temp;
                }
            } else
            {
                if (students[k].score > students[k + 1].score)
                {
                    temp = students[k];
                    students[k] = students[k + 1];
                    students[k + 1] = temp;
                }
            }

        }
    }

    for (l = 0; l < num; l++)
    {
        cout << students[l].name << " " << students[l].score << endl;
    }

}