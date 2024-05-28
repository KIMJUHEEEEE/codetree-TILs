#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int ans=9999999;
    for(int i=1;i<=1000;i++)
    {
        bool possible=true;
        int num=1;
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>i) {
                possible=false;
                break;
            }
        
        if(cnt+arr[j]>i)
        {
            cnt=0;
            num++;
        }
        cnt+=arr[j];
        }
    if(possible&&num<=m)
    {
        ans=min(ans,i);
    }
    }
    cout<<ans;
    return 0;
}