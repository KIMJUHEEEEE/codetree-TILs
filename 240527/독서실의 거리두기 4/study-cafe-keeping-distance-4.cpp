#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    string arr;
    cin >> arr;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        string tmp = arr;
        if (tmp[i] == '0')
        {
            tmp[i] = '1';
            for (int j = i + 1; j < n; j++)
            {
                if (tmp[j] == '0')
                {
                    tmp[j] = '1';

                    int min = 9999;
                    for (int a = 0; a < n - 1; a++)
                    {
                        for (int b = a + 1; b < n; b++)
                        {
                            if (b - a > min) break;
                            if (tmp[a] == '1' && tmp[b] == '1')
                            {
                                if (min > b - a) min = b - a;
                            }
                        }
                    }
                    if (ans < min) ans = min;
                    tmp[j] = '0';
                }
            }
            tmp[i] = '0';
        }
    }
    cout << ans;
    return 0;
}