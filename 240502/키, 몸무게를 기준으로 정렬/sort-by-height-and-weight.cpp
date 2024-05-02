#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class person{
    public:
    string name;
    int height;
    int weight;
    person(){}
};

bool cmp(person a, person b)
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
    person info[n];
    for(int i=0;i<n;i++)
    {
    string name;
    int height;
    int weight;
    cin>>name>>height>>weight;
    info[i].name=name;
    info[i].height=height;
    info[i].weight=weight;
    }
    sort(info,info+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<info[i].name<<' '<<info[i].height<<' '<<info[i].weight<<endl;
    }
    return 0;
}