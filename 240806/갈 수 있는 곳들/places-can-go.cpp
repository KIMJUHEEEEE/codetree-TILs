#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int arr[101][101]={0,};
    bool visited[101][101]={0,};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    queue<pair<int,int>> q;
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>y>>x;
        q.push(make_pair(y-1,x-1));
        visited[y-1][x-1]=1;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(q.size()>0)
        {
            int qy=q.front().first;
            int qx=q.front().second;
            q.pop();
            for(int j=0;j<4;j++)
            {
                if(qy+dy[j]<0||qx+dx[j]<0||qy+dy[j]==n||qx+dx[j]==n) continue;
                if(arr[qy+dy[j]][qx+dx[j]]==0&&visited[qy+dy[j]][qx+dx[j]]==0)
                {
                    q.push(make_pair(qy+dy[j],qx+dx[j]));
                    visited[qy+dy[j]][qx+dx[j]]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==1)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}