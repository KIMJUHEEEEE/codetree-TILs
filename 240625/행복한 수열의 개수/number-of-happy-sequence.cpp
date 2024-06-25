#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arr[101][101]={0,};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n-1;j++)
        {
            if(arr[i][j]==arr[i][j+1]) 
            {
                cnt++;
                if(cnt==m-1)
                {
                    ans++;
                    cnt=0;
                    break;
                }
            }
            else cnt=0;
            
        }
    }
    for(int j=0;j<n;j++)
    {
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i][j]==arr[i+1][j]) 
            {
                cnt++;
                if(cnt==m-1)
                {
                    ans++;
                    cnt=0;
                    break;
                }
            }
            else cnt=0;
        }
    }
    cout<<ans;
    return 0;
}