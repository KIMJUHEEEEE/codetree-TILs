#include <iostream>
#include <vector>
using namespace std;
int arr[5][5];
int direction[5][5];
int n, r, c;
int ans;
int dx[9] = { 0,0,1,1,1,0,-1,-1,-1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
vector<pair<int, int>> v;
bool Possible(int y, int x)
{
    if (y < 0 || x < 0 || y == n || x == n) return false;
    if (y == 0 && direction[y][x] == 1) return false;
    if (x == 0 && direction[y][x] == 7) return false;
    if (y == n - 1 && direction[y][x] == 5) return false;
    if (x == n - 1 && direction[y][x] == 3) return false;
    for (int i = 1; i < 4; i++)
    {
        //if (abs(direction[y][x] - direction[y + i * dy[direction[y][x]]][x + i * dx[direction[y][x]]]) == 4) return false;
        if (arr[y][x] < arr[y + i * dy[direction[y][x]]][x + i * dx[direction[y][x]]])
        {
            return true;
        }
    }
    return false;
}

void rec(int y, int x,int cnt)
{
    if (!Possible(y,x))
    {
        ans = max(ans, cnt);
        return;
    }
    for (int i = 1; i < 4; i++)
    {
        v.push_back(make_pair(y, x));
        if (arr[y][x] < arr[y + i * dy[direction[y][x]]][x + i * dx[direction[y][x]]])
        {
            rec(y + i * dy[direction[y][x]], x + i * dx[direction[y][x]], cnt + 1);
        } v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> direction[i][j];
        }
    }
    cin >> r >> c;
    rec(r - 1, c - 1,0);
    cout << ans;
    return 0;
}