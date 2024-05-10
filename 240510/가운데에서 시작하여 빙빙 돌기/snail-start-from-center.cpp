#include <iostream>
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};//동북서남
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[101][101]={0,};
    int n;
    cin>>n;
    int x=n/2;
    int y=n/2;
    int cnt=1;
    arr[x][y]=cnt;
    int dir=0;
    cnt++;
    int rot=1;
    while(cnt<=n*n)
    {
        if(x+dx[dir]==n||y+dy[dir]==n||x+dx[dir]<0||y+dy[dir]<0||arr[x+dx[dir]][y+dy[dir]]!=0)
        {
            dir=(dir+1)%4; 
        }
        for(int i=0;i<rot;i++)
        {
            x+=dx[dir];
            y+=dy[dir];
            arr[x][y]=cnt;
            cnt++;
        }
        dir=(dir+1)%4;
        if(dir==2||dir==0) rot++;
    }
    for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[i][j] << ' ';
    }
    cout << endl;
}
    return 0;
}