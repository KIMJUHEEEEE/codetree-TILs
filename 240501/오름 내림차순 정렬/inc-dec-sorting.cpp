#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[101]={0,};
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}