#include <iostream>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};//동남서북

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[101][101]={0,};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
                int cnt=0;
            for(int k=0;k<4;k++)
            {
                if(i+dx[k]>=0&&j+dy[k]>=0&&i+dx[k]<n&&j+dy[k]<n)
                {
                    if(arr[i+dx[k]][j+dy[k]]==1) cnt++;
                }
            }
            if(cnt>=3) ans++;
        }
    }
    cout<<ans;
    return 0;
}