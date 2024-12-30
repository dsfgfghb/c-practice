#include <iostream>
using namespace std;
// 二分查找

int erfen1(int a[], int left, int right, int x)
{
    int mid = 0;
    while (left < right)
    {
        cout << left << ' ' << right << ' ';
        mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return -1; // 找一个数组中x的下标
}

int solve(int a[], int left, int right, int x)
{
    int mid = 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (a[mid] >= x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left; // 返回数组中第一个大于x的数
}

int main()
{
    int a[10] = {1, 2, 3, 3, 5, 6, 7, 8, 9, 10};
    int b = solve(a, 0, 9, 3);
    if (b)
    {
        cout << b;
    }
    return 0;
}