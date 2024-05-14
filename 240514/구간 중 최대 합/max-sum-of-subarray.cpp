#include <iostream>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=0;
    for(int i=0;i<n-k;i++)
    {
        int sum=0;
        for(int j=0;j<k;j++)
        {
            sum+=arr[i+j];
        }
        if(sum>max) max=sum;
    }
    cout<<max;
    return 0;
}