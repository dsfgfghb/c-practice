//最大连续子序列和
//输入：-2 11 -4 13 -5 -2
//输出：20
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int height, num = 0, ans = -1;
    vector<int> A;
    vector<int> dp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            height = stoi(s.substr(0, i));
            A.push_back(height);
            if (num == 0)
            {
                dp.push_back(A[num]);
                ans = dp[num];
            }
            else
            {
                dp.push_back(max(dp[num - 1] + A[num], A[num]));
                ans = max(ans, dp[num]);
            }
            num++;
            s = s.substr(i + 1);
            i = 0;
        }
    }
    cout << ans;
    return 0;
}