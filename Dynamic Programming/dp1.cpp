#include <iostream>
using namespace std;
const int MAXN = 1000;
int dp1[MAXN];
int F(int n){
    if(n == 0)return 0;
    if(dp1[n]!=-1)return n;
    else{
        dp1[n] = F(n-1) + F(n-2);
        return dp1[n];
    }
}


int main(){
    
}
