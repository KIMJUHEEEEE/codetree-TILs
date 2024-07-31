#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int n, m;
vector<pair<int, int>> v;
vector<int> num;
float ans = INT_MAX;
void rec(int idx)
{
    if (idx == m)
    {
        float maxdis = 0;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                float dist = 0;
                dist = sqrt((v[num[i]].first - v[num[j]].first) * (v[num[i]].first - v[num[j]].first) + (v[num[i]].second - v[num[j]].second) * (v[num[i]].second - v[num[j]].second));
                maxdis = max(maxdis, dist);
            }
        }
        ans = min(ans, maxdis);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (num.size() > 0)
        {
            if (num[num.size() - 1] >= i) continue;
        }
        num.push_back(i);
        rec(idx + 1);
        num.pop_back();

    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    rec(0);
    cout << ans * ans;
    return 0;
}