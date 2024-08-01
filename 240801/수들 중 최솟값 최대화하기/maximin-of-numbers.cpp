#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;
int arr[11][11];
bool ck[11];
vector<int> v;
int ans=0;

void rec(int idx)
{
    if(idx==n)
    {
        int sum=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            sum=min(sum,arr[i][v[i]]);
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(ck[i]==1) continue;
        v.push_back(i);
        ck[i]=1;
        rec(idx+1);
        v.pop_back();
        ck[i]=0;
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