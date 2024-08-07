#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[101][101];
int n;
bool check(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        if (y + dy[i] < 0 || x + dx[i] < 0 || y + dy[i] == n || x + dx[i] == n) continue;
        if (arr[y + dy[i]][x + dx[i]] < arr[y][x]) return true;
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int r, c;
    cin >> r >> c;
    int num = arr[r - 1][c - 1];
    queue<pair<int, int>> q;
    q.push(make_pair(r - 1, c - 1));
    int maxx = c-1;
    int maxy = r-1;
    for (int a = 0; a < k; a++)
    {
        int maxnum = 0;
        bool visited[101][101] = { 0, };
        while (q.size() > 0)
        {
            int qx = q.front().second;
            int qy = q.front().first;
            q.pop();
            num = arr[maxy][maxx];
            for (int i = 0; i < 4; i++)
            {
                if (num > arr[qy + dy[i]][qx + dx[i]]&&visited[qy+dy[i]][qx+dx[i]]==0)
                {
                    if (qy + dy[i] < 0 || qx + dx[i] < 0 || qy + dy[i] == n || qx + dx[i] == n) continue;
                    q.push(make_pair(qy + dy[i], qx + dx[i]));
                    visited[qy + dy[i]][qx + dx[i]] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 1)
                {
                    if (arr[i][j] > maxnum)
                    {
                        maxnum = arr[i][j];
                        maxx = j;
                        maxy = i;
                    }
                }
            }
        }
        num = maxnum;
        q.push(make_pair(maxy, maxx));
        if (check(maxy, maxx) == false)
        {
            cout << maxy + 1 << ' ' << maxx+1;
            return 0;
        }
    }
    cout << maxy + 1 << ' ' << maxx + 1;
    return 0;
}