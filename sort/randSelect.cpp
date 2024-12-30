#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int randPartion(int arr[], int left, int right)         // 随机选择一个元素作为划分元素
{
    int p = (round(1.0 * rand() / RAND_MAX * (right - left) + left));
    swap(arr[p], arr[left]);
    int temp = arr[left];
    while (left < right)
    {
        while (left < right && arr[right] > temp)
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= temp)
            left++;
        arr[right] = arr[left];
    }
    arr[left] = temp;
    return left;
}

void QSort(int arr[], int left, int right)          // 快速排序
{
    if (left < right)
    {
        int p = randPartion(arr, left, right);
        QSort(arr, left, p - 1);
        QSort(arr, p + 1, right);
    }
}


int randSelect(int arr[], int left, int right, int k)       // 返回第k大的数
{
    if(left == right) return arr[left];
    int p = randPartion(arr, left, right);
    int M=p-left+1;
    if(k==M) return arr[p];
    if(k<M) return randSelect(arr, left, p-1, k);
    return randSelect(arr, p+1, right, k-M);
}

int main()
{
    srand(unsigned(time(NULL))); // 初始化随机数种子
    int arr[10];
    for (int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout<<"\n"<< randSelect(arr, 0, 9, 5) << endl;
}