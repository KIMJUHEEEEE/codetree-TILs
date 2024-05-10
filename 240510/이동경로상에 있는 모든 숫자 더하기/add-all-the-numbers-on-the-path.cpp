#include <iostream>
#include <string>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};//동남서북

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[101][101]={0,};
    int n,t;
    cin>>n>>t;
    string str;
    cin>>str;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int x=n/2;
    int y=n/2;
    int ans=arr[x][y];
    int dir=3;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='R')
        {
            dir=(dir+1)%4;
        }
        else if(str[i]=='L')
        {
            dir=(dir+3)%4;
        }
        else
        {
            if(x+dx[dir]<0||x+dx[dir]>=n||y+dy[dir]<0||y+dy[dir]>=n) continue;
            x+=dx[dir];
            y+=dy[dir];
            ans+=arr[x][y];
        }
    }
    cout<<ans;
    return 0;
}