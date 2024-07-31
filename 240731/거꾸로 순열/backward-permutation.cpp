#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
bool ck[9];
void rec(int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = n; i >=1; i--)
    {
        if (ck[i] == 0)
        {
            v.push_back(i);
            ck[i] = 1;
            rec(idx + 1);
            v.pop_back();
            ck[i] = 0;
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    rec(0);
    return 0;
}