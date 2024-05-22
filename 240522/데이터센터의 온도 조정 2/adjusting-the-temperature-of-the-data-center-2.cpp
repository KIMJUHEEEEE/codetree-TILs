#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,c,g,h;
    cin>>n>>c>>g>>h;
    int arr[10001][2]={0,};
    int mint=1000;
    int maxt=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        if(mint>arr[i][0]) mint=arr[i][0];
        if(maxt<arr[i][1]) maxt=arr[i][1];
    }
    int ans=0;
    for(int i=mint;i<=maxt;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i<arr[j][0]) sum+=c;
            else if(arr[j][0]<=i&&arr[j][1]>=i) sum+=g;
            else sum+=h;
        }
        if(ans<sum) ans=sum;
    }
    cout<<ans;
    return 0;
}