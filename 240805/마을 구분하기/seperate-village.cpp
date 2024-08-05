#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[26][26];
bool ck[26][26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> popularity;

bool check(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] == n || x + dy[i] == n) continue;
        if (arr[y + dy[i]][x + dx[i]] == 1 && ck[y + dy[i]][x + dx[i]] == 0) return true;
    }
    return false;
}

void dfs(int x, int y)
{
    if (check(x, y) == false)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (arr[y + dy[i]][x + dx[i]] == 1 && ck[y + dy[i]][x + dx[i]] == 0)
        {
            ck[y + dy[i]][x + dx[i]] = 1;
            dfs(x + dx[i], y + dy[i]);
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
        }
    }
    int town = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && ck[i][j] == 0)
            {
                ck[i][j] = 1;
                dfs(j, i);
                int maxi = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (ck[i][j] == 1)
                        {
                            ck[i][j] = 0;
                            arr[i][j] = 0;
                            maxi++;
                        }
                    }
                }
                popularity.push_back(maxi);
                town++;
            }
        }
    }
    sort(popularity.begin(), popularity.end());
    cout << town << endl;
    for (int i = 0; i < popularity.size(); i++)
    {
        cout << popularity[i] << endl;
    }
    return 0;
}