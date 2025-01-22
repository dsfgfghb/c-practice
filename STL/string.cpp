#include<iostream>
#include<string>
using namespace std;


int main(){
    string str = "abcd";
    //string访问:
    //1.通过下标访问        str[i]  
    //若要读入和输出整个字符串,则只能用cin和cout
    //用printf输出string:
    printf("%s\n",str.c_str());   //c_str()将string转化为字符数组进行输出

    //2.通过迭代器访问
    string :: iterator it;       //定义迭代器it
    for(it = str.begin();it != str.end();it++){     //用迭代器访问每一位 string支持直接对迭代器进行加减某个数字 如str.begin()+3
        cout<<*it<<endl;
    }

    //string常用函数:
    //1.operator+=      可以将两个string直接拼接起来
    string str1 = "hello";
    string str2 = "world";
    str1 += str2;
    cout<<str1<<endl;   //helloworld

    //2.compare operator == != > < >= <=  比较规则是字典序
    //3.length() / size()  返回字符串长度       O(1)
    //4.insert(pos,string)  在pos位置插入string  O(N)
    //insert(it,it2,it3)    在it位置插入it2到it3之间的元素 将[it2.it3) 插入it的位置上

    //5.erase(it)           删除it位置的元素
    //erase(first,last)     删除[first,last)之间的元素
    //erase(pos,length)     删除pos位置开始的length个元素

    //6.clear()             清空字符串      O(1)
    //7.substr(pos,length)   返回pos位置开始,长度为length的子串     O(length)
    //8.string::npos        find函数的返回值 可以判断是否找到 值可视为-1或4294967295
    //9.find(string)         查找string的位置,返回第一次出现的位置,若没有找到返回  O(nm)    n为字符串长度,m为查找字符串长度
    return 0;
}