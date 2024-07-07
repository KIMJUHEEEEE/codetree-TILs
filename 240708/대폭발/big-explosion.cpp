#include <iostream>
#include <math.h>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int r,c;
    cin>>r>>c;
    int arr[101][101]={0,};
    int y=r-1;
    int x=c-1;
    arr[y][x]=1;
    for(int a=0;a<m;a++)
    {
        int cparr[101][101]={0,};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==1)
                {
                    for(int dir=0;dir<4;dir++)
                    {
                        x=j;
                        y=i;
                        y+=pow(2,a)*dy[dir];
                        x+=pow(2,a)*dx[dir];
                        if(x<0||y<0||x>=n||y>=n)
                        {
                            continue;
                        }
                        cparr[y][x]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cparr[i][j]==1)
                {
                    arr[i][j]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1) ans++;
        }
    }
    cout<<ans;
    return 0;
}