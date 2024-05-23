#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101]={0,};
    int max=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>max) max=arr[i];
    }
    int ans=0;
    for(int i=1;i<max;i++)
    {
        int tmp[101]={0,};
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            tmp[j]=arr[j]-i;
            
        }
        for(int j=0;j<n;j++)
        {
            if(tmp[j]<=0) tmp[j]=0;
            if(tmp[j]>0&&tmp[j+1]==0) 
            {
                cnt++;
            }
        }
        if(ans<cnt) ans=cnt;
    }
    cout<<ans;
    return 0;
}