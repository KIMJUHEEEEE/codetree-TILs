#include <iostream>
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };//남서북동
using namespace std;
char arr[1002][1002];
int arrd[1002][1002];
int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int x = 0;
    int y = 1;
    int dir = 3;
    for (int i = 1; i <= 4 * n; i++)
    {
        if (x == 0 && y == 0 || x == n + 1 && y == 0 || x == n + 1 && y == n + 1 || x == 0 && y == n + 1)
        {


            dir = (dir + 1) % 4;
            x += dx[dir];
            y += dy[dir];
            i--;

        }
        else {
            arrd[x][y] = i;
            x += dx[dir];
            y += dy[dir];
        }
    }
    int k;
    cin >> k;
    bool check = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arrd[i][j] == k)
            {
                x = i; y = j;
                check = 1;
                break;
            }
        }
        if (check == 1) break;
    }
    dir = (k - 1) / n;//남서북동
    int cnt = 0;
    x += dx[dir];
    y += dy[dir];
    while (1)
    {
        if (arr[x][y] != '/' && arr[x][y] != '\\')
        {
            break;
        }
        else if (arr[x][y] == '/')
        {
            if (dir == 0) dir = 1;
            else if (dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else dir = 2;
            x += dx[dir];
            y += dy[dir];
            cnt++;
        }
        else if (arr[x][y] == '\\')
        {
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else dir = 0;
            x += dx[dir];
            y += dy[dir];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}