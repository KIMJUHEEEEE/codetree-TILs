#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[12][12];
int cparr[12][12];
int ans=15;
int n, m;
vector<pair<int, int>> line;
vector<pair<int, int>> made;
bool check()
{
    int n1[12], n2[12];
    for (int i = 0; i < n; i++)
    {
        n1[i] = i;
        n2[i] = i;
    }
    for (int i = 0; i < line.size(); i++)
    {
        int idx = line[i].second;
        swap(n1[idx], n1[idx + 1]);
    }
    for (int i = 0; i < made.size(); i++)
    {
        int idx = made[i].second;
        swap(n2[idx], n2[idx + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        if (n1[i] != n2[i]) return false;
    }
    return true;
}

void rec(int idx)
{
    if (idx == m)
    {
        if (check())
        {
            ans = min(ans, (int)made.size());
        }
        return;
    }
    made.push_back(line[idx]);
    rec(idx + 1);
    made.pop_back();
    rec(idx + 1);
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;
    ans = m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        line.push_back(make_pair(b, a - 1));
    }
    sort(line.begin(), line.end());
    rec(0);
    cout << ans;
    return 0;
}