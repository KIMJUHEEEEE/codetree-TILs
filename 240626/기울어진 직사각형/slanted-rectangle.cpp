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
    for (int c= 1; c < n - 1; c++)
    {
        int x = n - 1;
        int y = c;
        int sum = arr[x][y];
        int map[22][22] = { 0, };
        map[x][y] = 1;
        for (int a = 0; a < 4; a++)
        {
            while (1)
            {
                x += dx[a];
                y += dy[a];
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
    cout << ans;
    return 0;
}