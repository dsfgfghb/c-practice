#include <iostream>
#include <algorithm>
using namespace std;

struct stud
{
    int score;
    long long id;
    int kaochang_num;
    int kaochang_level;
};

bool cmp(stud a, stud b)
{
    if (a.score != b.score)
    {
        return a.score > b.score;
    }
    else
    {
        return a.id < b.id;
    }
}

int main()
{
    int n,num=0;
    cin >> n;
    stud stu[1000];
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        long long m;
        cin >> m;
        sum+=m;
        for (int j = 0; j < m; j++)
        {
            cin>>stu[num].id;
            cin >> stu[num].score;
            stu[num].kaochang_num=i+1;
            num++;
        }
        
        sort(stu+num-m, stu+num, cmp);
        int k = 1,temp=0;
        for (int j = num-m; j < num; j++)
        {

            if (temp&&stu[j].score == stu[j-1].score)
            {
                stu[j].kaochang_level=stu[j-1].kaochang_level;
            }
            else
            {
                stu[j].kaochang_level=k;
            }
            k++;
        }
        
    }
    sort(stu, stu+sum,cmp);
    int k=1,temp=0;
    for (int i = 0; i < sum; i++)
    {
        if (temp&&stu[i].score!=stu[i+1].score)
        {
            k+=temp;
            temp=0;
        }
        cout<<stu[i].id<<' '<< k<<' '<<stu[i].kaochang_num<<' '<<stu[i].kaochang_level<<endl;
        k++;
        if (stu[i].score == stu[i+1].score)
        {
           k--;
           temp++;
        }
        
    }
    
    return 0;
}                     