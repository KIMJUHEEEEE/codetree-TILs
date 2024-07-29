#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m;
int arr[21];
int ans;
vector<int> v;


int func()
{
    int sum = 0;
    string str;
    int idx = 0;
    vector<int> v2;
    v2.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        v2.push_back(v2[i - 1] ^ v[i]);
    }
    return v2[v2.size()-1];
}

void rec(int idx, int cnt)
{
    if (cnt == m)
    {
        ans = max(ans, func());
        return;
    }
    for (int i = idx; i <= n; i++)
    {
        v.push_back(i);
        rec(i+1, cnt + 1);
        v.pop_back();
    }
}
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    rec(1, 0);
    cout<<ans;
    return 0;
}