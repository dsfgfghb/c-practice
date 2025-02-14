#include <iostream>
using namespace std;

struct Node
{
    char data;
    int next;
    bool flag=false;
};

int main()
{
    Node node[99999];
    int head1,head2,n;
    cin>>head1>>head2>>n;
    int p,p2;
    char c;
    for(int i=0;i<n;i++)
    {
        cin>>p>>c>>p2;
        node[p].data=c;
        node[p].next=p2;
    }
    for(int i=head1;i!=-1;i=node[i].next)
    {
        node[i].flag=true;
    }
    for(int i=head2;i!=-1;i=node[i].next)
    {
        if(node[i].flag==true)
        {
            cout<<i<<" "<<node[i].data<<endl;
            break;
        }
        cout<<-1<<endl;
        break;
    }
    return 0;
}