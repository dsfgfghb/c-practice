#include<iostream>
#include<string>
#include <map>
using namespace std;

int number =0;
map<int,string> mp;
map<string,int> mp2;
map<int,int> gang;
map<int,int> weight;
map<int,int> vis;
int G[2010][2010] = {0};

int getnum(string name){
    if(mp2.find(name) != mp2.end()){
        return mp2[name];
    }else{
        mp2[name] = number;
        mp[number] = name;
        return number++;
    }
}

void DS(int curvisit,int &head ,int &Member,int &totalWeight){
    vis[curvisit] = 1;
    Member++;
    
    if(weight[curvisit] > weight[head]){
        head = curvisit;
    }
    for(int i=0;i<number;i++){
        if(G[curvisit][i] > 0){
            totalWeight += G[curvisit][i];
            G[curvisit][i] =0;
            G[i][curvisit] = 0;
            DS(i,head,Member,totalWeight);
            
        }
    }
}

void SAll(int k){
    for(int i=0;i<number;i++){
        if(vis[i] == 0){
            int head = i,Member = 0,weight = 0;
            DS(i,head,Member,weight);
            if(Member > 2 && weight > k){
                gang[head] = Member;
            }
        }
    }
}

int main(){
    int N,k,num;
    cin >> N >>k;
    string name1,name2;
    int w;
    for(int i=0;i<N;i++){
        cin >> name1 >> name2 >> w;
        getnum(name1);
        getnum(name2);
        weight[mp2[name1]] += w;
        weight[mp2[name2]] += w;
        G[mp2[name1]][mp2[name2]] += w;
        G[mp2[name2]][mp2[name1]] += w;
    }
    SAll(k);
    cout << gang.size() << endl;
    for(auto it = gang.begin();it != gang.end();it++){
        cout << mp[it->first] << " " << it->second << endl;
    }
}