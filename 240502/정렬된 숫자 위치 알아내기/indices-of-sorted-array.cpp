#include <iostream>
#include <algorithm>
using namespace std;

class number{
    public:
    int idx;
    int num;
    int move;
    number(){}
};

bool cmp(number a, number b)
{
    if(a.num==b.num) return a.idx<b.idx;
    return a.num<b.num;
}
bool cmp2(number a, number b)
{
    return a.idx<b.idx;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    number nb[n];
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        nb[i].num=a;
        nb[i].idx=i+1;
    }
    sort(nb,nb+n,cmp);
    for(int i=0;i<n;i++)
    {
        nb[i].move=i+1;
    }
    sort(nb,nb+n,cmp2);
    for(int i=0;i<n;i++)
    {
        cout<<nb[i].move<<' ';
            }
    return 0;
}