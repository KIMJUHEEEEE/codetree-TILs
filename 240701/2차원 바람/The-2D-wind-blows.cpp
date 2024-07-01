#include <iostream>
using namespace std;
int arr[101][101] = { 0, };
int cparr[101][101] = { 0, };
int n, m, q;
void rotate(int r1, int c1, int r2, int c2)
{
    int tmp = arr[r1][c1];
    for (int i = r1; i < r2; i++)
    {
        arr[i][c1] = arr[i+1][c1];
    }
    for (int i = c1; i <= c2; i++)
    {
        arr[r2][i] = arr[r2][i + 1];
    }
    for (int i = r2; i > r1; i--)
    {
        arr[i][c2] = arr[i - 1][c2];
    }
    for (int i = c2; i > c1; i--)
    {
        arr[r1][i] = arr[r1][i - 1];
    }
    arr[r1][c1 + 1] = tmp;
}

void average(int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cparr[i][j] = arr[i][j];
        }
    }
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            int cnt = 1;
            int sum = arr[i][j];
            if (i - 1 >= 0)
            {
                sum += arr[i - 1][j];
                cnt++;
            }
            if (i + 1 < n)
            {
                sum += arr[i + 1][j];
                cnt++;
            }
            if (j - 1 >= 0)
            {
                sum += arr[i][j - 1];
                cnt++;
            }
            if (j + 1 < m)
            {
                sum += arr[i][j + 1];
                cnt++;
            }
            cparr[i][j] = sum / cnt;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = cparr[i][j];
        }
    }
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
    for (int i = 0; i < q; i++)
    {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        rotate(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
        average(r1 - 1, c1 - 1, r2 - 1, c2 - 1);

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