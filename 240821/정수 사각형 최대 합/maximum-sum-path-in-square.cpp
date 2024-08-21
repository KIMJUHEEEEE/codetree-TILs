#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101][101]={0,};
    int sum[101][101]={0,};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            sum[i][j]=arr[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]=max(sum[i][j],arr[i][j]+sum[i-1][j]);
            sum[i][j]=max(sum[i][j],arr[i][j]+sum[i][j-1]);
        }
    }
    cout<<sum[n][n];
    return 0;
}