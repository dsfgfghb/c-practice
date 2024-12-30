#include <iostream>
using namespace std;
typedef long long LL;

LL PturnT(LL x,LL p)
{
    LL y=0,product=1;
    while (x!=0)
    {
        y=y+(x%10)*product;
        x=x/10;
        product*=p;
    }
    return y;
}

LL TturnP(LL x,LL p)
{
    int arr[100000]={0},num=0;
    do
    {
       arr[num++]=x%p;
       x=x/p;
    } while (x!=0);
    LL y=0;
    for (int i=num-1;i>=0;i--)
    {
        y=y*10+arr[i];
    }
    return y;
    
}


int main()
{
    // int DateA[4],DateB[4];
    int a, b, ans = 1;
    cin >> a >> b;
    // DateA[0]=a/10000;
    // DateA[1]=a%10000/100;
    // DateA[2]=a%100;
    // DateB[0]=b/10000;
    // DateB[1]=b%10000/100;
    // DateB[2]=b%100;
    int temp = 0;
    if (a > b)
    {
    }
    else
    {
        temp = a;
        a = b;
        b = temp;
    }
    int y1, m1, d1, y2, m2, d2;
    y1 = a / 10000;
    m1 = a % 10000 / 100;
    d1 = a % 100;
    y2 = b / 10000;
    m2 = b % 10000 / 100;
    d2 = b % 100;
    while (y1 > y2 || m1 > m2 || d1 > d2)
    {
        ans++;
        switch (m2)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if (d2 < 31)
            {
                d2++;
            }
            else
            {
                m2++;
                d2 = 0;
            }
            break;
        case 12:
            if (d2 < 31)
            {
                d2++;
            }
            else
            {
                y2++;
                m2 = 1;
                d2 = 1;
            }
            break;
        case 2:
            if (b / 10000 % 4 == 0 && b / 10000 % 100 != 0 || b / 10000 % 400 == 0)
            {
                if (d2 < 29)
                {
                    d2++;
                }
                else
                {
                    m2++;
                    d2 = 0;
                }
            }
            else
            {
                if (d2 < 28)
                {
                    d2++;
                }
                else
                {
                    m2++;
                    d2 = 0;
                }
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (d2 < 30)
            {
                d2++;
            }
            else
            {
                m2++;
                d2 = 0;
            }
            break;
        default:
            break;
        }
        
    }
    cout<<ans;
    return 0;
}