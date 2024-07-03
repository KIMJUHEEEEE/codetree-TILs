#include <iostream>
using namespace std;
int n;
int arr[201][201];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void movedown()
{
    for(int j=0;j<n;j++)
    {
        for(int i=n-1;i>0;i--)
        {
            if(arr[i][j]==0)
            {
                arr[i][j]=arr[i-1][j];
                arr[i-1][j]=0;
            }
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.]
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int k=0;k<m;k++)
    {int c=0;
    cin>>c;
    c=c-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i][c]!=0)
        {
            int num=arr[i][c];
            arr[i][c]=0;
            for(int a=0;a<4;a++)
            {
                int x=c;
                int y=i;
                for(int b=0;b<num-1;b++)
                {
                    if(x+dx[a]<0||x+dx[a]>=n||y+dy[a]<0||y+dy[a]>=n) break;
                    arr[y+dy[a]][x+dx[a]]=0;
                    x+=dx[a];
                    y+=dy[a];
                }
            }
        }
        movedown();
    }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}