#include<iostream> 
#include<set>
using namespace std;

//set 是一个 内部自动有序 且 不含重复元素 的容器
int main(){
    set<int> s; //set容器的定义与vector相同

    //set容器的访问只能通过迭代器访问
    set<int>::iterator it;
    for(int i=10;i>0;i--){
        s.insert(i);
    }
    for(it=s.begin();it!=s.end();   it++   ){     //除开vector 和 string之外的STL容器都不支持*(it+i)的访问方式
        cout<<*it<<" ";
    }
    cout<<endl;

    //set常用函数
    //1.insert(x)    将x插入到set容器中,并自动排序和去重  O(logN) 
    //2.find(x)       查找x是否存在于set容器中,返回迭代器  O(logN)
    //3.erase(it)     删除it迭代器对应的元素 O(1)  
    //erase(value) value为所需要删除的元素的值     O(logN)
    //erase(first,last) first和last为迭代器，删除[first,last)区间的元素  O(last-first)
    //4.size()          返回set容器中元素的个数         O(1)
    //5.clear()          清空set容器中所有元素            O(N)
    return 0;
}