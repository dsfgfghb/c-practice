#include <iostream>
#include <vector>
using namespace std;

#define BIG_NUM 1000000
#define MAX_NODES 500

struct Node
{
    int v;   // vertex
    int dis; // distance
};

vector<Node> adj[MAX_NODES]; // adjacency list
int weight[MAX_NODES];       // each node's weight
int dis[MAX_NODES];          // distance from start node
int vis[MAX_NODES];          // visited or not
int prv[MAX_NODES];          // previous node
int num[MAX_NODES] = {0};    // number of shortest path
int w[MAX_NODES] = {0};      // weight of shortest path
int n, m;
void dijkstra(int s)
{
    num[s] = 1;
    fill(dis, dis + MAX_NODES, BIG_NUM);
    fill(vis, vis + MAX_NODES, 0);
    fill(prv, prv + MAX_NODES, -1);
    dis[s] = 0;
    for (int i = 0; i < n; i++)         
    {
        int u = -1, minn = BIG_NUM;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == 0 && dis[j] < minn)       
            {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
            break;
        vis[u] = 1;
        for (int v = 0; v < adj[u].size(); v++)
        {
            int j = adj[u][v].v;
            if (!vis[j])
            {
                if (dis[u] + adj[u][v].dis < dis[j])
                {
                    dis[j] = dis[u] + adj[u][v].dis;
                    prv[j] = u;
                    num[j] = num[u];
                    w[j] = w[u]+weight[j];
                }
                else if (dis[u] + adj[u][v].dis == dis[j])
                {
                    num[j] += num[u];
                    if(w[u]+ weight[j]>w[j]){
                        w[j] = w[u]+weight[j];
                    }
                }
            }
        }
    }
}
int main()
{
    int c1, c2;
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Node{v, w});
        adj[v].push_back(Node{u, w});
    }
    dijkstra(c1);
    cout << num[c2] <<" "<<w[c2] << endl;
    return 0;
}
