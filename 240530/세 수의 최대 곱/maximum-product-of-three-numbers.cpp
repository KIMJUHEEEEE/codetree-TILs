#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[100001]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long maxi=arr[0]*arr[1]*arr[2];
    if(n==3)
    {
        cout<<maxi;
        return 0;
    }
    if(arr[n-1]>0&&arr[n-2]>0&&arr[n-3]>0)
    {
        long long multi=arr[n-1]*arr[n-2]*arr[n-3];
        maxi=max(maxi,multi);
    }
    if(arr[0]<0&&arr[1]<0&&arr[n-1]>0)
    {
        long long multi=arr[0]*arr[1]*arr[n-1];
        maxi=max(maxi,multi);
    }
    cout<<maxi;
    return 0;
}