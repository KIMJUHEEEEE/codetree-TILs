#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int sum=0;
    int arr[6]={0,};
    for(int i=0;i<6;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int min=INT_MAX;
    sort(arr,arr+6);
    int max=0;
    for(int i=0;i<3;i++)
    {
        if(arr[i]+arr[6-i-1]>max) max=arr[i]+arr[5-i];
        if(arr[i]+arr[5-i]<min) min=arr[i]+arr[5-i];
    }
    cout<<max-min;
    return 0;
}