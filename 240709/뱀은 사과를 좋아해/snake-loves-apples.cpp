#include <iostream>
#include <vector>
using namespace std;
int arr[101][101];
int dir = 0;//우상좌하
vector<pair<int, int>> snake;
bool snakecheck()
{

    for (int i = 1; i < snake.size() - 1; i++)
    {
        if (snake[0].first == snake[i].first && snake[0].second == snake[i].second)
        {
            return true;
        }
    }
    return false;
}
int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x - 1][y - 1] = 1;
    }
    int ans = 0;

    snake.push_back(make_pair(0,0));
    for (int i = 0; i < k; i++)
    {
        char c;
        int p;
        cin >> c >> p;
        if (c == 'D')
        {
            int y = snake[0].first;
            int x = snake[0].second;
            if (y == n-1) break;
            else
            {
                for (int j = 0; j < p; j++)
                {
                    ans++;
                    int hy = snake[0].first;
                    int hx = snake[0].second;
                    bool apple = 0;
                    if (arr[hy + 1][hx] == 1)
                    {
                        apple = 1;
                        arr[hy + 1][hx] = 0;
                        int ty = snake[snake.size() - 1].first;
                        int tx = snake[snake.size() - 1].second;
                        snake.push_back(make_pair(ty, tx));
                    }
                    if (snake.size() > 1)
                    {
                        int s = snake.size() - 1;
                        if (apple == 1) s--;
                        for (int a = s; a >0; a--)
                        {
                            snake[a].first = snake[a - 1].first;
                            snake[a].second = snake[a - 1].second;

                        }
                        
                    }
                    snake[0].first = hy + 1;
                    if (hy + 1 == n || snakecheck() == true)
                    {
                        cout << ans;
                        return 0;
                    }


                }
            }
        }
        else if (c == 'R')
        {
            int y = snake[0].first;
            int x = snake[0].second;
            if (x == n - 1) break;
            else
            {
                for (int j = 0; j < p; j++)
                {
                    ans++;
                    int hy = snake[0].first;
                    int hx = snake[0].second;
                    bool apple = 0;
                    if (arr[hy][hx+1] == 1)
                    {
                        apple = 1;
                        arr[hy][hx+1] = 0;
                        int ty = snake[snake.size() - 1].first;
                        int tx = snake[snake.size() - 1].second;
                        snake.push_back(make_pair(ty, tx));
                    }
                    if (snake.size() > 1)
                    {
                        int s = snake.size() - 1;
                        if (apple == 1) s--;
                        for (int a = s; a > 0; a--)
                        {
                            snake[a].first = snake[a - 1].first;
                            snake[a].second = snake[a - 1].second;

                        }

                    }
                    snake[0].second = hx + 1;
                    if (hx + 1 == n || snakecheck() == true)
                    {
                        cout << ans;
                        return 0;
                    }

                }
            }
        }
        else if (c == 'U')
        {
            int y = snake[0].first;
            int x = snake[0].second;
            if (y == 0) break;
            else
            {
                for (int j = 0; j < p; j++)
                {
                    ans++;
                    int hy = snake[0].first;
                    int hx = snake[0].second;
                    bool apple = 0;
                    if (arr[hy-1][hx] == 1)
                    {
                        apple = 1;
                        arr[hy -1][hx] = 0;
                        int ty = snake[snake.size() - 1].first;
                        int tx = snake[snake.size() - 1].second;
                        snake.push_back(make_pair(ty, tx));
                    }
                    if (snake.size() > 1)
                    {
                        int s = snake.size() - 1;
                        if (apple == 1) s--;
                        for (int a = s; a > 0; a--)
                        {
                            snake[a].first = snake[a - 1].first;
                            snake[a].second = snake[a - 1].second;

                        }

                    }
                    snake[0].first = hy - 1;
                    if (hy - 1 < 0 || snakecheck() == true)
                    {
                        cout << ans;
                        return 0;
                    }

                }
            }
        }
        else if (c == 'L')
        {
            int y = snake[0].first;
            int x = snake[0].second;
            if (x == 0) break;
            else
            {
                for (int j = 0; j < p; j++)
                {
                    ans++;
                    int hy = snake[0].first;
                    int hx = snake[0].second;
                    bool apple = 0;
                    if (arr[hy][hx - 1] == 1)
                    {
                        apple = 1;
                        arr[hy][hx-1] = 0;
                        int ty = snake[snake.size() - 1].first;
                        int tx = snake[snake.size() - 1].second;
                        snake.push_back(make_pair(ty, tx));
                    }
                    if (snake.size() > 1)
                    {
                        int s = snake.size() - 1;
                        if (apple == 1) s--;
                        for (int a = s; a > 0; a--)
                        {
                            snake[a].first = snake[a - 1].first;
                            snake[a].second = snake[a - 1].second;

                        }

                    }
                    snake[0].second = hx - 1;
                    if (hx - 1 < 0 || snakecheck() == true)
                    {
                        cout << ans;
                        return 0;
                    }

                }
            }
        }
    }
    cout << ans;
    return 0;
}