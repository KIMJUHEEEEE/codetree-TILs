#include <iostream>
using namespace std;
int arr[2001][2001];

int main() {
    // 여기에 코드를 작성해주세요.

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            arr[i + 1000][j + 1000] = 1;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            arr[i + 1000][j + 1000] = 0;
        }
    }
    int maxw = 0;
    int maxh = 0;
    for (int i = 0; i < 2001; i++)
    {
        int mw = 0;
        int mh = 0;
        for (int j = 0; j < 2001; j++)
        {
            if (arr[i][j] == 1)
            {
                int tmpi = i;
                int tmpj = j;
                while (arr[tmpi][j] == 1)
                {
                    tmpi++;
                    mh++;
                }
                while (arr[i][tmpj] == 1)
                {
                    tmpj++;
                    mw++;
                }
                if (maxw < mw) maxw = mw;
                if (maxh < mh) maxh = mh;
                mw = 0;
                mh = 0;
            }
        }
    }
    cout << (maxw-1) * (maxh-1);
    return 0;
}