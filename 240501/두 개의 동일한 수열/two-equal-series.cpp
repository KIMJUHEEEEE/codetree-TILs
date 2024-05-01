#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    int arr[101]={0,};
    int brr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    sort(arr,arr+n);
    sort(brr,brr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=brr[i])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}