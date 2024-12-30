#include <iostream>
#include <stdio.h>
using namespace std;
const double eps = 1e-15;

double square2(double left, double right)
{
    double mid = (left + right) / 2;
    if (right - left > eps)
    {
        if (mid * mid < 2)
        {
           return square2(mid, right);
        }
        else if (mid * mid > 2)
        {
            return square2(left, mid);
        }
    }

    return mid;
}

int main()
{
    double a = square2(1, 2);
    printf("%.15f", a);
    // cout<<square2(1,2);
}