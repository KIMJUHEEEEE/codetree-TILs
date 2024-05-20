#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,b;
    int arr[1001]={0,};
    cin>>n>>b;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int max=0;
    for(int i=0;i<n;i++)
    {
        int sum=arr[i]/2;
        int cnt=0;
        if(sum<=b) cnt++;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            sum+=arr[j];
            if(sum<=b) cnt++;
        }
        if(cnt>max) max=cnt;
    }
    cout<<max;
    return 0;
}