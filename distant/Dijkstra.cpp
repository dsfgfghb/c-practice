#include <iostream> 
using namespace std;
#define BIG_NUM 1000000

int main()
{
    int pointNum,edgeNum,start;
    cin>>pointNum>>edgeNum>>start;
    int **graph = new int*[pointNum];
    int *dis = new int[pointNum];
    int *vis = new int[pointNum];
    for(int i = 0;i<pointNum;i++)
    {
        graph[i] = new int[pointNum];
        for(int j = 0;j<pointNum;j++)
        {
            graph[i][j] = BIG_NUM;
        }
    }
    for(int i = 0;i<edgeNum;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
    }   
    for(int i = 0;i<pointNum;i++)
    {
        dis[i] = BIG_NUM;
        vis[i] = 0;
    }
    dis[start] = 0;
    
    for(int i=0;i<pointNum;i++)
    {
        int u=-1,minn = BIG_NUM;
        for(int j=0;j<pointNum;j++)
        {
            if(vis[j]==0&&dis[j]<minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if(u==-1) break;
        vis[u] = 1;
        for(int v=0;v<pointNum;v++)
        {
            if(vis[v]==0&&graph[u][v]!=BIG_NUM)
            {
                if(dis[v]>dis[u]+graph[u][v])
                {
                    dis[v] = dis[u]+graph[u][v];
                }
            }
        }

    }
    for(int i = 0;i<pointNum;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}
