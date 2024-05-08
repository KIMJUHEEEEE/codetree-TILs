#include <iostream>
using namespace std;

int arra[1000001];
int arrb[1000001];

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
        int a;
        char b;
        cin >> a >> b;
        if (b == 'L')
        {
            for (int j = 0; j < a; j++)
            {
                sa++;
                da--;
                arra[sa] = da;
            }
        }
        else if (b == 'R')
        {
            for (int j = 0; j < a; j++)
            {
                sa++;
                da++;
                arra[sa] = da;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        if (b == 'L')
        {
            for (int j = 0; j < a; j++)
            {
                sb++;
                db--;
                arrb[sb] = db;
            }
        }
        else if (b == 'R')
        {
            for (int j = 0; j < a; j++)
            {
                sb++;
                db++;
                arrb[sb] = db;
            }
        }
    }
    int cnt = 0;
    int maxi=sa;
    if(sa<sb) maxi=sb;
    for (int i = 1; i < maxi; i++)
    {
        if (i>sa)
        {
            arra[i]=da;
        }
        else if(i>sb)
        {
            arrb[i]=db;
        }
        if ((arra[i - 1] != arrb[i - 1]) && (arra[i] == arrb[i])) 
        {
            cnt++;
            //cout<<i<<' ';
        }
    }
    cout << cnt;
    return 0;
}