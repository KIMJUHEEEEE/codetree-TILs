#include <iostream>
#include <vector>
using namespace std;
int k, n;
vector<int> v;
bool possible()
{
    if (v.size() >= 3)
    {
        for (int i = 0; i <= v.size() - 3; i++)
        {
            if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) return false;
        }
    }
    return true;
}

void rec(int idx)
{
    if (idx == n)
    {
        if (possible())
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        v.push_back(i);
        rec(idx + 1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k >> n;
    rec(0);

    return 0;
}