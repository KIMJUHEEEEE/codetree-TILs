#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[101][101];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    //위에서
    int dir = 0;//하좌상우
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        dir = 0;
        int count = 1;
        int x = j;
        int y = 0;
        while (1)
        {
            if (x < 0 || y < 0 || x == n || y == n) break;
            count++;
             if (dir == 0)
            {
                if (arr[y][x] == 0)
                {
                    y += 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 1;
                    x-= 1;
                }
                else
                {
                    dir = 3;
                    x += 1;
                }
            }
            else if (dir == 1)
            {
                if (arr[y][x] == 0)
                {
                    x -= 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 0;
                    y+= 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 2;
                    y -= 1;
                }
            }
            else if (dir == 2)
            {
                if (arr[y][x] == 0)
                {
                    y -= 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 3;
                    x += 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 1;
                    x -= 1;
                }
            }
            else if (dir == 3)
            {
                if (arr[y][x] == 0)
                {
                    x += 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 2;
                    y-= 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 0;
                    y += 1;
                }
            }
        }
        ans = max(ans, count);
    }
    for (int i = 0; i < n; i++)
    {
        dir = 1;
        int count = 1;
        int x = n-1;
        int y = i;
        while (1)
        {
            if (x < 0 || y < 0 || x == n || y == n) break;
            count++;
            if (dir == 0)
            {
                if (arr[y][x] == 0)
                {
                    y += 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 1;
                    x -= 1;
                }
                else
                {
                    dir = 3;
                    x += 1;
                }
            }
            else if (dir == 1)
            {
                if (arr[y][x] == 0)
                {
                    x -= 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 0;
                    y += 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 2;
                    y -= 1;
                }
            }
            else if (dir == 2)
            {
                if (arr[y][x] == 0)
                {
                    y -= 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 3;
                    x += 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 1;
                    x -= 1;
                }
            }
            else if (dir == 3)
            {
                if (arr[y][x] == 0)
                {
                    x += 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 2;
                    y -= 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 0;
                    y += 1;
                }
            }
        }
        ans = max(ans, count);
    }
    for (int j = 0; j < n; j++)
    {
        int count = 1;
        int x = j;
        int y = n-1;
        dir = 2;
        while (1)
        {
            if (x < 0 || y < 0 || x == n || y == n) break;
            count++;
            if (dir == 0)
            {
                if (arr[y][x] == 0)
                {
                    y += 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 1;
                    x -= 1;
                }
                else
                {
                    dir = 3;
                    x += 1;
                }
            }
            else if (dir == 1)
            {
                if (arr[y][x] == 0)
                {
                    x -= 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 0;
                    y += 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 2;
                    y -= 1;
                }
            }
            else if (dir == 2)
            {
                if (arr[y][x] == 0)
                {
                    y -= 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 3;
                    x += 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 1;
                    x -= 1;
                }
            }
            else if (dir == 3)
            {
                if (arr[y][x] == 0)
                {
                    x += 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 2;
                    y -= 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 0;
                    y += 1;
                }
            }
        }
        ans = max(ans, count);
    }
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        int x = 0;
        int y = i;
        dir = 3;
        while (1)
        {
            if (x < 0 || y < 0 || x == n || y == n) break;
            count++;
            if (dir == 0)
            {
                if (arr[y][x] == 0)
                {
                    y += 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 1;
                    x -= 1;
                }
                else
                {
                    dir = 3;
                    x += 1;
                }
            }
            else if (dir == 1)
            {
                if (arr[y][x] == 0)
                {
                    x -= 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 0;
                    y += 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 2;
                    y -= 1;
                }
            }
            else if (dir == 2)
            {
                if (arr[y][x] == 0)
                {
                    y -= 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 3;
                    x += 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 1;
                    x -= 1;
                }
            }
            else if (dir == 3)
            {
                if (arr[y][x] == 0)
                {
                    x += 1;
                }
                else if (arr[y][x] == 1)
                {
                    dir = 2;
                    y -= 1;
                }
                else if (arr[y][x] == 2)
                {
                    dir = 0;
                    y += 1;
                }
            }
        }
        ans = max(ans, count);
    }
    cout << ans;
    return 0;
}