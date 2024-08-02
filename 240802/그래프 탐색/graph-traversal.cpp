#include <iostream>
using namespace std;
int n, m;
int arr[1001][100];
bool visited[1001][1001];
int ans = 0;
bool check(int idx)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[idx][i] == 0 && arr[idx][i] == 1)
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
        ans = max(ans, cnt);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (idx == i) continue;
        if (arr[idx][i] == 1 && visited[idx][i] == 0)
        {
            visited[idx][i] = 1;
            visited[i][idx] = 1;
            dfs(i, cnt + 1);
            arr[idx][i] = 0;
            visited[idx][i] = 0;
            visited[i][idx] = 0;
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
    visited[0][0] = 1;
    dfs(0, 0);
    cout << ans;
    return 0;
}