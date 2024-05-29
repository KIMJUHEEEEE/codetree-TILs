#include <iostream>
using namespace std;

bool IsPossible(int arr[],int a,int n,int k)
{
    int available_indices[101] = {0,};
    int cnt = 0;

    for(int i = 0; i < n; i++)
        if(arr[i] >= a)
            available_indices[cnt++] = i;

    for(int i = 1; i < cnt; i++) {
        int dist = available_indices[i] - available_indices[i - 1];
        if(dist > k)
            return false;
    }

    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int arr[101]={0,};
    int cnt[101]={0,};
    int idx=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]++;
        if(idx<arr[i]) idx=arr[i];
    }
    int ans=0;
    for(int i=1;i<101;i++)
    {
        if(cnt[i]==0) continue;
        if(IsPossible(arr,i,n,k))
        {
            ans=max(ans,i);
        }
    }
    cout<<ans;
    return 0;
}