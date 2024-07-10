#include <iostream>
using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        char arr[51][51] = { 0, };
        for (int j = 0; j < m; j++)
        {
            int x, y;
            char d;
            cin >> x >> y >> d;
            arr[x - 1][y - 1] = d;
        }
        if (m == 1||m==0)
        {
            cout << m << endl;
            continue;
        }
        int cnt = 2*n+1;
        while (cnt--) {
            char cparr[51][51] = { 0, };
            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < n; x++)
                {
                    if (arr[y][x] == '\0') continue;
                    if (arr[y][x] == 'D')
                    {
                        if (y + 1 == n)
                        {
                            if (cparr[y][x] != '\0'||cparr[y][x]=='M')
                            {
                                cparr[y][x] = 'M';
                            }
                            else cparr[y][x] = 'U';
                        }
                        else
                        {
                            if (cparr[y+1][x] != '\0' || cparr[y][x] == 'M')
                            {
                                cparr[y+1][x] = 'M';
                            }
                            else cparr[y + 1][x] = 'D';
                        }
                    }
                    else if (arr[y][x] == 'U')
                    {
                        if (y - 1 < 0)
                        {
                            if (cparr[y][x] != '\0' || cparr[y][x] == 'M')
                            {
                                cparr[y][x] = 'M';
                            }
                            else cparr[y][x] = 'D';
                        }
                        else
                        {
                            if (cparr[y-1][x] != '\0' || cparr[y][x] == 'M')
                            {
                                cparr[y-1][x] = 'M';
                            }
                            else cparr[y - 1][x] = 'U';
                        }
                    }
                    else if (arr[y][x] == 'R')
                    {
                        if (x + 1 == n)
                        {

                            if (cparr[y][x ] != '\0' || cparr[y][x] == 'M')
                            {
                                cparr[y][x] = 'M';
                            }
                            else cparr[y][x] = 'L';
                        }
                        else
                        {
                            if (cparr[y][x+1] != '\0' || cparr[y][x] == 'M')
                            {
                                cparr[y][x+1] = 'M';
                            }
                            else cparr[y][x + 1] = 'R';
                        }
                    }
                    else if (arr[y][x] == 'L')
                    {
                        if (x - 1 < 0)
                        {
                            if (cparr[y][x] != '\0' || cparr[y][x] == 'M')
                            {
                                cparr[y][x] = 'M';
                            }
                            else cparr[y][x] = 'R';
                        }
                        else
                        {
                            if (cparr[y][x-1] != '\0' || cparr[y][x] == 'M')
                            {
                                cparr[y][x-1] = 'M';
                            }
                            else cparr[y][x - 1] = 'L';
                        }
                    }
                }
            }

            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < n; x++)
                {
                    arr[y][x] = cparr[y][x];
                    if (arr[y][x] == 'M') arr[y][x] = '\0';
                }
            }
        }
        int num = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (arr[y][x] != '\0')
                {
                    num++;
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}