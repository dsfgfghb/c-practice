// 最长公共子序列
#include <iostream>
using namespace std;

int main()
{
    int len1, len2;
    string s1, s2;
    cin >> s1 >> s2;
    len1 = s1.length();
    len2 = s2.length();
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= len2; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[len1][len2];
    return 0;
}