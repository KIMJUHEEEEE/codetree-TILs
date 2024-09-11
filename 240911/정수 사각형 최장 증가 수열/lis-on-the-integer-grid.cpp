#include <iostream>
#include <queue>
using namespace std;
int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int arr[501][501];
int m[501][501];

int bfs(int y,int x)
{
    bool visited[501][501]={0,};
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    visited[y][x]=1;
    m[y][x]=1;
    while(q.size()>0)
    {
        int yy=q.front().first;
        int xx=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(yy+dy[i]<0||xx+dx[i]<0||yy+dy[i]==n||xx+dx[i]==n) continue;
            if(arr[yy][xx]>=arr[yy+dy[i]][xx+dx[i]]) continue;
            if(arr[yy][xx]<arr[yy+dy[i]][xx+dx[i]]&&visited[yy+dy[i]][xx+dx[i]]==0)
            {
                q.push(make_pair(yy+dy[i],xx+dx[i]));
                visited[yy+dy[i]][xx+dx[i]]=1;
                m[yy+dy[i]][xx+dx[i]]=m[yy][xx]+1;
            }
        }
    }
    int num=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            num=max(num,m[i][j]);
        }
    }
    return num;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j]; 
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans=max(ans,bfs(i,j));
        }
    }
    cout<<ans;
    return 0;
}