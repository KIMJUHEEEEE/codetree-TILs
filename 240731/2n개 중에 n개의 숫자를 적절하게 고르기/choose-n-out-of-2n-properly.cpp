#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;
int arr[21];
int sum;
vector<int> v;
int ans=INT_MAX;

void rec(int idx)
{
    if(idx==n)
    {
        int cnt=0;
        for(int i=0;i<v.size();i++)
        {
            cnt+=arr[v[i]];
        }
        ans=min(ans,abs(sum-2*cnt));
        return;
    }
    for(int i=0;i<2*n;i++)
    {
        if(v.size()>0)
        {
            if(v[v.size()-1]>=i) continue;
        }
        v.push_back(i);
        rec(idx+1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    rec(0);
    cout<<ans;
    return 0;
}