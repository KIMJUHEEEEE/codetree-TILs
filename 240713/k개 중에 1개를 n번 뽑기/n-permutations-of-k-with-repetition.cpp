#include <iostream>
#include <vector>
using namespace std;
int k,n;
vector<int> v;

void rec(int idx)
{
    if(idx==n)  
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<' ';
        }cout<<endl;
        return;
    } 
    for(int i=1;i<=k;i++)
    {
        v.push_back(i);
        rec(idx+1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>k>>n;
    rec(0);
    return 0;
}