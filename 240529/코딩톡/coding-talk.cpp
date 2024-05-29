#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, p, u, m;
    char c;
    cin >> n >> m >> p;
    bool ck[26] = { 0, };
    char person[101] = { 0, };
    int num[101] = { 0, };
    for (int i = 1; i <= m; i++)
    {
        cin >> c >> u;
        person[i] = c;
        num[i] = u;
        if (i >= p)
        {
            ck[int(c) - 65] = 1;
        }
    }
    for(int i=1;i<m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            if(num[i]==num[j]&&num[i]==num[p])
            {
                ck[int(person[i])-65]=1;
                ck[int(person[j])-65]=1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ck[i] == 0)
        {
            cout << char(i + 'A') << ' ';
        }
    }
    return 0;
}