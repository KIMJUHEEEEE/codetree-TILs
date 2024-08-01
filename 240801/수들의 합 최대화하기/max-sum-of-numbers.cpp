#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[11][11];
vector<int> v;
int ans=0;

void rec(int idx)
{
    if(idx==n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i][v[i]];
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(v.size()>0)
        {   bool ck=0;
            for(int j=0;j<v.size();j++)
            {
                if(v[j]==i) ck=1;
                if(ck==1) break;
            }
            if(ck==1) continue;
        }
        v.push_back(i);
        rec(idx+1);
        v.pop_back();
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    rec(0);
    cout<<ans;
    return 0;
}