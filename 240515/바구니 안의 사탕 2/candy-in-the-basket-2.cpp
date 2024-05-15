#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int arr[101]={0,};
    int maxidx=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[b]+=a;
        if(maxidx<b) maxidx=b;
    }
    int max=0;
    for(int i=k;i<=maxidx;i++)
    {
        int sum=0;
        for(int j=-k;j<=k;j++)
        {
            sum+=arr[i+j];
        }
        if(max<sum) max=sum;
    } 
    cout<<max;
    return 0;
}