/**
 * ����ѧ���ĳɼ������ɼ����а���ÿ��ѧ���������ͷ������밴��Ҫ�󽫳ɼ������ɼ��Ӹߵ��ͻ�ӵ͵��ߵ�˳������������С�
 * ���ڳɼ���ͬ��ѧ��������������˳�����У���Ҫ����ԭʼ�ɼ����п�ǰ��ѧ��������ǰ�Ĺ�����
 * �����ʽ��
 * ��һ�а������� N����ʾѧ��������
 * �ڶ��а���һ������ 0 �� 1����ʾ�������0 ��ʾ�Ӹߵ��ͣ�1 ��ʾ�ӵ͵��ߡ�
 * ������ N �У�ÿ������һ��ѧ������Ϣ������һ�����Ȳ����� 10 ��Сд��ĸ���ɵ��ַ�����ʾ�����Լ�һ����Χ�� 0?100 ��������ʾ������
 * �����ʽ��
 * ������������ĳɼ�����
 * ÿ�����һ��ѧ���������ͳɼ����õ����ո������
 * ���ݷ�Χ��
 * 1��N��1000
 * ��������1��
    4
    0
    jack 70
    peter 96
    Tom 70
    smith 67
 * �������1��
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
    //������Ҫ�Ȱ�nameȷ����С����Ȼcin����ȥ��
    //cin��char��������һ���ַ�������'/000'���Ӷ����ʱ�Զ���ֹ��
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