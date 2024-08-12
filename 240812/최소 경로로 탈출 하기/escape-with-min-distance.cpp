#include <iostream>
#include <queue>
using namespace std;
int n,m;
int arr[101][101];
bool visited[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt[101][101];

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    q.push(make_pair(0,0));
    while(q.size()>0)
    {
        int y=q.front().first;
        int x=q.front().second;
        visited[y][x]=1;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(y+dy[i]<0||x+dx[i]<0||y+dy[i]==n||x+dx[i]==m) continue;
            if(visited[y+dy[i]][x+dx[i]]==0&&arr[y+dy[i]][x+dx[i]]==1)
            {
                q.push(make_pair(y+dy[i],x+dx[i]));
                cnt[y+dy[i]][x+dx[i]]=cnt[y][x]+1;
            }
        }

    }
    if(cnt[n-1][m-1]==0) cnt[n-1][m-1]=-1;
    cout<<cnt[n-1][m-1];
    return 0;
}