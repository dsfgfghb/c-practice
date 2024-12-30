#include <bits/stdc++.h>

int main()
{
    int n,x;
    int arr[200];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        scanf("%d",&x);
        int k;
        for (k = 0; k < n; k++)
        {
            if (arr[k]==x)
            {
                printf("%d\n",k);
                break;
            }
            
        }
        if (k==n)
        {
            printf("-1");
        }
        
    }
    return 0;
}