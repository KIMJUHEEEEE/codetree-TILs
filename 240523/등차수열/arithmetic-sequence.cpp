#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101]={0,};
    int min=9999;
    int max=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<min) min=arr[i];
        if(arr[i]>max) max=arr[i];
    }
    int ans=0;
    
    for(int kk=min;kk<max;kk++)
    {
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(kk-arr[i]==arr[j]-kk) 
                {
                    cnt++;
                }
            }
        }
        if(ans<cnt) ans=cnt;
    }
    cout<<ans;
    return 0;
}