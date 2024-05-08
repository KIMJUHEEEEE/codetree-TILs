#include <iostream>
using namespace std;
int arra[1001];
int arrb[1001];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    int da = 0;
    int db = 0;
    int sa = 0;
    int sb = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        int s;
        cin >> c >> s;
        if (c == 'R')
        {
            for (int j = 0; j < s; j++)
            {
                da++;
                sa++;
                arra[sa] = da;
            }
        }
        else if (c == 'L')
        {
            for (int j = 0; j < s; j++)
            {
                da--;
                sa++;
                arra[sa] = da;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        char c;
        int s;
        cin >> c >> s;
        if (c == 'R')
        {
            for (int j = 0; j < s; j++)
            {
                db++;
                sb++;
                arrb[sb] = db;
            }
        }
        else if (c == 'L')
        {
            for (int j = 0; j < s; j++)
            {
                db--;
                sb++;
                arrb[sb] = db;
            }
        }
    }
    for (int i = 1; i < 1001; i++)
    {
        if(i>sb||i>sa) break;
        if (arra[i] == arrb[i])
        {
            cout << i; return 0;
        }
        
    }
    cout<<-1;
    return 0;
}