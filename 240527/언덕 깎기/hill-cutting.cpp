#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[1001]={0,};
    int min=9999;
    int max=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(min>arr[i]) min=arr[i];
        if(max<arr[i]) max=arr[i];
    }
    sort(arr,arr+n);
    int ans=99999;
    for(int i=min;i<=max-17;i++)
    {
        int sum=0;
        for(int k=0;k<n;k++)
        {
            if(arr[k]<i) sum+=(i-arr[k])*(i-arr[k]);
            if(arr[k]>i+17) sum+=(arr[k]-i-17)*(arr[k]-i-17);
        }

        if(ans>sum) ans=sum;
    }
    cout<<ans;
    return 0;
}