#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,k;
int arr[101][101];
int ans[101][101];
vector<pair<int,int>> v;

void bfs()
{
    queue<pair<int,int>> q;
    for(int i=0;i<v.size();i++)
    {  
        q.push(make_pair(v[i].first,v[i].second));
    }
    while(q.size()>0)
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(y+dy[i]<0||x+dx[i]<0||y+dy[i]==n||x+dx[i]==n) continue;
            if(arr[y+dy[i]][x+dx[i]]==1&&ans[y+dy[i]][x+dx[i]]==0)
            {
                ans[y+dy[i]][x+dx[i]]=ans[y][x]+1;
                q.push(make_pair(y+dy[i],x+dx[i]));
            }
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0)
            {
                ans[i][j]=-1;
            }
            if(arr[i][j]==2)
            {
                v.push_back(make_pair(i,j));
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1&&ans[i][j]==0) ans[i][j]=-2;
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}