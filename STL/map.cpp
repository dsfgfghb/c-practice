#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    map<string,int> m;  //map的定义  数组不能作为键值
    map<set<int>,int> m2;   //map的键和值也可以是STL容器
    m2[{1,2,3}]=2;
    m["hello"] = 1;
    m["world"] = 2;
    //map的访问
    //1. 通过下标访问
    //2. 通过迭代器访问
    map<string,int>::iterator it = m.begin();
    for(;it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;   //it->first表示键，it->second表示值
    }


    //map常用函数
    //1.find(key)    查找key对应的迭代器，如果找不到，返回end()     O(logN)
    //2.erase(key)    删除key对应的键值对，返回删除的迭代器      O(logN)
    //erase(it)    删除迭代器it指向的键值对，返回删除的迭代器       O(1)
    //3.size()    返回map的大小    O(1)
    //4.clear()    清空map    O(1)
}