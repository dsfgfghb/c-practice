#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 200;
int n,m;
int dis[MAXN][MAXN];    //i到j的最短距离

void floyd(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(dis[i][k]!=INF&&dis[k][j]!=INF){
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dis[i][j] = INF;
        }
    }
    for(int i = 1;i<=n;i++){
        dis[i][i] = 0;
    }
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b] = c;
    }
    floyd();
    return 0;
}