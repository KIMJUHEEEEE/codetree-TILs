#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;
int arr[11][11];
bool ck[11];
vector<int> v;
int ans=INT_MAX;

void rec(int idx)
{
    if(idx==n)
    {
        int sum=0;
        for(int i=0;i<v.size()-1;i++)
        {
            sum+=arr[v[i]][v[i+1]];
            if(arr[v[i]][v[i+1]]==0) return;
        }
        if(arr[v[v.size()-1]][v[0]]==0) return;
        sum+=arr[v[v.size()-1]][v[0]];
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(ck[i]!=0) continue;
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