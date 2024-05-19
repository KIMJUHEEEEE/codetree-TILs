#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    int arr[11]={0,};
    int a[11]={0,};
    int b[11]={0,};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i]>>a[i]>>b[i];
    }
    int ans=0;

    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=1;k<10;k++ )
            {
                if(i==j||j==k||i==k) continue;
                int cnt=0;
                //cout<<i<<j<<k<<endl;
                for(int l=0;l<n;l++)
                {
                    int cnt1=0;
                    int cnt2=0;
                    //cout<<arr[l]<<' ';
                    if(i==arr[l]/100) cnt1++;
                    if(j==(arr[l]%100)/10) cnt1++;
                    if(k==arr[l]%10) cnt1++;
                    if(arr[l]/100==j||arr[l]/100==k) cnt2++;
                    if((arr[l]%100)/10==i||(arr[l]%100)/10==k) cnt2++;
                    if(arr[l]%10==i||arr[l]%10==j) cnt2++;
                    //cout<<cnt1<<' '<<cnt2<<endl;
                    if(cnt1==a[l]&&cnt2==b[l]) 
                    {
                        //cout<<i<<j<<k<<endl;
                        //cout<<arr[l]<<' ';
                        //cout<<cnt1<<' '<<cnt2<<endl;
                        cnt++;
                    }
                }
                if(cnt==n) {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}