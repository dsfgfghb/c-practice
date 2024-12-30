#include <iostream>
using namespace std;
int gac(int n,int m){
    return !m ? n :gac(m,n%m);          //求最大公约数  gac(n,m) = gac(m,n%m)
}

int lcm(int n,int m){
    return n*m/gac(n,m);            //求最小公倍数  lcm(n,m) = n*m/gac(n,m)
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gac(a,b)<<endl;
    cout<<lcm(a,b)<<endl;
    return 0;
}