#include "iostream"

using namespace std;

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

//��ָ�뷨
//����3�����䣬ǰ����-1���м���0��������1
//ָ��i��ζi���ȫ��-1��k�ұ�ȫΪ1��jΪ����ָ�룬��ߵ�-1��0���������ұ�����
void numArrange(int array[], int n)
{
    int i = 0, j = 0, k = n-1;
    while (j <= k)
    {
        switch (array[j]) {
            case -1:
                swap(array, i, j);
                //֮�������ｻ������j++����Ϊj��i������i��Ϊ-1��0��������Ϊ1����-1��0������ֱ�Ӽ��j+1�����ˡ�
                i++;
                j++;
                break;
            case 0:
                j++;
                break;
            case 1:
                //ǰ�᣺j < k�������1��j��k������1��Ȼ��j���档����j֮ǰֻ��-1��0��û��1��
                swap(array, j, k);
                k--;
                //����û��j++�Է�ֹ������a[j]��Ϊ1�����array[k]��0������j++�������1��-1����j��Ҫ������ԭλ����������
        }
    }
}