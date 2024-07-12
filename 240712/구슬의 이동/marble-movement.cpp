#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



class beads {
public:
    int r;
    int c;
    int d;
    int v;
    int i;
    beads(int r, int c, int d, int v, int i) {
        this->r = r;
        this->d = d;
        this->c = c;
        this->i = i;
        this->v = v;
    }
    };
    bool cmp(beads a, beads b)
    {
        if (a.v == b.v)
        {
            return a.i > b.i;
        }
        return a.v > b.v;
    }

    int main()
    {
        // 여기에 코드를 작성해주세요.
        int n, m, t, k;
        cin >> n >> m >> t >> k;
        vector<beads> arr[51][51];

        for (int i = 0; i < m; i++)
        {
            int r, c, v;
            int dir = 0;
            char d;
            cin >> r >> c >> d >> v;
            if (d == 'R') dir = 0;
            else if (d == 'D') dir = 1;
            else if (d == 'L') dir = 2;
            else if (d == 'U') dir = 3;
            arr[r - 1][c - 1].push_back(beads(r - 1, c - 1, dir, v, i + 1));
        }
        while (t--)
        {
            vector<beads> cparr[51][51];

            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < n; x++)
                {
                    int xx;
                    int yy;
                    int dir;
                    if (arr[y][x].size() == 0) continue;
                    if (arr[y][x].size() != 0)
                    {

                        for (int b = 0; b < arr[y][x].size(); b++)
                        {
                            xx = x;
                            yy = y;
                            for (int a = 0; a < arr[y][x][b].v; a++)
                            {
                                dir = arr[y][x][b].d;
                                if (xx + dx[dir] < 0 || yy + dy[dir] < 0 || xx + dx[dir] == n || yy + dy[dir] == n)
                                {
                                    dir = (dir + 2) % 4;
                                    arr[y][x][b].d = dir;
                                    xx += dx[dir];
                                    yy += dy[dir];
                                }
                                else {
                                    xx += dx[dir];
                                    yy += dy[dir];
                                }
                            }
                            cparr[yy][xx].push_back(arr[y][x][b]);
                            if (cparr[yy][xx].size() == k+1)
                            {
                                sort(cparr[yy][xx].begin(), cparr[yy][xx].end(), cmp);
                                cparr[yy][xx].pop_back();
                            }
                        }

                    }
                }
            }
            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < n; x++)
                {
                    arr[y][x] = cparr[y][x];
                }
            }
        }
        int ans = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                ans += arr[y][x].size();
            }
        }
        cout << ans;
        return 0;
    }