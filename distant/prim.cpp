#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 200;
vector <int> G[MAXN];//图

void prim(int s,vector <int> &d,vector <int> &visit){
    d.resize(MAXN);
    fill(d.begin(),d.end(),INF);
    fill(visit.begin(),visit.end(),0);
    d[s] = 0;   
    for(int i = 0;i < MAXN;i++){
        int u = -1,minn=INF;
        for(int j = 0;j < MAXN;j++){
            if(visit[j] == 0 && d[j] < minn){
                u = j;
                minn = d[j];
            }
        }
        if(u == -1) break;
        visit[u] = 1;
        for(int j = 0;j < G[u].size();j++){
            int v = G[u][j];
            if(visit[v] == 0 && d[v] > G[u][j]){
                d[v] = G[u][j];
            }
        }

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back(c);
        G[b].push_back(c);
    }
    vector <int> visit;
    vector <int> d;
    prim(0,d,visit);
    
    return 0;
}