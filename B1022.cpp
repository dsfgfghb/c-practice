#include<iostream>
using namespace std;
typedef long long ll;
ll TturnP(ll x,ll p)
{
    int arr[100000]={0},num=0;
    do
    {
       arr[num++]=x%p;
       x=x/p;
    } while (x!=0);
    ll y=0;
    for (int i=num-1;i>=0;i--)
    {
        y=y*10+arr[i];
    }
    return y;
}
int main()
{
    ll A,B,sum,p;
    cin>>A>>B;
    sum=A+B;
    cin>>p;
    cout<<TturnP(sum,p)<<endl;
    return 0;
}