using namespace std;

//��������Ԫ���е�kС��Ԫ��
//��ֱ�ӵ�������ʹ�������㷨�ȴ�С���������Ȼ����ȡL(k)��������ƽ��ʱ�临�ӶȽ��ﵽO(nlog2_n)���ϡ�
//���⣬�����Բ���С���ѵķ�����ʱ�临�Ӷ�ΪO(n+klog2_n)��
//��ʹ�ÿ������򷽷���ʱ�临�Ӷ���ƽ������¿��ԴﵽO(n)
//���ÿ��������˼·�������䣬����������16��ͳ�������У�
//��֪n(n>2)�����������ɵļ���A={ak|0<=k<n}�����仮��Ϊ�������ཻ���Ӽ�A1��A2��Ԫ�ظ����ֱ���n1��n2��A1��A2
//�е�Ԫ��֮�ͷֱ�ΪS1��S2�����һ�������㷨����|n1-n2|��С��|S1-S2|���
//���ҵ���floor(n/2)С��Ԫ��λ�ü��ɣ�ʱ�临�Ӷ�ͬ���⡣
int findKth(int array[], int low, int high, int k)
{
    int pivot = array[low];
    int low_temp = low;
    int high_temp = high;
    while (low < high)
    {
        while (low < high && array[high] >= pivot)
        {
            high--;
        }
        array[low] = array[high];
        while (low < high && array[low] <= pivot)
        {
            ++low;
        }
        array[high] = array[low];
    }
    array[low] = pivot;
    //�����ǿ�������Ļ����㷨������Ϊ���㷨�ĺ���
    //�����������������ֱ��ȷ��һ��Ԫ�ص�����λ�ã�����������Ϊ��kС/��
    //���low == k����Ȼpivot����ҪѰ�ҵ�Ԫ�أ�ֱ�ӷ���
    if (low == k)
    {
        return array[low];
    //��������ߵ�����
    } else if (low > k) {
        return findKth(array, low_temp, low-1, k);
    } else {
        return findKth(array, low+1, high_temp, k);
    }
}

int main()
{

}