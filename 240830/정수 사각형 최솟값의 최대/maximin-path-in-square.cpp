#include <iostream>
#include <algorithm>

#define MAX_NUM 1000
#define DIR_NUM 2
#define UNUSED -1

using namespace std;

int n;
int grid[MAX_NUM][MAX_NUM];
int memo[MAX_NUM][MAX_NUM];

bool InRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

void InitializeMemo() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            memo[i][j] = UNUSED;
}

int FindMaximin(int x, int y) {
    // 미리 계산된 적이 있는 경우 해당 값을 사용해줍니다.
    if(memo[x][y] != UNUSED)
        return memo[x][y];

    // 도착 지점에 도착하면 최솟값의 최대를 갱신해줍니다.
    if( (x == n - 1) &&  (y == n - 1) )
        return memo[n - 1][n - 1] = grid[n - 1][n - 1] ;

    int dx[DIR_NUM] = {1, 0};
    int dy[DIR_NUM] = {0, 1};

    // 가능한 방향에 대해 탐색해줍니다.
    int maximin = 0;
    for(int i = 0; i < DIR_NUM; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(InRange(new_x, new_y))
            maximin = max(maximin,
                          min(FindMaximin(new_x, new_y), grid[x][y]));
    }

    // 게산된 값을 memo 배열에 저장해줍니다.
    memo[x][y] = maximin;

    return maximin;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    InitializeMemo();

    cout << FindMaximin(0, 0);

    return 0;
}