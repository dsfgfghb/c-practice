#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int num[10],min_num,min_i,ans[50]={0};
    for (int i = 0; i < 10; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i < 10; i++)
    {
        if (num[i])
        {
            ans[0]=i;
            num[i]--;
            break;
        }
        
    }
    int k=1;
    for (int i = 0; i < 10; i++)
    {
        if (num[i])
        {
            while (num[i]!=0)
            {
                num[i]--;
                ans[k]=i;
                k++;
            }
        }
        
    }
    
    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> num[i];
    //     if (i == 0)
    //     {
    //         min_num = num[i];
    //         min_i = i;
    //     }
    //     else
    //     {
    //         if (num[i] < min_num&&num[i] != 0)
    //         {
    //             min_num = num[i];
    //             min_i = i;
    //         }
    //     }
    // }
    // int temp=min_num;
    // num[min_i]=num[0];
    // num[0]=temp;
    // sort(num+1,num+10);
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << num[i];
    // }
    for (int i = 0; i <k; i++)
    {
        cout<<ans[i];
    }
    
    return 0;
}