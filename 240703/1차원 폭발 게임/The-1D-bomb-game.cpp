#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int cnt = 1;
    int si = -1;
    int ei = 0;
    if (m == 1)
    {
        cout << 0;
        return 0;
    }
    while (1)
    {
        cnt = 1;
        si = -1;
        ei = 0;
        bool ck = 0;
        for (int i = 0; i < v.size() -1; i++)
        {
            if (v[i] == v[i + 1])
            {
                cnt += 1;
                if (si == -1) si = i;
                ei = i + 2;
                if (i + 1 == v.size()-1 && cnt >= m)
                {
                    v.erase(v.begin() + si, v.end());
                }
            }
            else
            {
                if (cnt >= m)
                {
                    ck = 1;
                    v.erase(v.begin() + si, v.begin() + ei);
                    i = si - 1;
                }
                cnt = 1;
                si = -1;
                ei = 0;
            }
            if(v.size()==0) break;
        }
        if (ck == 0) break;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}