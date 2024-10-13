#include <iostream>
#include <vector>
using namespace std;

int get_num()
{
    vector<char> arr;
    int ans=1;
    int time=0;
    char temp;
    temp=getchar();
    while (temp>='0'&&temp<='9')
    {
        arr.push_back(temp);
        temp=getchar();
    }
    temp=getchar();
    ans = temp-'0';
    for(char i:arr)
    {
        if (i==temp)
        {
            time++;
            
        }
        cout<<i;
    }
    cout<<endl;
    for (int i = 0; i < time-1; i++)
    {
        ans=ans*10+(temp-'0');
        
        
    }
    temp=getchar();
    return ans;
}

int main()
{
    cout<<get_num()+get_num();    
    return 0;
}