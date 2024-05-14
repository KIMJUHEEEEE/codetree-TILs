#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int arr[10001]={0,};
    int maxidx=0;
    for(int i=0;i<n;i++)
    {
        int a=0;
        char s;
        cin>>a>>s;
        if(a>maxidx) maxidx=a;
        if(s=='G') arr[a]=1;
        else if(s=='H') arr[a]=2;
    }
    int max=0;
    for(int i=0;i<=maxidx;i++)
    {
        int sum=0;
        for(int j=0;j<=k;j++)
        {
        sum+=arr[i+j];
        }
        if(max<sum) max=sum;
    }
    cout<<max;
    return 0;
}