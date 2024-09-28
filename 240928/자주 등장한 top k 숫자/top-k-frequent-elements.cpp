#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class number {
public:
    int k;
    int v;
    number(int key, int value) { k = key; v = value; }
};
vector<number> va;


bool cmp(number m1, number m2)
{
    if (m1.v > m2.v) return true;
    if (m1.v == m2.v)
    {
        if (m1.k > m2.k) return true;
        else return false;
    }
    else return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, K;
    cin >> n >> K;
    unordered_map<int, int> ma;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        if (ma.find(a) == ma.end())
        {
            ma.insert({ a, 1 });
            va.push_back(number(a, 1));
        }
        else
        {
            ma[a]++;
            for (int j = 0; j < va.size(); j++)
            {
                if (va[j].k == a)
                {
                    va[j].v++;
                    break;
                }
            }
        }
    }
        sort(va.begin(), va.end(), cmp);
        for (int i = 0; i < K; i++)
        {
            cout << va[i].k<<' ';
        }
    
    return 0;
}