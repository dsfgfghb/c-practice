#include <iostream>
#include <string.h>
using namespace std;

int find(int x,int *father) {
    if (father[x] != x) {
        father[x] = find(father[x],father); 
    }
    return father[x];
}
int main()
{
    int n, m;
    cin >> n>> m;
    int *father = new int[n+1];
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        father[find(a,father)] = find(b,father);
    }
    for(int i=1; i<=n; i++)
    {
        if (father[i] != i) {
            father[i] = find(father[i],father); 
        }
        cout << father[i] << endl;
    }
    delete[] father;
    return 0;
}