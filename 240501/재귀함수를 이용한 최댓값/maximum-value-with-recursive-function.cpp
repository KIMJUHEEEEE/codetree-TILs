#include <iostream>
using namespace std;

int mmax(int arr[],int i, int n, int max)
{
    if(i==n) return 0;
    max=arr[i];
    int ma=mmax(arr,i+1,n,max);
    if(max<ma)
    {
        max=ma;
    }
    return max;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<mmax(arr,0,n,0);
    return 0;
}