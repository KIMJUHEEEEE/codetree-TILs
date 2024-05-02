#include <iostream>
#include <algorithm>
using namespace std;

class student{
    public:
    int height;
    int weight;
    int number;
    student(){}
};

bool cmp(student a, student b)
{
    if(a.height==b.height)
    {
        if(a.weight==b.weight) return a.number<b.number;
        return a.weight>b.weight;
    }
    return a.height>b.height;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    student info[n];
    for(int i=0;i<n;i++)
    {
        int h;
        int w;
        cin>>h>>w;
        info[i].height=h;
        info[i].weight=w;
        info[i].number=i+1;
    }
    sort(info,info+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<info[i].height<<' '<<info[i].weight<<' '<<info[i].number<<endl;
    }
    return 0;
}