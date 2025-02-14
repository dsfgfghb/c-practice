#include <iostream>
#include <algorithm>
using namespace std;
#define maxN 100000

struct Node
{
    int address;
    int data;
    bool flag = false;
    int next = -1;
};

bool cmp(Node a, Node b)
{
    if (a.flag == false || b.flag == false)
    {
        return a.flag > b.flag;
    }
    return a.data < b.data;
}

int main()
{
    Node link[maxN];
    int n, head, next, num;
    cin >> n >> head;
    for (int i = 0; i < n; i++)
    {
        cin >> head >> num >> next;
        link[head].address = head;
        link[head].data = num;
        link[head].next = next;
        link[head].flag = true;
    }
    sort(link, link + maxN, cmp);
    for (int i = 0; i < n; i++)
    {
        if (link[i].flag)
        {
            cout << link[i].address<<" "<<link[i].data<<" "<<link[i].next<<endl;
        }
    }
    return 0;
}