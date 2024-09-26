#include <iostream>
#include <queue>
using namespace std;
int R, C, k;
int arr[101][101];
int exits[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void clearmap()
{
    for (int i = 0; i <= R; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            arr[i][j] = 0;
            exits[i][j] = 0;
        }
    }
}

int bfs(int y, int x, int d)
{
    int visited[101][101] = { 0, };
    int maxy = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    while (q.size() > 0)
    {
        int fy = q.front().first;
        int fx = q.front().second;
        maxy = max(fy, maxy);
        int numf = arr[fy][fx];
        visited[fy][fx] = 1;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (fy + dy[i] > R && fy + dy[i] <= 2 && fx + dx[i] > C && fx + dx[i] <= 0) continue;
            if (visited[fy + dy[i]][fx + dx[i]] == 0 && numf == arr[fy + dy[i]][fx + dx[i]])
            {
                q.push(make_pair(fy + dy[i], fx + dx[i]));
                visited[fy + dy[i]][fx + dx[i]] = 1;
            }

        }
        if (exits[fy][fx] == 1)
        {
            for (int j = 0; j < 4; j++)
            {
                if (arr[fy + dy[j]][fx + dx[j]] != numf && arr[fy + dy[j]][fx + dx[j]] != 0&&visited[fy+dy[j]][fx+dx[j]]==0)
                {
                    q.push(make_pair(fy + dy[j], fx + dx[j]));
                }
            }
        }
    }
    return maxy;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> R >> C >> k;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int c, d;
        cin >> c >> d;
        bool move = false;
        arr[0][c] = i;
        arr[1][c - 1] = i;
        arr[1][c] = i;
        arr[1][c + 1] = i;
        arr[2][c] = i;
        int y = 1;
        while (1)
        {
            if (move == true) break;
            if (arr[y + 1][c - 1] == 0 && arr[y + 2][c] == 0 && arr[y + 1][c + 1] == 0 && y <= R)
            {
                arr[y - 1][c] = 0;
                arr[y][c - 1] = 0;
                arr[y][c + 1] = 0;
                arr[y][c] = 0;
                arr[y + 1][c] = 0;
                arr[y + 1][c - 1] = i;
                arr[y + 1][c] = i;
                arr[y + 1][c + 1] = i;
                arr[y][c] = i;
                arr[y + 2][c] = i;
                y += 1;
            }
            else if (arr[y - 1][c - 1] == 0 && arr[y][c - 2] == 0 && arr[y + 1][c - 1] == 0 && arr[y + 1][c - 2] == 0 && arr[y + 2][c - 1] == 0 && y <= R && c - 2 > 0)
            {
                arr[y - 1][c] = 0;
                arr[y][c - 1] = 0;
                arr[y][c + 1] = 0;
                arr[y][c] = 0;
                arr[y + 1][c] = 0;
                arr[y + 1][c - 2] = i;
                arr[y + 1][c - 1] = i;
                arr[y + 1][c] = i;
                arr[y][c - 1] = i;
                arr[y + 2][c - 1] = i;
                d = (d + 3) % 4;
                y += 1;
                c -= 1;
            }
            else if (arr[y - 1][c + 1] == 0 && arr[y][c + 2] == 0 && arr[y + 1][c + 1] == 0 && arr[y + 1][c + 2] == 0 && arr[y + 2][c + 1] == 0 && y <= R && c + 2 <= C)
            {
                arr[y - 1][c] = 0;
                arr[y][c - 1] = 0;
                arr[y][c + 1] = 0;
                arr[y][c] = 0;
                arr[y + 1][c] = 0;
                arr[y + 1][c + 2] = i;
                arr[y + 1][c + 1] = i;
                arr[y + 1][c] = i;
                arr[y][c + 1] = i;
                arr[y + 2][c + 1] = i;
                d = (d + 1) % 4;
                y += 1;
                c += 1;
            }
            else if (y <= 2)
            {
                move = true;
                clearmap();
            }
            else
            {
                move = true;
                if (d == 0) exits[y - 1][c] = 1;
                else if (d == 1) exits[y][c + 1] = 1;
                else if (d == 2) exits[y + 1][c] = 1;
                else if (d == 3) exits[y][c - 1] = 1;
                ans += (bfs(y, c, d)-2);

            }
        }

    }
    cout << ans;
    return 0;
}