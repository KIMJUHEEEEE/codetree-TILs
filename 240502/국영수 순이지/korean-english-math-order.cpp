#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class person{
    public:
    string name;
    int eng;
    int mat;
    int ko;
    person(){}
};

bool cmp(person a, person b)
{
    if(a.ko==b.ko)
    {
        if(a.eng==b.eng)
        {
            return a.mat>b.mat;
        }
        return a.eng>b.eng;
    }
    return a.ko>b.ko;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    person info[n];
    for(int i=0;i<n;i++)
    {
    string name;
    int eng;
    int mat;
    int ko; 
    cin>>name>>ko>>eng>>mat;  
    info[i].name=name;
    info[i].ko=ko;
    info[i].eng=eng;
    info[i].mat=mat;  
    }
    sort(info, info+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<info[i].name<<' '<<info[i].ko<<' '<<info[i].eng<<' '<<info[i].mat<<endl;
    }
    return 0;
}