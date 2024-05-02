#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

class info{
    public:
    string name;
    int height;
    int weight;
    info(){}
};

bool cmp(info a, info b)
{
    return a.height<b.height;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    info person[11];
    for(int i=0;i<n;i++)
    {
    string name;
    int height;
    int weight;
    cin>>name>>height>>weight;
    person[i].name=name;
    person[i].height=height;
    person[i].weight= weight;
    }
    sort(person,person+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<person[i].name<<' '<<person[i].height<<' '<<person[i].weight<<endl;
    }
    return 0;
}