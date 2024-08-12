#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int arr[10][10];
int k, u, d;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> v;
bool visited[10][10];

int ans;
queue<pair<int, int>> q;
int count()
{
    bool bfs_visited[10][10]={0,};
    int sum = 0;
    while (q.size() > 0)
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        bfs_visited[y][x] = 1;
        for (int i = 0; i < 4; i++)
        {
            if (y + dy[i] < 0 || x + dx[i] < 0 || y + dy[i] == n || x + dx[i] == n) continue;
            if (abs(arr[y][x] - arr[y + dy[i]][x + dx[i]]) <= d && abs(arr[y][x] - arr[y + dy[i]][x + dx[i]]) >= u)
            {
                if (bfs_visited[y + dy[i]][x + dx[i]] == 0)
                {
                    q.push(make_pair(y + dy[i], x + dx[i]));
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bfs_visited[i][j] == 1)
            {
                sum++;
            }
        }
    }
    return sum;
}

void dfs(int idx)
{
    if (idx == k)
    {
        for (int i = 0; i < k; i++)
        {
            q.push(make_pair(v[i].first, v[i].second));
        }
        ans = max(ans, count());
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                visited[i][j] = 1;
                v.push_back(make_pair(i, j));
                dfs(idx + 1);
                v.pop_back();
                visited[i][j] = 0;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k >> u >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}