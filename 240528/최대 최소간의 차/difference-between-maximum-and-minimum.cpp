#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    while(1)
    {
        sort(arr,arr+n);
        int mini=arr[0];
        int maxi=arr[n-1];
        if(maxi-mini<=k)
        {
            break;
        }
        else
        {
            arr[0]+=1;
            ans++;
            sort(arr,arr+n);
            if(maxi-arr[0]<=k) break;
            else
            {
                arr[n-1]-=1;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}