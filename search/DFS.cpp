#include <iostream>
using namespace std;
int maxv = -999, n, maxw;
int item[9999], w[9999], v[9999];

void dfs(int i, int sumw, int sumv)
{
    if (i == n)return;
    dfs(i + 1, sumw, sumv);
    if(maxw >= sumw+ w[i])
    {
        maxv = sumv+ v[i] > maxv ? sumv+ v[i] : maxv;
        dfs(i + 1, sumw + w[i], sumv + v[i]);
    }
}

int main()
{
    cin >> n >> maxw;
    for (int i; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    dfs(0, 0, 0);
    cout << maxv;
    return 0;
}