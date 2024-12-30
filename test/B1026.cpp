#include<iostream>
using namespace std;
int main()
{
    int c1,c2;
    int diff;
    int CLK_TCK=100;
    int h,m,s;
    cin>>c1>>c2;
    diff=c2-c1;
    if (diff%100>=50)
    {
        diff=diff/CLK_TCK+1;
    }
    else
    {
        diff=diff/CLK_TCK;
    }
    h=diff/3600;
    m=(diff%3600)/60;
    s=diff%60;
   
    cout<<h<<":"<<m<<":"<<s<<endl;
    return 0;
}