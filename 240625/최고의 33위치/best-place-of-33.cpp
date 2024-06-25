#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[21][21]={0,};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<n-2;j++)
        {
            int ans=0;
            for(int x=0;x<3;x++)
            {
                for(int y=0;y<3;y++)
                {
                    if(arr[i+x][y+j]==1)
                    {
                        ans++;
                    }
                }
            }
            cnt=max(cnt,ans);
        }
    }
    cout<<cnt;
    return 0;
}