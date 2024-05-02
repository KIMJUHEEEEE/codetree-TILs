#include <iostream>
#include <algorithm>
using namespace std;

class info{
    public:
    int height;
    int weight;
    int number;
    info(){}
};

bool cmp(info a, info b)
{
    if(a.height==b.height)
    {
        return a.weight>b.weight;
    }
    return a.height<b.height;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    info student[n];
    for(int i=0;i<n;i++)
    {
        int h, w;
        cin>>h>>w;
        student[i].height=h;
        student[i].weight=w;
        student[i].number=i+1;
    }
    sort(student,student+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<student[i].height<<' '<<student[i].weight<<' '<<student[i].number<<endl;
    }
    return 0;
}