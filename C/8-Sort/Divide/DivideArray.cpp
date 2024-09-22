/**
 * ���Ż�����������ַ���
 */
#include "iostream"

using namespace std;

typedef struct Vector {
    int size;
    int array[];
} Vector;

void initial(Vector &vector, int array[], int n) {
    vector.size = n;
    for (int i = 0; i < n; i++) {
        vector.array[i] = array[i];
    }
}

void output(Vector &vector) {
    for (int j = 0; j < vector.size; ++j) {
        cout << vector.array[j] << " ";
    }
    cout << "*************"  << endl;
}

/**
 * ��һ��˳���L����Ԫ��Ϊ�������ݣ����һ���㷨����L������С�ڱ�ͷԪ�ص���������ǰ�벿�֣����ڱ�ͷԪ�ص��������ں�벿�֡�
 * ��Ҫ��˳��
 * ��1��
 * ���͵�ͨ��ĳһ�������������Ԫ�طָ�����ǿ��������㷨��һ��ѭ����
 * ʱ�临�Ӷȣ�������������Ԫ�ض��ȱ�ͷԪ�ش�O(n)�� �ռ临�Ӷ� O(1)
 */
void divide_1(Vector &vector) {
    int begin = 0;
    int end = vector.size - 1;
    int mark = vector.array[0];
    while (begin < end) {
        //��Ϊ����ֵ������һ��������Ӧ�ô��Ҳ࿪ʼ
        //��Ϊ�������࿪ʼ�����array[i]С��mark�ˣ�����Ҫ�ƶ��������Ҳ࿪ʼ�����j����mark������Ҫ�ƶ�
        //�������i����mark�ˣ��ƶ�������ȥ�أ����ﶼ�����ʣ���jС��mark��ֱ���ƶ���i�Ϳ�����
        while (vector.array[end] > mark && begin != end) {
            end--;
        }
        if (begin != end) {
            vector.array[begin] = vector.array[end];
            begin++;
        }
        while (vector.array[begin] < mark && begin != end) {
            begin++;
        }
        if (begin != end) {
            vector.array[end] = vector.array[begin];
            end--;
        }
    }
    vector.array[begin] = mark;
}

//�����������ƶ�������ż����ǰ��
//����ָ�뽻���� һ�����޷�ȷ��һ������Ԫ��λ�õ�ʱ����
void divide_2(Vector &vector)
{
    int i = 0, j = vector.size - 1;
    while (i < j)
    {
        while (i < j && vector.array[i] % 2 != 0)
        {
            i++;
        }
        while (i < j && vector.array[j] % 2 != 1)
        {
            j--;
        }
        //�������������������λ���ϡ����ȡ���������Ǹ��ǡ�
        if (i < j)
        {
            int temp = vector.array[i];
            vector.array[i] = vector.array[j];
            vector.array[j] = temp;
        }
        //�����ǽ���������i�Ѿ�С���������ˣ�j�Ѿ������������ˣ����ı䡣
        i++;
        j--;
    }
}

//���ѡȡһ������������֪��������λ�ÿ��ã�
//����ָ��ǰ�Ʒ���������ָ�븲�Ƿ�Ҳ���ԣ�������Ҫ���ܵ����ֿ��ŵĻ��ַ������������������ƶ��ķ�����ͬ��
int divide_3(Vector &vector, int low, int high)
{
    //���һ��λ�� ������lowԪ�ػ��� ��֪��Ϊʲô�����������һ����
    //int rand_index = low + rand() % (high-low+1);
    int rand_index = 0;
    int temp = vector.array[low];
    vector.array[low] = vector.array[rand_index];
    vector.array[rand_index] = temp;
    temp = vector.array[low];
    //��ָ�������������������Ӹ�λ������Ԫ�ؾ�С��������������λ��ʱ���ұ�Ԫ�ؾ�����������
    int i = low;
    //��ָ�������������ұ�һ����λ��
    for (int j = low + 1; j <= high; j++)
    {
        //��ǰԪ��С������������ָ�����ƣ�����ָ��Ԫ�ػ������Ӷ���ָ���Ծɱ���С�ڵ�������������ָ��ͬ��
        //��������λ��ʼ�ձ��ֲ�����
        if (vector.array[j] < temp)
        {
            int t = vector.array[++i];
            vector.array[i] = vector.array[j];
            vector.array[j] = t;
        }
    }
    //�����ָ��ĵ��Ҳ�ȫ�Ǵ���������������������������ָ�뽻������
    temp = vector.array[i];
    vector.array[i] = vector.array[low];
    vector.array[low] = temp;
    return rand_index;
}

int main() {
    int array[7] = {4, 2, 7, 5, 1, 8, 7};
    Vector vector;
    initial(vector, array, 7);
    output(vector);
    cout << divide_3(vector, 0, 6) << endl;
    output(vector);
}