#include <iostream>
#include <string>
using namespace std;
int Mod = 1e9 + 7;

int main()
{
    string str;
    char P[100000]={0};
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (i != 0)
        {
            P[i] = P[i - 1];
        }
        if (str[i] == 'P')
        {
            P[i]++;
        }
    }
    int ans = 0,T=0;
    for (int i = str.length()-1; i >= 0; i--)
    {
        if (str[i] == 'T'){
            T++;
        }
        if(str[i]=='A'){
            ans += (P[i] * T) % Mod;
        }
    }
    cout << ans % Mod;
}