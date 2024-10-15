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

LL StringToLL(string s)
{
    LL x=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]>='a'&&s[i]<='z')
        {
            x=x*52+(s[i]-'a'+26);
        }
        else if (s[i]>='A'&&s[i]<='Z')
        {
            x=x*52+(s[i]-'A');
        }
        
    }
    return x;
}

string LLToString(LL x)
{
    string s;
    string res;
    int num=0;
    do
    {
        if (x%52<26)
        {
            s[num++]=char(x%52)+'A';
        }
        else
        {
            s[num++]=char(x%52)+'a';
        }
        x=x/52;
    } while (x!=0);
    for (int i = 0; i < num; i++)
    {
        res[i]=s[num-i-1];
    }
    return res;
}

int main()
{
    LL a=StringToLL("BCD");
    string s=LLToString(a);
    cout<<s[0]<<s[1]<<s[2];
    return 0;
}