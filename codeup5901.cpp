#include <iostream>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int head=0,end;
    end=a.length()-1;
    while (head<end)
    {
        if (a[head]==a[end]){}
        else{cout<<"NO!";return 0;}
        head++;end--;
    }
    cout<<"YES!";
}