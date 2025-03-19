#include <iostream>
using namespace std;
const int MAXN = 100;
int dp1[MAXN];

int F(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    if(dp1[n]!=-1)return n;
    else{
        dp1[n] = F(n-1) + F(n-2);
        return dp1[n];
    }
}

void dp(){
    int dp2[MAXN][MAXN];
    int weight[MAXN][MAXN]; 
    int n;
    cin>>n;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=i;j++){
            cin>>weight[i][j];
        } 
    }
    for(int i = 1;i<=n;i++){
        dp2[n][i] = weight[n][i];  
    }
    for(int i = n-1;i>=1;i--){
        for(int j = 1;j<=i;j++){
            dp2[i][j] = max(dp2[i+1][j],dp2[i+1][j+1]) + weight[i][j];
        }       
    }
    cout<<dp2[1][1]<<endl;
}

int main(){
    fill(dp1,dp1+MAXN,-1);
    cout<<F(10)<<endl;
    dp();
    return 0;
}
