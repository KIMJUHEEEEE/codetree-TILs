#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
vector<int> vv;
int ans = 0;

bool cmp(pair<int, int>v, pair<int, int>v1)
{
    if (v.first == v1.first)
    {
        return v.second < v1.second;
    }
    return v.first < v1.first;
}

void rec(int idx)
{
    int a = vv.size() - 1;
    if (a >= 1 && v[vv[a - 1]].second >= v[vv[a]].first)
    {
        return;
    }
    if (idx <= v.size())
    {
        ans = max(ans, (int)vv.size());
    }
    for (int i = idx; i < v.size(); i++)
    {
        vv.push_back(i);
        rec(idx+1);
        vv.pop_back();
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), cmp);
    rec(0);
    cout << ans;
    return 0;
}