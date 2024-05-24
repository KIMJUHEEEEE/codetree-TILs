#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        int tmp=i;
        for(int j=0;j<3;j++)
        {
         sum+=arr[tmp];
         tmp=arr[tmp]-1;   
        }
        if(max<sum) max=sum;
    }
    cout<<max;
    return 0;
}