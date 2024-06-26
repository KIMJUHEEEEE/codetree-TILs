#include <iostream>
using namespace std;
int dy[4] = { 1,-1,-1,1 };
int dx[4] = { -1,-1,1,1 };


int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[21][21] = { 0, };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            int x = i;
            int y = j;
            int sum = arr[x][y];
            int map[22][22] = { 0, };
            map[x][y] = 1;
            int cnta = 0;
            int cntb = 0;
            for (int a = 0; a < 4; a++)
            {
                while (1)
                {
                    if (a == 0) cnta++;
                    if (a == 1) cntb++;
                    if (a == 2)
                    {
                        if (cnta == 0) break;
                        cnta--;
                    }
                    if (a == 3)
                    {
                        if (cntb == 0) break;
                        cntb--;
                    }
                    x += dx[a];
                    y += dy[a];
                    if (a == 0 && x == 0)
                    {
                        cnta--;
                        x -= dx[a];
                        y -= dy[a];
                        break;
                    }
                    else if (a == 1 && y == 0)
                    {
                        cntb--;
                        x -= dx[a];
                        y -= dy[a];
                        break;
                    }
                    else if (a == 2 && x == n - 1)
                    {
                        x -= dx[a];
                        y -= dy[a];
                        break;
                    }
                    else if (a == 3 && y == n - 1)
                    {
                        x -= dx[a];
                        y -= dy[a];
                        break;
                    }
                    if (x >= n || x < 0 || y < 0 || y >= n || map[x][y] == 1)
                    {
                        x -= dx[a];
                        y -= dy[a];
                        break;
                    }
                    else
                    {
                        if (map[x][y] == 0)
                        {
                            sum += arr[x][y];
                            map[x][y] = 1;
                        }
                    }
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans;
    return 0;
}