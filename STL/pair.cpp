#include<iostream>
#include<utility>                                    
using namespace std;

int main(){
    pair<int,int> p;
    p.first = 10;
    p.second = 20;
    cout<<p.first<<" "<<p.second<<endl; 
    //判断时如果first相等,才判别second的大小
}