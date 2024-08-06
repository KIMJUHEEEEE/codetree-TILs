#include <iostream>
#include <queue>
using namespace std;
int n,m;
int arr[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool visited[101][101];
int ans=0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0]=1;
    while(q.size()>0)
    {
        int x=q.front().first;
        int y=q.front().second;
        if(x==m-1&&y==n-1) ans=1;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]<0||y+dy[i]<0||x+dx[i]==m||y+dy[i]==n) continue;
            if(arr[y+dy[i]][x+dx[i]]==1&&visited[y+dy[i]][x+dx[i]]==0) 
            {q.push(make_pair(x+dx[i],y+dy[i])); visited[y+dy[i]][x+dx[i]]=1;}
        }
    }
    cout<<ans;
    return 0;
}