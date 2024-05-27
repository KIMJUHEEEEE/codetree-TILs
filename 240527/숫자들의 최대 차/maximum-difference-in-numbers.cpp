#include <iostream>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int cnt[10001]={0,};
    int max=0;
    int min=99999;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
        if(max<a) max=a;
        if(min>a) min=a;
    }
    int ans=0;
    if(max-k<min) {ans=n; cout<<ans; return 0;}
    for(int i=min;i<=max-k;i++)
    {
        int sum=0;
        for(int j=i;j<=i+k;j++)
        {
            sum+=cnt[j];
        }
        if(sum>ans) ans=sum;
    }
    cout<<ans;

    return 0;
}