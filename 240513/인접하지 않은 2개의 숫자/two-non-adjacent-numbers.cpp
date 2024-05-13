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
    int max=0;
    int sum=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+2;j<n;j++)
        {
            sum=arr[i];
            sum+=arr[j];
            if(sum>max) max=sum;
        }
    }
    cout<<max;
    return 0;
}