#include <iostream>
using namespace std;
typedef long long LL;

int P[10000], IsUsed[10000], P_n, QueenSum = 0;
void Full_permutation(LL x)
{
    if (x == P_n + 1)
    {
        for (int i = 0; i < P_n; i++)
        {
            cout << P[i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < P_n; i++)
    {
        if (!IsUsed[i])
        {
            P[i] = x;
            IsUsed[i] = 1;
            Full_permutation(x + 1);
            IsUsed[i] = 0;
        }
    }
}

void N_queen_baoli(int line)
{
    if (line == P_n + 1)
    {
        int is_ok = 1;
        for (int i = 1; i <= P_n; i++)
        {
            for (int j = i + 1; j <= P_n; j++)
            {
                if (abs(i - j) == abs(P[i] - P[j]))
                {
                    is_ok = 0;
                    break;
                }
            }
        }
        if (is_ok)
        {
            QueenSum++;
        }
        return;
    }

    for (int i = 1; i <= P_n; i++)
    {
        if (!IsUsed[i])
        {
            P[i] = line;
            IsUsed[i] = 1;
            N_queen_baoli(line + 1);
            IsUsed[i] = 0;
        }
    };
}
void N_queen_huishu(int x)
{
    if (x == P_n + 1)
    {
        QueenSum++;
        return;
    }
    for (int i = 1; i <= P_n; i++)
    {
        if (IsUsed[i])
        {
            continue;
        }
        bool Flag = 1;
        for (int j = 1; j < x; j++)
        {
            if (abs(x - j) == abs(i - P[j]))
            {
                Flag = 0;
                break;
            }
        }
        if (Flag)
        {

            P[x] = i;
            IsUsed[i] = 1;
            N_queen_huishu(x + 1);
            IsUsed[i] = 0;
        }
    }
}
LL PturnT(LL x, LL p)
{
    LL y = 0, product = 1;
    while (x != 0)
    {
        y = y + (x % 10) * product;
        x = x / 10;
        product *= p;
    }
    return y;
}

LL TturnP(LL x, LL p)
{
    int arr[100000] = {0}, num = 0;
    do
    {
        arr[num++] = x % p;
        x = x / p;
    } while (x != 0);
    LL y = 0;
    for (int i = num - 1; i >= 0; i--)
    {
        y = y * 10 + arr[i];
    }
    return y;
}

LL StringToLL(string s)
{
    LL x = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            x = x * 52 + (s[i] - 'a' + 26);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            x = x * 52 + (s[i] - 'A');
        }
    }
    return x;
}

string LLToString(LL x)
{
    string s;
    string res;
    int num = 0;
    do
    {
        if (x % 52 < 26)
        {
            s += char(x % 52) + 'A';
        }
        else
        {
            s += char(x % 52) + 'a';
        }
        x = x / 52;
    } while (x != 0);
    for (int i = 0; i < s.length(); i++)
    {
        res += s[s.length() - 1 - i];
    }
    return res;
}



int main()
{
    LL a = StringToLL("BCD");
    string s = LLToString(a), z = "ABC";
    z += "DEF";
    cout << s << z << endl;
    P_n = 5;
    Full_permutation(1);

    P_n = 5;
    N_queen_baoli(1);
    cout << QueenSum << endl;
    ;
    QueenSum = 0;
    N_queen_huishu(1);
    cout << QueenSum;
    return 0;
}