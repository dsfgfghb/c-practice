#include <iostream>
using namespace std;
int gac(int n, int m)
{
    return !m ? n : gac(m, n % m); // 求最大公约数  gac(n,m) = gac(m,n%m)
}

int lcm(int n, int m)
{
    return n * m / gac(n, m); // 求最小公倍数  lcm(n,m) = n*m/gac(n,m)
}

struct factor
{
    int x, cnt;
} fac[10]; // 素因子分解, 由于前10个素数的乘积已经超过了int的范围，所以只需要10个

long long *Eratosthenes(long long n)// eratosthenes法求素数
{ 
    // int prime[n+1];
    long long *prime = new long long[n + 1];
    bool *p = new bool[n + 1];
    for (long long i = 0; i <= n; i++)
    {
        p[i] = false;
    }
    // bool p[n+1]={false};
    long long k = 0;
    for (long long i = 2; i <= n; i++)
    {
        if (p[i] == false) // 之前未标记的都为素数
        {
            prime[k++] = i;
        }
        for (long long j = i + i; j <= n; j += i)
        { // 把i的倍数都做标记
            p[j] = true;
        }
    }
    return prime;
}

void factorize(int n)       //素因子分解
{
    long long *prime = Eratosthenes(n);
    for (int i = 0; i < 10; i++)
    {
        if (n % prime[i] == 0)
        {
            fac[i].x = prime[i];
            fac[i].cnt = 0;
            while (n % prime[i] == 0)
            {
                fac[i].cnt++;
                n /= prime[i];
            }
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gac(a, b) << endl;
    cout << lcm(a, b) << endl
         << endl;
    factorize(648);
    for (int i = 0; i < 10; i++)
    {
        if (fac[i].cnt > 0)
        {
            cout << fac[i].x << " " << fac[i].cnt << endl;
        }
    }
    return 0;
}