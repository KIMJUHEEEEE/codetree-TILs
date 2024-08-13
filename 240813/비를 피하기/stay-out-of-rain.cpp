#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    // 여기에 코드를 작성해주세요.

    int n, h, m;
    cin >> n >> h >> m;
    int arr[101][101] = { 0, };
    int ans[101][101] = { 0, };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            queue<pair<int, int>> q;
            int visited[101][101] = { 0, };
            if (arr[i][j] == 2)
            {
                q.push(make_pair(i, j));
                while (q.size() > 0)
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        if (y + dy[k] < 0 || x + dx[k] < 0 || y + dy[k] == n || x + dx[k] == n) continue;
                        if ((arr[y + dy[k]][x + dx[k]] == 0||arr[y + dy[k]][x + dx[k]] == 2)&&visited[y+dy[k]][x+dx[k]]==0)
                        {
                            q.push(make_pair(y + dy[k], x + dx[k]));
                            visited[y + dy[k]][x + dx[k]] = visited[y][x]+1;
             
                        }
                        else if (arr[y + dy[k]][x + dx[k]] == 3)
                        {
                            if (ans[i][j] == 0)
                            {
                                ans[i][j] = visited[y][x] + 1;
                            }
                            else
                            {
                                ans[i][j] = min(ans[i][j], visited[y][x] + 1);
                            }
                        }
                    }
                }
                if(ans[i][j]==0) ans[i][j]=-1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}