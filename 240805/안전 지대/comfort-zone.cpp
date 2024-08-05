#include <iostream>
using namespace std;
int n, m;
int arr[51][51];
int ck[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int minik = 1000;
int maxs = 0;

bool check(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] == m|| y + dy[i] == n) continue;
        if (arr[y + dy[i]][x + dx[i]] != 0 && ck[y + dy[i]][x + dx[i]] == 0) return true;
    }
    return false;
}

void dfs(int x, int y, int num)
{
    if (check(x, y) == false)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (arr[y + dy[i]][x + dx[i]] > 0 && ck[y + dy[i]][x + dx[i]] == 0)
        {
            ck[y + dy[i]][x + dx[i]] = num;
            dfs(x + dx[i], y + dy[i], num);

        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int k = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            k = max(k, arr[i][j]);
        }
    }
    if(k==1)
    {
        cout<<1<<' '<<0;
        return 0;
    }
    for (int a = 1; a < k; a++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ck[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] <= a)
                {
                    arr[i][j] = 0;
                }
            }
        }
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] != 0 && ck[i][j] == 0)
                {
                    num++;
                    ck[i][j] = num;
                    dfs(j, i, num);
                }
            }
        }
        if (maxs < num)
        {
            maxs = num;
            minik = a;
        }
    }
    cout << minik << ' ' << maxs;
    return 0;
}