#include <iostream>
using namespace std;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    int arr[21][21] = { 0, };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n * n; j++)
        {
            for (int y = 0; y < n; y++)
            {
                bool ck = 0;
                for (int x = 0; x < n; x++)
                {
                    int maxx = 0;
                    int maxy = 0;

                    if (arr[y][x] == j)
                    {
                        ck = 1;
                        int maxnum = 0;
                        for (int a = 0; a < 8; a++)
                        {
                            if (y + dy[a] < 0 || y + dy[a] == n || x + dx[a] < 0 || x + dx[a] == n) continue;
                            if (arr[y + dy[a]][x + dx[a]] > maxnum)
                            {
                                maxnum = arr[y + dy[a]][x + dx[a]];
                                maxx = x + dx[a];
                                maxy = y + dy[a];
                            }
                        }
                        int tmp = arr[y][x];
                        arr[y][x] = maxnum;
                        arr[maxy][maxx] = tmp;
                    }
                    if (ck == 1) break;
                }
                if (ck == 1) break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}