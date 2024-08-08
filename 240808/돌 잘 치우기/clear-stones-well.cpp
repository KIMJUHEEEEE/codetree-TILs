#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m,k;
int arr[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool visited[101][101];
vector<pair<int,int>> stone;
queue<pair<int,int>> q;
vector<pair<int,int>> choice;
bool ck[10];
int ans;
void dfs(int idx)
{
    if(idx==m)
    {
        for(int i=0;i<m;i++)
        {
            int a=choice[i].first;
            int b=choice[i].second;
            arr[a][b]=0;
        }
        while(q.size()>0)
        {
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            for(int j=0;j<4;j++)
            {
                if(y+dy[j]<0||x+dx[j]<0||y+dy[j]==n||x+dx[j]==n) continue;
                if(arr[y+dy[j]][x+dx[j]]==0&&visited[y+dy[j]][x+dx[j]]==0)
                {
                    q.push(make_pair(y+dy[j],x+dx[j]));
                    visited[y+dy[j]][x+dx[j]]=1;
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==1)
            {
                sum++;
            }
        }
        }
        ans=max(sum,ans);
        for(int i=0;i<m;i++)
        {
            int a=choice[i].first;
            int b=choice[i].second;
            arr[a][b]=1;
        }
        return;
    }
    for(int i=0;i<stone.size();i++)
    {
        if(ck[i]==0)
        {choice.push_back(stone[i]);
        ck[i]=1;
        dfs(idx+1);
        choice.pop_back();
        ck[i]=0;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>k>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)
            {
             stone.push_back(make_pair(i,j));   
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        int r,c;
        cin>>r>>c;
        q.push(make_pair(r-1,c-1));
        visited[r-1][c-1]=1;
        dfs(0);
    }
    cout<<ans;
    return 0;
}