#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char m;
    cin >> m;
    int col = n%2==0?n/2:n/2+1;
    for (int i = 0; i < col; i++)
    {
        if (i==0||i==col-1)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<m;
            }
            cout<<endl;
        }
        else
        {
            cout<<m;
            for (int j = 1; j < n-1; j++)
            {
                cout<<" ";
            }
            cout<<m<<endl;
            
        }
        
    }
    
}