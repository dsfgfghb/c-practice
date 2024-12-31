#include <iostream>
#include <ctime>
using namespace std;

long long cal1(long long n,int p){       //求n中有多少个p的因子      //暴力
    long long ans = 0 ;
    for(int i = 1; i<=n; i++){
        if(i%p==0){
            int cnt = i;
            while (cnt%p==0)
            {
                ans++;
                cnt/=p;
            }
        }
    }
    return ans;
}

long long cal2(long long n,int p){       //求n中有多少个p的因子 因子个数:(n/p+n/p^2+n/p^3+...)  //优化
    long long ans = 0;
    while (n)
    {
        ans+=n/p;           //加上 n/p^k;
        n/=p;               //除以p 
    }
    return ans;
}

long long cal3(long long n,int p){          //递归版本
    if (n<p) return 0;
    return n/p+cal3(n/p,p);
}

// int cal3(int n){     //1 2 3 4 5 6...11 12 13 ... 22 23..123 124...  cal 1+2+...+1+1+1+2+....1+2+3(123)...
//     int ans = 0;
//     int ctn = 0;
//     int num = 45;
//     int temp=10;
//     while(n/temp!=0){
        

//     }
    
//     return ans;
// }

int main(){
    clock_t start,finish;
    start = clock();
    // cout<<cal1(10000000000,2)<<endl;
    cout<<cal1(100000000000000000,4)<<endl;
    finish = clock();
    cout<<"time:"<<double(finish-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}