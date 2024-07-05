#include <iostream>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[51][51];
int cparr[51][51];
int n;

void down()
{
    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i > 0; i--)
        {
            int a = i;
            if (cparr[a][j] == 0 && cparr[a - 1][j] != 0)
            {
                while (1)
                {
                    if (cparr[a][j] != 0) break;
                    else {
                        cparr[a][j] = cparr[a - 1][j];
                        cparr[a - 1][j] = 0;
                    }
                    a++;
                    if (a == n) break;
                }

            }
        }
    }
}

void copy()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cparr[i][j] = arr[i][j];
        }
    }
}

int search()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (cparr[i][j] == cparr[i][j + 1]&&cparr[i][j]!=0)
            {
                cnt++;
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (cparr[i][j] == cparr[i + 1][j]&&cparr[i][j]!=0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            copy();
            int num = arr[i][j];

            cparr[i][j] = 0;
            if (num > 1)
            {
                for (int a = 0; a < 4; a++)
                {
                    int x = j;
                    int y = i;
                    for (int b = 0; b < num-1; b++)
                    {
                        if (x + dx[a] < 0 || x + dx[a] >= n || y + dy[a] < 0 || y + dy[a] >= n) break;
                        x = x + dx[a];
                        y = y + dy[a];
                        cparr[y][x] = 0;
                    }
                }
            }
            down();

            ans = max(ans, search());
        }
    }
    cout << ans;
    return 0;
}