#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[21][21];
vector<pair<int, int>> v;
vector<int> vv;
int ans;
void rec(int idx) {
    if (vv.size() == v.size())
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != 0) cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        vv.push_back(i);
        if (i == 0)
        {
            int x = v[idx].first;
            int y = v[idx].second;
            if(arr[y-2][x]==0&&y-2>=0) arr[y - 2][x] = i+1;
            if(arr[y-1][x]==0&&y-1>=0) arr[y - 1][x] = i+1;
            if(arr[y+1][x]==0&&y+1<n) arr[y + 1][x] = i+1;
            if(arr[y+2][x]==0&&y+2<n) arr[y + 2][x] = i+1;
        }
        else if (i == 1)
        {
            int x = v[idx].first;
            int y = v[idx].second;
            if(arr[y-1][x]==0&&y-1>=0) arr[y - 1][x] = i+1;
            if(arr[y][x-1]==0&&x-1>=0) arr[y][x - 1] = i+1;
            if(arr[y][x+1]==0&&x+1<n) arr[y][x + 1] = i+1;
            if(arr[y+1][x]==0&&y+1<n) arr[y + 1][x] = i+1;
        }
        else if (i == 2)
        {
            int x = v[idx].first;
            int y = v[idx].second;
            if(arr[y-1][x-1]==0&&x-1>=0&&y-1>=0) arr[y - 1][x - 1] = i+1;
            if(arr[y-1][x+1]==0&&y-1>=0&&x+1<n) arr[y - 1][x + 1] = i+1;
            if(arr[y+1][x-1]==0&&y+1<n&&x-1>=0) arr[y + 1][x - 1] = i+1;
            if(arr[y+1][x+1]==0&&y+1<n&&x+1<n) arr[y + 1][x + 1] = i+1;
        }
        rec(idx+1);
        vv.pop_back();
        if (i == 0)
        {
            int x = v[idx].first;
            int y = v[idx].second;
            if(arr[y - 2][x] == 1 && y - 2 >= 0) arr[y - 2][x] = 0;
            if (arr[y - 1][x] == 1 && y - 1 >= 0) arr[y - 1][x] = 0;
            if (arr[y + 1][x] == 1 && y + 1 < n) arr[y + 1][x] = 0;
            if (arr[y + 2][x] == 1 && y + 2 < n) arr[y + 2][x] = 0;
        }
        else if (i == 1)
        {
            int x = v[idx].first;
            int y = v[idx].second;
            if (arr[y - 1][x] == 2 && y - 1 >= 0) arr[y - 1][x] = 0;
            if (arr[y][x - 1] == 2 && x - 1 >= 0) arr[y][x - 1] = 0;
            if (arr[y][x + 1] == 2 && x + 1 < n) arr[y][x + 1] = 0;
            if (arr[y + 1][x] == 2 && y + 1 < n) arr[y + 1][x] = 0;
        }
        else if (i == 2)
        {
            int x = v[idx].first;
            int y = v[idx].second;
            if (arr[y - 1][x - 1] == 3 && x - 1 >= 0 && y - 1 >= 0) arr[y - 1][x - 1] = 0;
            if (arr[y - 1][x + 1] == 3 && y - 1 >= 0 && x + 1 < n) arr[y - 1][x + 1] = 0;
            if (arr[y + 1][x - 1] == 3 && y + 1 < n && x - 1 >= 0) arr[y + 1][x - 1] = 0;
            if (arr[y + 1][x + 1] == 3 && y + 1 < n && x + 1 < n) arr[y + 1][x + 1] = 0;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                v.push_back(make_pair(i, j));
                arr[i][j] = 4;
            }
        }
    }
    rec(0);
    cout << ans;
    return 0;
}