#include <iostream>
#include <algorithm>
using namespace std;

class spot{
    public:
    int idx;
    int x;
    int y;
    spot(){}
};

bool cmp(spot a, spot b)
{
    if(a.x+a.y==b.x+b.y)
    {
        return a.idx<b.idx;
    }
    return a.x+a.y<b.x+b.y;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    spot num[n];
    for(int i=0;i<n;i++)
    {
        int x;
        int y;
        cin>>x>>y;
        if(x<0) x*=(-1);
        if(y<0) y*=(-1);
        num[i].idx=i+1;
        num[i].x=x;
        num[i].y=y;
    }
    sort(num,num+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<num[i].idx<<endl;
    }
    return 0;
}