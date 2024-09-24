#include <iostream>
#include <vector>
using namespace std;
int r, c, k;
int arr[71][71];

bool checksouth(int y, int x)
{
    if (arr[y + 1][x - 1] == 0 && arr[y + 2][x] == 0 && arr[y + 1][x + 1] == 0) return true;
    else return false;
}
bool checkwest(int y, int x)
{
    if (arr[y - 1][x - 1] == 0 && arr[y][x - 2] == 0 && arr[y + 1][x - 1] == 0 && arr[y + 1][x - 2] == 0 && arr[y + 2][x - 1] == 0) return true;
    else return false;
}
bool checkeast(int y, int x)
{
    if (arr[y - 1][x + 1] == 0 && arr[y][x + 2] == 0 && arr[y + 1][x + 1] == 0 && arr[y + 1][x + 2] == 0 && arr[y + 2][x + 1] == 0) return true;
    else return false;
}
void setF(int y, int x)
{
    arr[y][x - 1] = 9;
    arr[y][x] = 8;
    arr[y][x + 1] = 9;
    arr[y-1][x] = 9;
}
void movesouth(int y, int x)
{
    arr[y][x - 1] = 0;
    arr[y][x] = 0;
    arr[y][x + 1] = 0;
    arr[y - 1][x] = 0;
    arr[y + 1][x] = 0;
    arr[y + 1][x - 1] = 9;
    arr[y + 1][x] = 8;
    arr[y + 1][x + 1] = 9;
    arr[y][x] = 9;
    arr[y + 2][x] = 9;
}
void movewest(int y, int x)
{
    arr[y][x - 1] = 0;
    arr[y][x] = 0;
    arr[y][x + 1] = 0;
    arr[y - 1][x] = 0;
    arr[y + 1][x] = 0;
    arr[y + 1][x - 2] = 9;
    arr[y + 1][x - 1] = 8;
    arr[y + 1][x] = 9;
    arr[y][x - 1] = 9;
    arr[y + 2][x - 1] = 9;
}
void moveeast(int y, int x)
{
    arr[y][x - 1] = 0;
    arr[y][x] = 0;
    arr[y][x + 1] = 0;
    arr[y - 1][x] = 0;
    arr[y + 1][x] = 0;
    arr[y + 1][x + 2] = 9;
    arr[y + 1][x + 1] = 8;
    arr[y + 1][x] = 9;
    arr[y][x + 1] = 9;
    arr[y + 2][x + 1] = 9;
}
void clearmap()
{
    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            arr[i][j] = 0;
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> r >> c >> k;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        int c1, d;//북동남서
        cin >> c1 >> d;
        int y = 0;
        c1 = c1 - 1;
        setF(y, c1);
        bool now = 0;
        while (1)
        {
            if (now == 1) break;
            if (checksouth(y, c1) == 1 && y + 2 <= r)
            {
                movesouth(y, c1);
                y += 1;
            }
            else if (checkwest(y, c1) == 1 && c1 - 2 >= 0 && y + 2 <= r)
            {
                d = (d + 3) % 4;
                movewest(y, c1);
                y += 1;
                c1 -= 1;
            }
            else if (checkeast(y, c1) == 1 && c1 + 2 < c && y + 2 <= r)
            {
                d = (d + 1) % 4;
                moveeast(y, c1);
                y += 1;
                c1 += 1;
            }
            else if (y <= 1) {
                clearmap(); now = 1;
            }
            else
            {
                now = 1;
                arr[y][c1] = 9;
                if (y == r - 1||(d == 1 && arr[y][c1 + 2] == 0 && arr[y + 1][c1 + 1] == 0)||(d==3&&arr[y][c1-2]==0&&arr[y+1][c1-1]==0)||d==0) { 
                    sum += y+1; 
                    arr[y][c1 - 1] = y + 1;
                    arr[y][c1] = y + 1;
                    arr[y][c1 + 1] = y + 1;
                    arr[y - 1][c1] = y + 1;
                    arr[y + 1][c1] = y + 1;
                }
                else
                {
                    if (d == 1)
                    {
                        int num = max(arr[y][c1 + 2], arr[y + 1][c1 + 1]);
                        num = max(num, y + 1);
                        arr[y][c1 - 1] = num;
                        arr[y][c1] = num;
                        arr[y][c1 + 1] = num;
                        arr[y - 1][c1] = num;
                        arr[y + 1][c1] = num;
                        sum += num;
                    }
                    else if (d == 2)
                    {
                        int num = max(arr[y+2][c1], arr[y + 1][c1 + 1]);
                        num = max(num, arr[y+1][c1-1]);
                        num = max(num, y + 1);
                        arr[y][c1 - 1] = num;
                        arr[y][c1] = num;
                        arr[y][c1 + 1] = num;
                        arr[y - 1][c1] = num;
                        arr[y + 1][c1] = num;
                        sum += num;
                    }
                    else if (d == 3)
                    {
                        int num = max(arr[y][c1 - 2], arr[y + 1][c1 - 1]);
                        num = max(num, y + 1);
                        arr[y][c1] = num;
                        arr[y][c1 + 1] = num;
                        arr[y - 1][c1] = num;
                        arr[y + 1][c1] = num;
                        sum += num;
                    }
                }
                
            }

        }

    }
    cout << sum;

    return 0;
}