#include <iostream>
#include <queue>
using namespace std;
int n, m;
int arr[201][301];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int last_num;
int take;
queue<pair<int, int>> q;
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

int check_water()
{
    int q_num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                int sum = 0;
                for (int k = 0; k < 4; k++)
                {
                    if (i + dy[k] < 0 || j + dx[k] < 0 || i + dx[k] == n || j + dx[k] == m) continue;
                    if (arr[i + dy[k]][j + dx[k]] == 1) sum++;
                }
                if (sum != 4)
                {
                    q.push(make_pair(i, j));
                    q_num++;
                }
            }
        }
    }
    return q_num;
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
        int q_num = check_water();
        while (q_num > 0)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            q_num--;
            for (int k = 0; k < 4; k++)
            {
                if (y + dy[k] < 0 || x + dx[k] < 0 || y + dx[k] == n || x + dx[k] == m) continue;
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
    cout << take-1 << ' ' << last_num;
    return 0;
}