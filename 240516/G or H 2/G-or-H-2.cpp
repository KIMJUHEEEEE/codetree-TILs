#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n = 0;
    cin >> n;
    char arr[101] = { 0, };
    int maxidx = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        arr[a] = b;
        if (a > maxidx) maxidx = a;
    }
    char b;

    int ans = 0;
    for (int i = 0; i <= maxidx; i++)
    {
        int cnth = 0;
        int cntg = 0;
        int len = 0;
        if (arr[i] != 0)
        {
            if (arr[i] == 'H') cnth++;
            else if (arr[i] == 'G') cntg++;
            for (int j = i + 1; j <= maxidx; j++)
            {
                bool ck = 0;
                if (arr[j] == 'H') { cnth++; ck = 1; }
                else if (arr[j] == 'G') {
                    cntg++; ck = 1;
                }
                if (cnth == 0 || cntg == 0 || cntg == cnth&&ck==1)
                {
                    len = j - i;
                    if (ans < len) ans = len;
                }
            }
        }

    }
    cout << ans;
    return 0;
}