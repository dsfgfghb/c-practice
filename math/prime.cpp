#include <iostream>
#include <ctime>
using namespace std;

void Eratosthenes(long long n) {          //eratosthenes法求素数
    long long* prime = new long long[n+1];
    bool* p = new bool[n+1];
    for(long long i=0;i<=n;i++){
        p[i]=false;
    }
    long long k=0;
    for(long long i=2;i<= n;i++){
        if (p[i]==false)            //之前未标记的都为素数
        {
            prime[k++]=i;
        }
        for(long long j=i+i;j<=n;j+=i){   //把i的倍数都做标记
            p[j]=true;
        }
    }
    for(long long i=0;i<k;i++){
        cout<<prime[i]<<endl;
    }
}


int main(){
    clock_t start,finish;
    start=clock();
    Eratosthenes(100000000);
    finish=clock();
    cout<<"time:"<<double(finish-start)/CLOCKS_PER_SEC<<"s"<<endl;
}