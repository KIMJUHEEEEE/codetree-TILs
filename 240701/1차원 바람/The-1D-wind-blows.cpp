#include <iostream>
using namespace std;
int arr[101][101] = { 0, };
int n, m, q;
void moveright(int a) {
    int tmp = arr[a][m - 1];
    for (int j = m - 1; j > 0; j--)
    {
        arr[a][j] = arr[a][j - 1];
    }
    arr[a][0] = tmp;
}

void moveleft(int a) {
    int tmp = arr[a][0];
    for (int j = 0; j < m - 1; j++)
    {
        arr[a][j] = arr[a][j + 1];
    }
    arr[a][m - 1] = tmp;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int w = 0; w < q; w++)
    {
        int a = 0;
        char c = ' ';
        cin >> a >> c;
        if (c == 'L')
        {
            int lowu = a - 1;
            int lowd = a - 1;
            moveright(lowu);
            bool ck = 0;//왼쪽
            bool move = 0;
            while (1)
            {
                bool correct = 0;
                if(lowu>0)
                {for (int j = 0; j < m; j++)
                {
                    if (arr[lowu][j] == arr[lowu - 1][j])
                    {
                        correct = 1;
                        break;
                    }
                }
                if (correct == 1 && lowu - 1 >= 0)
                {
                    if (ck == 0)
                    {
                        moveleft(lowu - 1);
                        move = 1;
                    }
                    else
                    {
                        moveright(lowu - 1);
                        move = 1;
                    }
                    lowu--;
                }
                }
                bool correct1 = 0;
                if(lowd<n-1)
                {for (int j = 0; j < m; j++)
                {
                    if (arr[lowd][j] == arr[lowd + 1][j])
                    {
                        correct1 = 1;
                        break;
                    }
                }
                if (correct1 == 1 && lowd + 1 >= 0)
                {
                    if (ck == 0)
                    {
                        moveleft(lowd + 1);
                        move = 1;
                    }
                    else
                    {
                        moveright(lowd + 1);
                        move = 1;
                    }
                    lowd++;
                }
                }
                if (correct == 0 && correct1 == 0) break;
                if (move == 1)
                {
                    if (ck == 0)
                    {
                        ck = 1;
                    }
                    else
                    {
                        ck = 0;
                    }
                    move = 0;
                }
            }
        }
        else if (c == 'R')
        {
            int lowu = a - 1;
            int lowd = a - 1;
            moveleft(lowu);
            bool ck = 1;//왼쪽
            bool move=0;
            while (1)
            {
                bool correct = 0;
                if(lowu>0)
                {for (int j = 0; j < m; j++)
                {
                    if (arr[lowu][j] == arr[lowu - 1][j])
                    {
                        correct = 1;
                        break;
                    }
                }
                if (correct == 1 && lowu - 1 >= 0)
                {
                    if (ck == 0)
                    {
                        moveleft(lowu - 1);
                    }
                    else
                    {
                        moveright(lowu - 1);
                    }
                    lowu--;
                }
                }
                bool correct1 = 0;
                if(lowd<n-1)
                {for (int j = 0; j < m; j++)
                {
                    if (arr[lowd][j] == arr[lowd + 1][j])
                    {
                        correct1 = 1;
                        break;
                    }
                }
                if (correct1 == 1 && lowd + 1 >= 0)
                {
                    if (ck == 0)
                    {
                        moveleft(lowd + 1);
                    }
                    else
                    {
                        moveright(lowd + 1);
                    }
                    lowd++;
                }
                }
                if (move == 1)
                {
                    if (ck == 0)
                    {
                        ck = 1;
                    }
                    else
                    {
                        ck = 0;
                    }
                    move = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}