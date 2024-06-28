#include <iostream>
using namespace std;
int dx[4] = { 1,-1,-1,1 };
int dy[4] = { -1,-1,1,1 };


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
    for (int y = 1; y < n - 1; y++)
    {
        for (int x = 1; x < n - 1; x++)
        {
            //if (x + y > n) break;
            for (int i = y + x; i < n; i++)
            {
                for (int j = y; j < n - x; j++)
                {
                    int map[21][21] = { 0, };
                    int xx = j;
                    int yy = i;
                    int sum = arr[i][j];
                    map[i][j] = 1;
                    int cnt = 0;
                    for (int a = 0; a < 4; a++)
                    {
                        int cnta = y;//1,3
                        int cntb = x;//0,2
                        while (1) {
                            xx += dx[a];
                            yy += dy[a];
                            if (xx >= n || xx < 0 || yy < 0 || yy >= n || cnta == 0 || cntb == 0 || map[yy][xx] == 1)
                            {
                                xx -= dx[a];
                                yy -= dy[a];
                                break;
                            }
                            sum += arr[yy][xx];
                            map[yy][xx] = 1;
                            cnt++;
                            if (a == 0 || a == 2) cntb--;
                            else if (a == 1 || a == 3) cnta--;
                        }


                    }
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans;
    return 0;
}