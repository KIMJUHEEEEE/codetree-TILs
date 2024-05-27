#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int arr[101]={0,};
    int cnt[1000001]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=0;
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<=i+k;j++)
        {
            if(arr[i]==arr[j])
            {
                if(cnt[arr[i]]==0)
                {
                    cnt[arr[i]]+=2;
                }
                else
                {
                    cnt[arr[i]]++;
                }
                if(max==cnt[arr[i]]){
                    if(ans<arr[i]) ans=arr[i];
                }
                else if(max<cnt[arr[i]]) {max=cnt[arr[i]]; ans=arr[i];}
            }
        }
    }
    cout<<ans;
    return 0;
}