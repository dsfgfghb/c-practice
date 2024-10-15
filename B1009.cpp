#include <iostream>
using namespace std;
int main()
{
    char arr[80][80],s,i=0;
    while (scanf("%s",arr[i])!=EOF)
    {
        i++;
    }
    while (i>=0)
    {
        cout<<arr[i]<<" ";
        i--;
    }
    return 0;
}