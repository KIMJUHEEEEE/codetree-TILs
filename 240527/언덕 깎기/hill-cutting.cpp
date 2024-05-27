#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[1001]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int cnt=1;
    int ans=0;
    while(1)
    {
        arr[0]=arr[0]+1;
        sort(arr,arr+n);
        ans=cnt*cnt;
        if(arr[n-1]-arr[0]<=17) {
            
            break;
        }
        arr[n-1]=arr[n-1]-1;
        sort(arr,arr+n);
        if(arr[n-1]-arr[0]<=17)
            {
                ans+=cnt*cnt;
                break;
            }
        cnt++;
    }
    cout<<ans;
    return 0;
}