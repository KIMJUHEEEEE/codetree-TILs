#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class rect {
public:
    int lx;
    int ly;
    int rx;
    int ry;
    int sum;
    rect(int lx, int ly, int rx, int ry, int sum)
    {
        this->lx = lx;
        this->ly = ly;
        this->rx = rx;
        this->ry = ry;
        this->sum = sum;
    }
};

bool cmp(rect a, rect b) {
    return a.sum > b.sum;
}
int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    int arr[6][6] = { 0, };
    vector<rect> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            for (int x = 0; x < n - i; x++)
            {
                for (int y = 0; y < m - j; y++)
                {
                    int a = x;
                    int b = y;
                    int sum = 0;
                    for (int c = 0; c <= a; c++)
                    {
                        for (int d = 0; d <= b; d++)
                        {
                            sum += arr[i + c][j + d];
                        }
                    }
                    v.push_back(rect(j, i, j + b, i + a, sum));
                }
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    int ans = INT_MIN;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i].rx < v[j].lx || v[i].ry < v[j].ly || v[j].rx < v[i].lx || v[j].ry < v[i].ly)
            {
                ans = max(ans, v[i].sum + v[j].sum);
            }
        }
    }
    cout << ans;
    return 0;
}