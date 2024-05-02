#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class student{
    public:
    string name;
    int ko;
    int eng;
    int mat;
    student(){}
};

bool cmp(student a, student b)
{
    return a.ko+a.eng+a.mat<b.ko+b.eng+b.mat;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    student info[n];
    for(int i=0;i<n;i++)
    {
    string name;
    int ko;
    int eng;
    int mat;
    cin>>name>>ko>>mat>>eng;
    info[i].name=name;
    info[i].ko=ko;
    info[i].eng=eng;
    info[i].mat=mat;
    }
    sort(info,info+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<info[i].name<<' '<<info[i].ko<<' '<<info[i].mat<<' '<<info[i].eng<<endl;
    }
    return 0;
}