#include <iostream>
#include <vector>
int n, m, k;
using namespace std;
int arr[12];
int ans;
vector<int> v;
int score[5];
void rec(int idx)
{
    if (idx == n)
    {
        int cnt = 0;
        for (int i = 1; i < 5; i++)
        {
            if (score[i] >= m-1) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        v.push_back(i);
        score[i] += arr[idx];
        rec(idx + 1);
        v.pop_back();
        score[i] -= arr[idx];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rec(0);
    cout << ans;
    return 0;
}