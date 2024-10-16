#include <iostream>
#include <string.h>
using namespace std;
typedef long long LL;

int P[10000], IsUsed[10000], P_n, QueenSum = 0;

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

int main()
{
    while (cin >> P_n)
    {
        cout << P_n << " ";
        QueenSum = 0;
        memset(IsUsed, 0, sizeof(IsUsed));
        N_queen_huishu(1);
        cout << QueenSum << endl;
    }
}