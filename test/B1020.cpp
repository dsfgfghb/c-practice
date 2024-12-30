#include <iostream>
#include <algorithm>
using namespace std;
struct B1020
{
    float Totalprice;
    float num;
    float price;
};

bool cmp(B1020 a, B1020 b)
{
    return a.price > b.price;
}

int main()
{
    int n, m;
    B1020 b1020[10005];
    float ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> b1020[i].num;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b1020[i].Totalprice;
        b1020[i].price = b1020[i].Totalprice / b1020[i].num;
    }
    sort(b1020 + 1, b1020 + n + 1, cmp);
    int k = 1;
    while (m)
    {
        if (m >= b1020[k].num)
        {
            m -= b1020[k].num;
            ans += b1020[k].Totalprice;
        }
        else if (b1020[k].num - m >= 0)
        {   
            ans += b1020[k].price * m;
            m = 0;
        }
        k++;
    }
    cout << ans << endl;
    return 0;
}