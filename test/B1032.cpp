#include <bits/stdc++.h>

int main()
{
    int n;
    int a,temp,max = 0,k;
    int SchoolTS[100000];
    memset(SchoolTS, 0, sizeof(SchoolTS));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        scanf("%d", &temp);
        SchoolTS[a]+= temp;
        if (max<=SchoolTS[a])
        {
            max=SchoolTS[a];
            k=a;
        }
    }
    printf("%d %d\n", k, max);
}