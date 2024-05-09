#include <iostream>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};//동남서북
int arr[101][101];

int main() {
    // 여기에 코드를 작성해주세요.

    int n,m;
    cin>>n>>m;
    int x=0;
    int y=0;
    int cnt=1;
    int dir=0;
    while(1)
    {

        arr[x][y]=cnt;
        if(cnt==n*m) break;
        if((x+dx[dir])<0||(y+dy[dir])<0||(x+dx[dir])==n||(y+dy[dir])==n||arr[x+dx[dir]][y+dy[dir]]!=0)
        {
            dir=(dir+1)%4;
            x+=dx[dir];
            y+=dy[dir];
            cnt++;
        }
        else
        {
            x+=dx[dir];
            y+=dy[dir];
            cnt++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}