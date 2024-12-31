#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
// typedef long long ll;

ll calc(ll m,ll n){         //计算C(m,n)    //暴力算法
    long long ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
    }
    for(ll i=1;i<=m;i++){
        ans/=i;
    }
    for(ll i=1;i<=n-m;i++){
        ans/=i;
    }
    return ans;
}

ll calc2(ll m,ll n){        //C(m,n) = C(m,n-1) + C(m-1,n-1) //递归计算
    if(m==0||m==n) return 1;
    return (calc2(m,n-1) + calc2(m-1,n-1));
}

ll res[10000][10000]={0};

ll calc3(ll m,ll n){        //记忆化搜索  避免了重复计算   

    if(res[m][n]!=0) return res[m][n];
    if(m==0||m==n) return 1;
    return res[m][n] = calc3(m,n-1) + calc3(m-1,n-1);
}

ll calc4(ll m, ll n){        //C(m,n) 的 变式
    ll ans = 1;
    for(ll i=1 ; i<=m ; i++){
        ans = ans * (n-m+i)/i;
    }
    return ans;
}

ll CalC_p(ll m,ll n,ll p){
    if(m==0||m==n) return 1;
    if(res[m][n]!=0) return res[m][n];
    return res[m][n] = (CalC_p(m,n-1,p) + CalC_p(m-1,n-1,p))%p; 
}

int main(){
    cout<< calc3(12,30) << endl;
    memset(res,0,sizeof(res));
    cout<<CalC_p(12,30,1000000007)<<endl;
    return 0;
}