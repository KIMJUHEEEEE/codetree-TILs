#include <iostream>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main() {
    // 여기에 코드를 작성해주세요.
    int n,r,c;
    cin>>n>>r>>c;
    int arr[101][101]={0,};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int x=c-1;
    int y=r-1;
    cout<<arr[y][x]<<' ';
    while(1)
    {
        int max=arr[y][x];
        int dir=-1;
        for(int a=0;a<4;a++)
        {  
            if(max<arr[y+dy[a]][x+dx[a]])
            {
                max=arr[y+dy[a]][x+dx[a]];
                dir=a;
                y+=dy[a];
                x+=dx[a];
                cout<<max<<' ';
            }
            
        }
        if(dir==-1) break;
    }

    return 0;
}