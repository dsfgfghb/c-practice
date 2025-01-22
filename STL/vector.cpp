#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> name;   //一个容器
    vector<vector<int>> name2;  //每一个元素都是一个vector
    vector<int> name3[100];     //创建一个vector数组  name3[0]到 name3[99] 都是一个vector容器

    //vector容器的访问:
    //1.通过下标访问
    //2.通过迭代器访问
    vector<int>::iterator it;         //迭代器it  类似指针
    for(int i=1;i<=5;i++){
        name.push_back(i);
    }
    it=name.begin();        //it指向name的第一个元素   name.begin()为取name的首元素地址
    for(int i=0;i<5;i++){
        cout<<*(it+i)<<" ";        //name[i] 与 *(vi.begin()+i)    是等价的
    }
    cout<<endl;
    for(it=name.begin();it!=name.end();it++){       //迭代器it++ 可自增
        cout<<*it<<" ";
    }
    cout<<endl;
    //vector 常用函数:
    //1.push_back()  向容器尾部添加元素        O(1)
    //2.pop_back()   删除容器尾部元素          O(1)
    //3.size()       返回容器中元素的个数      O(1)
    //4.clear()      删除容器中所有元素         O(N)
    //5.insert(it,x)    用来在it位置插入x元素   O(N)
    //6.erase(it)  用来删除it位置的元素   O(N)   erase(first,last)  用来删除[first,last)内所有的元素   O(N)  


    name.insert(name.begin()+2,100);   //在name[2]位置插入100   
    for(it=name.begin();it!=name.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    name.erase(name.begin()+2);        //删除name[2]位置的元素
    for(it=name.begin();it!=name.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    name.erase(name.begin(),name.begin()+2);   //删除[0,2)内所有的元素  0和1
    for(it=name.begin();it!=name.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}