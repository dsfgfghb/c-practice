#include <iostream>
#include <queue>
using namespace std;

struct fruit{
        string name;
        int price;
        friend bool operator < (fruit a, fruit b) {
            return a.price < b.price;
        }
}f1,f2,f3;
int main() {
    queue<int> q;   
    //queue内元素访问:
    q.push(1);
    q.push(2);
    cout << q.front() << endl;//访问队首  
    cout<<q.back()<<endl;   //访问队尾

    //queue常用函数:
    //1.push(x)  入队    O(1)
    //2.pop()    出队    O(1)
    //3.empty()  判断队列是否为空    O(1)
    //4.size()   返回队列长度    O(1)
    //5.front()  返回队首元素    O(1)
    //6.back()   返回队尾元素    O(1)       


    //优先队列
    priority_queue<int> pq;
    for (int i = 0; i < 10; i++) pq.push(i);
    for(int i = 0; i < 10; i++) {cout << pq.top() << " "; pq.pop();}    //priority_queue只能用top()访问队首元素

    //优先队列常用函数:
    //1.push(x)  入队    O(logn)
    //2.pop()    出队    O(logn)
    //3.empty()  判断队列是否为空    O(1)
    //4.size()   返回队列长度    O(1)
    //5.top()    返回队首元素    O(1)

    //优先队列内元素优先级设置:
    priority_queue<int, vector<int>, greater<int>> pq2;  //greater<int>表示优先级为从大到小  less<int>表示优先级为从小到大
    
    priority_queue<fruit> pq1;
    f1.name = "apple";
    f1.price = 10;
    f2.name = "banana";
    f2.price = 20;
    f3.name = "orange";
    f3.price = 30;
    pq1.push(f1);
    pq1.push(f2);
    pq1.push(f3);
    while(!pq1.empty()) {
        cout << pq1.top().name << " " << pq1.top().price << endl;
        pq1.pop();
    }
    return 0;
}
