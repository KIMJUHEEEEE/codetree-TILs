#include <iostream>
#include <queue>
using namespace std;
int n, m;
int arr[201][301];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int last_num;
int take;
int q_num = 0;
queue<pair<int, int>> q;
queue<pair<int, int>> water;
int count_g_num()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                sum++;
            }
        }
    }
    return sum;
}

void check_water()
{
    bool visited[201][301] = { 0, };
    q.push(make_pair(0, 0));
    water.push(make_pair(0, 0));
    visited[0][0] = 1;
    q_num = 1;
    while (q.size() > 0)
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            if (y + dy[k] < 0 || x + dx[k] < 0 || y + dy[k] == n || x + dx[k] == m) continue;
            if (arr[y + dy[k]][x + dx[k]] == 0&&visited[y+dy[k]][x+dx[k]]==0)
            {
                q.push(make_pair(y + dy[k], x + dx[k]));
                water.push(make_pair(y + dy[k], x + dx[k]));
                visited[y + dy[k]][x + dx[k]] = 1;
                q_num++;
            }
        }
    }
}

void bfs()
{
    while (1)
    {
        take++;
        if (count_g_num() == 0) return;
        if (count_g_num() > 0)
        {
            last_num = count_g_num();
        }
        check_water();
        while (q_num > 0)
        {
            int y = water.front().first;
            int x = water.front().second;
            water.pop();
            q_num--;
            for (int k = 0; k < 4; k++)
            {
                if (y + dy[k] < 0 || x + dx[k] < 0 || y + dy[k] == n || x + dx[k] == m) continue;
                if (arr[y + dy[k]][x + dx[k]] == 1)
                {
                    arr[y + dy[k]][x + dx[k]] = 0;
                    q.push(make_pair(y + dy[k], x + dx[k]));
                }
            }

        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    bfs();
    cout << take - 1 << ' ' << last_num;
    return 0;
}