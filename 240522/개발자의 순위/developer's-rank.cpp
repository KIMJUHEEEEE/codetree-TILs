#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int k,n;
    int arr[11][21]={0,};
    int price[11][21]={0,};
    cin>>k>>n;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            price[i][arr[i][j]]=j;
        }
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int cnt=0;
            for(int l=0;l<k;l++)
            {
                if(price[l][i]<price[l][j]) cnt++;
            }
            if(cnt==k) ans++;
        }
    }
    if(k==1) ans=n*(n-1)/2;
    cout<<ans;
    return 0;
}