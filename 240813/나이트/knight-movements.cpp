#include <iostream>
#include <queue>
using namespace std;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
int arr[101][101];
bool visited[101][101];

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    visited[r1-1][c1-1]=1;
    queue<pair<int,int>> q;
    q.push(make_pair(r1-1,c1-1));
    while(q.size()>0)
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            if(y+dy[i]<0||x+dx[i]<0||y+dy[i]>=n||x+dx[i]>=n) continue;
            if(visited[y+dy[i]][x+dx[i]]==0)
            {
                visited[y+dy[i]][x+dx[i]]=1;
                q.push(make_pair(y+dy[i],x+dx[i]));
                if(arr[y+dy[i]][x+dx[i]]==0)
                {arr[y+dy[i]][x+dx[i]]=arr[y][x]+1;}
            }
        }
    }
    if(arr[r2-1][c2-1]==0) cout<<-1;
    else cout<<arr[r2-1][c2-1];
    return 0;
}