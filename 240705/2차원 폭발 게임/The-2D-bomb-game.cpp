#include <iostream>
using namespace std;
int arr[101][101];

int n, m, k;

bool bomb()
{
    bool ck = 0;
    for (int j = 0; j < n; j++)
    {
        int cnt = 1;
        int si = -1;
        int ei = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i][j] == arr[i + 1][j]&&arr[i][j]!=0)
            {
                cnt++;
                if (si == -1) si = i;
                ei = i + 1;
                if (ei == n - 1)
                {
                    for (int a = si; a <= ei; a++)
                    {
                        arr[a][j] = 0;
                        ck = 1;
                    }
                    cnt = 1;
                    si = -1;
                    ei = 0;
                }
            }
            else
            {
                if (cnt >= m)
                {
                    for (int a = si; a <= ei; a++)
                    {
                        arr[a][j] = 0;
                        ck = 1;
                    }
                    cnt = 1;
                    si = -1;
                    ei = 0;
                }
            }
        }
    }
    return ck;
}

void down()
{
    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i > 0; i--)
        {
            int a = i;
            if (arr[a][j] == 0 && arr[a - 1][j] != 0)
            {
                while (1)
                {
                    if (arr[a][j] != 0) break;
                    else {
                        arr[a][j] = arr[a - 1][j];
                        arr[a - 1][j] = 0;
                    }
                    a++;
                    if (a == n) break;
                }

            }
        }
    }
}

void rotate()
{
    int cparr[101][101];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cparr[i][j] = arr[n - 1 - j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = cparr[i][j];
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    if(m==1)
    {
        cout<<0;
        return 0;
    }
    for (int a = 0; a < k; a++)
    {
        bomb();
        down();
        rotate();
        down();
    }
    while (1)
    {
        bool ck=bomb();
        if (ck == 0) break;
        down();
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}