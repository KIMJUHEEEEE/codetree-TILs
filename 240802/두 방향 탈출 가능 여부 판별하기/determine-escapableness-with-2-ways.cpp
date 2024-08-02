#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[101][101];
int ans = 0;

bool ck(int x, int y)
{
    if (arr[y + 1][x] == 0 && arr[y][x + 1] == 0) return false;
    return true;
}

void dfs(int y, int x)
{
    if (x == m - 1 && y == n - 1) { ans = 1; return; }
    if (ck(x, y) == false)
    {
        return;
    }
   
    if (arr[y + 1][x] == 1 && y + 1 < n)
    {
        dfs(y + 1, x);
    }
    if (arr[y][x + 1] == 1 && x + 1 < m)
    {
        dfs(y, x + 1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}