#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 110;   // 最大点数
const int MAXE = 10010; // 最大边数

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &A) const
    {
        return w < A.w;
    }
} E[MAXE];

int fa[MAXN]; // 并查集

// 初始化并查集
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
}

// 查找操作（路径压缩）
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

// 合并操作
void merge(int x, int y)
{
    fa[find(x)] = find(y);
}


int kruskal(int n, int m){
    

    // 初始化并查集
    init(n);

    // 按权重排序边
    sort(E, E + m);

    int totalWeight = 0;
    int edgeCount = 0;

    for (int i = 0; i < m; ++i)
    {
        int u = E[i].u;
        int v = E[i].v;
        int w = E[i].w;

        if (find(u) != find(v))
        {
            merge(u, v);
            totalWeight += w;
            edgeCount++;

            // 如果已经选择了 n-1 条边，说明最小生成树已经构建完成
            if (edgeCount == n - 1)
            {
                break;
            }
        }
    }

    if (edgeCount == n - 1)
    {
        return totalWeight;
    }
    else
    {
        cout << "Graph is not connected, no spanning tree exists." << endl;
        return -1;
    }
    return totalWeight;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    cout << kruskal(n, m) << endl;
    return 0;
}