#include <iostream>
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    int arr[101][101] = { 0, };
    int cnt = 1;
    int x = 0;
    int y = 0;
    int dir = 0;
    arr[x][y] = cnt;
    cnt++;
    while (cnt <= n * m)
    {
        
        if (x + dx[dir] == n || y + dy[dir] == m || x + dx[dir] < 0 || y + dy[dir] < 0 || arr[x + dx[dir]][y + dy[dir]] != 0)
        {
            dir = (dir + 1) % 4;
        }
        
        x += dx[dir];
        y += dy[dir];
        arr[x][y] = cnt;
        cnt++;
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