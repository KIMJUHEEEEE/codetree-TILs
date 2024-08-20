#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    long long arr[1001]={0,};
    arr[0]=1;
    arr[1]=2;
    for(int i=2;i<=n;i++)
    {
        arr[i]=(2*arr[i-1]+3*arr[i-2])%1000000007;
        for(int j=i-3;j>=0;j--)
        {
            arr[i]=(arr[i]+2*arr[j])%1000000007;
        }
    }
    cout<<arr[n];
    return 0;
}