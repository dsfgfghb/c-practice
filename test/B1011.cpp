#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll A,B,C;
    int T;
    cin>>T;
    for (int i = 0; i <T; i++)
    {
        cin>>A>>B>>C;
        if (A>C-B)
        {
            cout<<"Case#"<<i+1<<":"<<"true";
        }
        else
        {
            cout<<"Case#"<<i+1<<":"<<"false";
        }
        
        
    }
    
    return 0;
}