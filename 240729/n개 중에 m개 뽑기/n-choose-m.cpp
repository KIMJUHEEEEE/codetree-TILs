#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
void rec(int num, int idx)
{
    if(idx==m)
    {
        for(int i=0;i<idx;i++)
        {
            cout<<v[i]<<' ';
        }cout<<endl;
        return;
    }
    for(int i=num+1;i<=n;i++)
    {
        v.push_back(i);
        rec(i,idx+1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    rec(0,0);
    return 0;
}