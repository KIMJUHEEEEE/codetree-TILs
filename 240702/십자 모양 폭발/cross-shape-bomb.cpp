#include <iostream>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int arr[211][211]={0,};
int n;
void down()
{
    for(int j=1;j<=n;j++)
    {
        for(int i=n;i>=1;i--)
        {
            if(arr[i][j]==0&&arr[i-1][j]!=0)
            {
                arr[i][j]=arr[i-1][j];
                arr[i-1][j]=0;
                i=n+1;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int r,c;
    cin>>r>>c;
    if(r>n||c>n)
    {
        cout<<0;
        return 0;
    }
    int num=arr[r][c];
    //cout<<num<<endl;
    arr[r][c]=0;

    for(int i=0;i<4;i++)
    {
        int x=c;
        int y=r;
        for(int a=0;a<num-1;a++)
        {
            arr[y+dy[i]][x+dx[i]]=0;
            y+=dy[i];
            x+=dx[i];
            if(y<1||y>n||x<1||x>n) break;
        }
    }

    down();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}