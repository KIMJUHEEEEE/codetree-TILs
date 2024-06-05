#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    while(1)
    {
        int cnt=0;
        for(int i=0;i<n-1;i++)
    {
        if(arr[i]<=arr[i+1]) cnt++;
        else
        {
            int tmp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=tmp;
        }
    }
    if(cnt==n-1) break;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}