#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[21][21] = { 0, };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int max = 0;
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-2; j++)
        {
            bool arrb[21][21] = { 0, };
            int cnt = 0;
            for (int k = 0; k < 3; k++)
            {
                arrb[i][j + k] = 1;
                if (arr[i][j + k] == 1 && j + k < n)
                {
                    cnt++;
                }
            }
            //cout << "cnt"<<i<<' '<<j<<' '<<cnt << endl;
            int maxb = 0;
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < n-2; b++)
                {
                    int cntb = 0;
                    if (arrb[a][b] == 0)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (arr[a][b + k] == 1 && b + k < n)
                            {
                                cntb++;
                            }
                        }
                    }
                    //cout <<"cntb"<< a<<' ' << b<<' ' << cntb << endl;
                    if (maxb < cntb) maxb = cntb;
                }
            }
            arrb[21][21] = { 0, };
            if (cnt+maxb > max) max = cnt + maxb;
        }
    }
    cout << max;
    return 0;
}