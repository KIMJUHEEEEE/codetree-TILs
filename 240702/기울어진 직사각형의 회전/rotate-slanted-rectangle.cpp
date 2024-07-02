#include <iostream>
using namespace std;

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
    int r,c,m1,m2,m3,m4,dir;
    cin>>r>>c>>m1>>m2>>m3>>m4>>dir;
    int x=c-1;
    int y=r-1;
    if(dir==0)
    {
        int tmp=arr[y][x];
        for(int a=0;a<m4;a++)
        {
            arr[y][x]=arr[y-1][x-1];
            y=y-1;
            x=x-1;
        }
        for(int a=0;a<m3;a++)
        {
            arr[y][x]=arr[y-1][x+1];
            y=y-1;
            x=x+1;
        }
        for(int a=0;a<m2;a++)
        {
            arr[y][x]=arr[y+1][x+1];
            y=y+1;
            x=x+1;
        }
        for(int a=0;a<m1;a++)
        {
            arr[y][x]=arr[y+1][x-1];
            y=y+1;
            x=x-1;
        }
        arr[r-2][c]=tmp;
    }
    else
    {
        int tmp=arr[y][x];
        for(int a=0;a<m1;a++)
        {
            arr[y][x]=arr[y-1][x+1];
            y=y-1;
            x=x+1;
        }
        for(int a=0;a<m2;a++)
        {
            arr[y][x]=arr[y-1][x-1];
            y=y-1;
            x=x-1;
        }
        for(int a=0;a<m3;a++)
        {
            arr[y][x]=arr[y+1][x-1];
            y=y+1;
            x=x-1;
        }
        for(int a=0;a<m4;a++)
        {
            arr[y][x]=arr[y+1][x+1];
            y=y+1;
            x=x+1;
        }
        arr[r-2][c-2]=tmp;

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