#include <iostream>
using namespace std;
int first_win()
{
    int a,a1,b,b1;
    int a1_win=0,b1_win=0;
    cin>>a>>a1>>b>>b1;
    if (a1==a+b)
    {
        a1_win=1;
    }
    if (b1==a+b)
    {
        b1_win=1;
    }
    if ((b1_win==1&&a1_win==1)||(b1_win!=1&&a1_win!=1))
    {
        return 0;
    }
    return a1_win==1?1:2;
}
int main()
{
    int n;
    int temp;
    int a=0,b=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        temp=first_win();
        switch (temp)
        {
        case 1:
            a++;
            break;
        case 2:
            b++;
            break;
        default:
            break;
        }
    }
    cout<<b<<" "<<a<<endl;
    return 0;
}