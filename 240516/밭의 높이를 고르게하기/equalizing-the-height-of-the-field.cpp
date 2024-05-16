#include <iostream>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,h,t;
    cin>>n>>h>>t;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int min= INT_MAX;
    for(int i=0;i<=n-t;i++)
    {
        int sum=0;
        for(int j=0;j<t;j++)
        {
            sum+=abs(arr[i+j]-h);
        }
        if(min>sum) min=sum;
    }
    cout<<min;
    return 0;
}