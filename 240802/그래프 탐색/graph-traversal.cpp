#include <iostream>
using namespace std;
int n, m;
int arr[1001][1001];
bool visited[1001][1001];
int ans = 0;
bool ck[1001];
bool check(int idx)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[idx][i] == 0 && arr[idx][i] == 1&&ck[i]==0)
        {
            if (i == 0) continue;
            return true;
        }
    }
    return false;
}

void dfs(int idx, int cnt)
{
    if (check(idx) == false)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[idx][i] == 1 && visited[idx][i] == 0&&ck[i]==0)
        {
            visited[idx][i] = 1;
            visited[i][idx]=1;
            ck[i] = 1;
            dfs(i, cnt + 1);
            visited[idx][i] = 0;
            visited[i][idx]=0;
        }
    }
   
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a - 1][b - 1] = 1;
        arr[b - 1][a - 1] = 1;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]==1)    
        {
            visited[i][0]=1;
            visited[0][i]=1;
            dfs(i, 1);
            visited[i][0]=0;
            visited[0][i]=0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (ck[i] == 1) ans++;
    }
    cout << ans;
    return 0;
}