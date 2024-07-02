#include <iostream>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int arr[201][201]={0,};
int n;
void down()
{
    for(int j=1;j<=n;j++)
    {
        for(int i=n;i>0;i--)
        {
            if(arr[i][j]==0&&arr[i-1][j]!=0)
            {
                arr[i][j]=arr[i-1][j];
                arr[i-1][j]=0;
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
    arr[r][c]=0;

    for(int i=0;i<4;i++)
    {
        int x=c;
        int y=r;
        for(int a=0;a<num-1;a++)
        {
            if(y+dy[i]<1||y+dy[i]>n||x+dx[i]<1||x+dx[i]>n) break;
            arr[y+dy[i]][x+dx[i]]=0;
            y+=dy[i];
            x+=dx[i];
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