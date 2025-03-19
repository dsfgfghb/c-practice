//拓扑排序
#include <iostream>     
#include <vector>   
#include <queue>
using namespace std;
vector<int> G[100]; //图
int in[100]; //入度

bool topologicalSort(int n,int m){
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i];
            in[v]--;
            if(in[v] == 0){
                q.push(v);
            }
        }
    }
    return cnt == n;        //判断排序成功
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        in[b]++;
    }
    if(topologicalSort(n,m))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}