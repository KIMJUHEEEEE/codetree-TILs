#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arra[101] = { 0, };
    int arrb[101] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arra[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arrb[i];
    }
    int ans = 0;
    int tmp[101];
        copy(arra, arra + n, tmp);
    for (int i = n - 1; i > 0; i--)
    {

        for (int j = i - 1; j >= 0; j--)
        {
            if (tmp[i] == arrb[i]) break;
            else if (arrb[i] > tmp[i])
            {
                int n = arrb[i] - tmp[i];
                int num = tmp[j];
                
                if (num <= n)
                {
                    tmp[i] += tmp[j];
                    ans += tmp[j] * (i - j);
                    tmp[j] = 0;
                }
                else
                {
                    tmp[i] += n;
                    ans += n * (i - j);
                    tmp[j] -= n;
                }

            }
        }
    }
    cout << ans;
    return 0;
}