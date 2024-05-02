#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class person{
    public:
    string name;
    int height;
    float weight;
    person(){}
};

bool cmp1(person a, person b)
{
    return a.name<b.name;
}

bool cmp2(person a, person b)
{
    return a.height>b.height;
}

int main() {
    // 여기에 코드를 작성해주세요.
    person info[5];
    for(int i=0;i<5;i++)
    {
    string name;
    int height;
    float weight;
    cin>>name>>height>>weight;
    info[i].name=name;
    info[i].height=height;
    info[i].weight=weight;
    }
    sort(info,info+5,cmp1);
    cout<<"name"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<info[i].name<<' '<<info[i].height<<' '<<info[i].weight<<endl;
    }
    
    sort(info,info+5,cmp2);
    cout<<endl<<"height"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<info[i].name<<' '<<info[i].height<<' '<<info[i].weight<<endl;
    }
    return 0;
}