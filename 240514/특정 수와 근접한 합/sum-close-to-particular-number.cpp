#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,s;
    cin>>n>>s;
    int arr[101]={0,};
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int min=9999999;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int a=sum-arr[i]-arr[j];
            if(abs(a-s)<min) min=abs(a-s);
        }
    }
    cout<<min;
    return 0;
}