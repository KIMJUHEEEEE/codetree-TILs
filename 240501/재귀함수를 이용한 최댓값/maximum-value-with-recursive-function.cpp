#include <iostream>
using namespace std;

int mmax(int arr[],int i, int n, int max)
{
    if(i==n) return 0;
    max=arr[i];
    if(max<mmax(arr,i+1,n,max))
    {
        max=mmax(arr,i+1,n,max);
    }
    return max;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    int arr[n]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<mmax(arr,0,n,0);
    return 0;
}