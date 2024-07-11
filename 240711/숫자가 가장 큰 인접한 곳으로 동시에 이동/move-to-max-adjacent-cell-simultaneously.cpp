#include <iostream>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, t;
    cin >> n >> m >> t;
    int arr[101][101] = { 0, };
    int beads[101][101] = { 0, };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = i = 0; i < m; i++)
    {
        int x, y;
        cin >> y >> x;
        beads[y - 1][x - 1] = 1;
    }
    for (int i = 0; i < t; i++)
    {
        int cpbeads[101][101] = { 0, };
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (beads[y][x] == 0) continue;
                else
                {
                    int max = 0;
                    int maxx = x;
                    int maxy = y;
                    for (int k = 0; k < 4; k++)
                    {
                        if(y+dy[k]<0||x+dx[k]<0||x+dx[k]==n||y+dy[k]==n) continue;
                        if (max < arr[y + dy[k]][x + dx[k]])
                        {
                            maxx = x + dx[k];
                            maxy = y + dy[k];
                            max = arr[maxy][maxx];
                        }
                    }

                    beads[y][x] = 0;
                    cpbeads[maxy][maxx]++;

                }
            }
        }
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                beads[y][x] = cpbeads[y][x];
                if(beads[y][x]>1) beads[y][x]=0;
            }
        }
    }
    int ans = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (beads[y][x] == 1) ans++;
        }
    }
    cout << ans;
    return 0;
}