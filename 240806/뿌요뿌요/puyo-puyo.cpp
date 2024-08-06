#include <iostream>
using namespace std;
int n;
int arr[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool visited[101][101];
int maxnum=0;
int cnt=0;

bool possible(int x, int y)
{
    for(int i=0;i<4;i++)
    {
        if(x+dx[i]<0||y+dy[i]<0||x+dx[i]==n||y+dy[i]==n) continue;
        if(arr[y+dy[i]][x+dx[i]]==arr[y][x]&&visited[y+dy[i]][x+dx[i]]==0) return true;
    }
    return false;
}

void dfs(int x, int y)
{
    if(possible(x,y)==false)
    {
        maxnum=max(maxnum,cnt);
        return;
    }
    for(int i=0;i<4;i++)
    {
        if(arr[y][x]==arr[y+dy[i]][x+dx[i]]&&visited[y+dy[i]][x+dx[i]]==0)
        {
            visited[y+dy[i]][x+dx[i]]=1;
            cnt++;
            dfs(x+dx[i],y+dy[i]);
        }
    }
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
    int num=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==0)
            {
                cnt=1;
                visited[i][j]=1;
                dfs(j,i);
                if(cnt>=4) num++;
            }
        }
    }
    cout<<num<<' '<<maxnum;
    return 0;
}