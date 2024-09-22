#include "iostream"

#define MAXSIZE 100

using namespace std;

//折半查找（元素均不一样） 分治
int search(int low, int high, int array[], int val)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == val)
        {
            return mid;
        } else if (array[mid] > val) {
            return search(low, mid - 1, array, val);
        } else {
            return search(mid+1, high, array, val);
        }
    } else {
        return -1;
    }
}

int main()
{
    int array[7] = {1, 3, 7, 8, 10, 15, 99};
    cout << search(1, 6, array, 8);
}