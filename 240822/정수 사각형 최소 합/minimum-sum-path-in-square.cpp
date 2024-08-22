#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101][101]={0,};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int sum[101][101]={0,};
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=1;j--)
        {
            if(sum[i][j]==0)
            {
                if(j==n)
                {
                    sum[i][j]=arr[i][j]+sum[i-1][j];
                }
                else if(i==1)
                {
                    sum[i][j]=arr[i][j]+sum[i][j+1];
                }
                else
                {
                    sum[i][j]=min(arr[i][j]+sum[i-1][j],arr[i][j]+sum[i][j+1]);
                }
            }
        }
    }
    cout<<sum[n][1];
    return 0;
}