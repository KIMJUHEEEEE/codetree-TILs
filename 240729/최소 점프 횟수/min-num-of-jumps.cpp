#include <iostream>
using namespace std;
int n;
int arr[11];
int jump;
int ans=99;

void rec(int idx, int cnt)
{
    if(idx>=n) return;
    if(idx==n-1)
    {
        ans=min(ans,cnt);
        return;
    }
    int num=arr[idx];
    for(int i=1;i<=num;i++)
    {
        rec(idx+i,cnt+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    rec(0,0);
    if(ans==99) ans=-1;
    cout<<ans;
    return 0;
}