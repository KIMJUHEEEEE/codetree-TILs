#include <iostream>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    int arr[52][52] = { 0, };

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            int map[52][52] = { 0, };
            for (int k = 0; k <= n + 2; k++)
            {
                if (k == 0)
                {
                    map[i][j] = 1;
                    if (arr[i][j] == 1) cnt++;
                }
                else
                {
                    for (int x = 1; x <= n; x++)
                    {
                        for (int y = 1; y <= n; y++)
                        {
                            int map2[52][52] = { 0, };
                            if (map[x][y] == 1)
                            {
                                map2[x][y] = 1;
                                for (int a = 0; a < 4; a++)
                                {
                                    map2[x + dx[a]][y + dy[a]] = 1;
                                    if (map[x + dx[a]][y + dy[a]] != 1)
                                    {
                                        map[x + dx[a]][y + dy[a]] = 2;
                                    }
                                }
                            }
                        }
                    }
                    for (int x = 1; x <= n; x++)
                    {
                        for (int y = 1; y <= n; y++)
                        {
                            if (map[x][y] == 2)
                            {
                                if (arr[x][y] == 1) cnt++;
                                map[x][y] = 1;
                            }
                        }
                    }
                }
                if (k * k + (k + 1) * (k + 1) <= cnt * m)
                {
                    ans = max(ans, cnt);
                }
            }

        }
    }
    cout << ans;
    return 0;
}