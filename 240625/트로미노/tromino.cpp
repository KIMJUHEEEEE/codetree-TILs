#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arr[201][201]={0,};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    //니은
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            int sum=0;
            for(int a=0;a<2;a++)
            {
                for(int b=0;b<2;b++)
                {
                    sum+=arr[i+a][j+b];
                }
            }
            ans=max(ans,sum-arr[i][j]);
            ans=max(ans,sum-arr[i+1][j]);
            ans=max(ans,sum-arr[i][j+1]);
            ans=max(ans,sum-arr[i+1][j+1]);
        }
    }
    //작대기 가로
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            int sum=0;
            for(int a=0;a<3;a++)
            {
                sum+=arr[i][j+a];
            }
            ans=max(ans,sum);
        }
    }
    //작대기 세로
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n-2;i++)
        {
            int sum=0;
            for(int a=0;a<3;a++)
            {
                sum+=arr[i+a][j];
            }
            ans=max(ans,sum);
        }
    }
    cout<<ans;
    return 0;
}