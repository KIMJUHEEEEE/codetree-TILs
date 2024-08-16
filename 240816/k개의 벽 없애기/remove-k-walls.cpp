#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int n, k;
int arr[101][101];
int visited[101][101];
bool ck[101][101];
int r1, c1, r2, c2;
vector<pair<int, int>> v;
int ans = INT_MAX;


void bfs(int y0, int x0)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(y0, x0));
    visited[y0][x0] = 1;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    while (q.size() > 0)
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (y + dy[i] < 0 || x + dx[i] < 0 || y + dy[i] == n || x + dx[i] == n) continue;
            if (arr[y + dy[i]][x + dx[i]] == 0 && visited[y + dy[i]][x + dx[i]] == 0)
            {
                q.push(make_pair(y + dy[i], x + dx[i]));
                visited[y + dy[i]][x + dx[i]] = visited[y][x] + 1;
            }
        }
    }
}

void dfs(int idx)
{
    if (idx == k)
    {
        for (int i = 0; i < k; i++)
        {
            arr[v[i].first][v[i].second] = 0;
        }
        bfs(r1 - 1, c1 - 1);
        if (visited[r2 - 1][c2 - 1] != 0)
            ans = min(ans, visited[r2 - 1][c2 - 1]);
        for (int i = 0; i < k; i++)
        {
            arr[v[i].first][v[i].second] = 1;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && ck[i][j] == 0)
            {
                v.push_back(make_pair(i, j));
                ck[i][j] = 1;
                dfs(idx + 1);
                v.pop_back();
                ck[i][j] = 0;
            }
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;
    dfs(0);
    if (ans == INT_MAX) ans = 0;
    cout << ans-1;
    return 0;
}