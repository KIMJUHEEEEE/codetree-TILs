#include <iostream>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int n;
char arr[101][101];
int dir = 0;//우상좌하

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x, y;
    cin >> y >> x;
    y = y - 1;
    x = x - 1;
    int xx = x;
    int yy = y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    while (1)
    {
        if (y < 0 || x < 0 || x >= n || y >= n) break;
        if (x == xx && y == yy &&dir==0&&arr[y+1][x+1]!='#'&&ans>0)
        {
            ans = -1; break;
        }
        if (arr[y - 1][x] == '#' && arr[y + 1][x] == '#' && arr[y][x - 1] == '#' && arr[y][x + 1] == '#')
        {
            ans = -1; break;
        }
        if (dir == 0)
        {
            if (arr[y][x + 1] == '#')
            {
                dir = 1;
            }
            else if (arr[y + 1][x + 1] == '#')
            {
                dir = 0;
                y = y;
                x = x + 1;
                ans++;
            }
            else
            {
                y = y;
                x = x + 1;
                dir = 3;
                ans++;
            }
        }
        else if (dir == 1)
        {
            if (arr[y - 1][x] == '#')
            {
                dir = 2;
            }
            else if (arr[y - 1][x + 1] == '#')
            {
                dir = 1;
                y = y - 1;
                x = x;
                ans++;
            }
            else {
                y = y - 1;
                x = x;
                ans++;
                dir = 0;
            }
        }
        else if (dir == 2)
        {
            if (arr[y][x - 1] == '#')
            {
                dir = 3;
            }
            else if (arr[y - 1][x - 1] == '#')
            {
                dir = 2;
                y = y;
                x = x - 1;
                ans++;
            }
            else {
                y = y;
                x = x - 1;
                ans++;
                dir = 1;
            }
        }
        else if (dir == 3)
        {
            if (arr[y + 1][x] == '#')
            {
                dir = 0;
            }
            else if (arr[y + 1][x - 1] == '#')
            {
                dir = 3;
                y = y + 1;
                x = x;
                ans++;
            }
            else {
                y = y + 1;
                x = x;
                ans++;
                dir = 2;
            }
        }

    }
    if (ans == 0) ans = -1;
    cout << ans;
    return 0;
}