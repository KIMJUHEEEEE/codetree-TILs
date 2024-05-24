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
    string tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = arr;
        int min = 0;
        if (tmp[i] == '0')
        {
            min = 999;
            tmp[i] = '1';
            for (int j = 0; j < n - 1; j++)
            {

                for (int k = j + 1; k < n; k++)
                {
                    int dis = 0;
                    if (abs(k - j) > min) break;
                    if (tmp[j] == '1' && tmp[k] == '1')
                    {
                        dis = abs(k - j);
                        if (dis < min) {
                            min = dis; break;
                        }
                    }
                }
            }
        }
        if (ans < min)
        {
            ans = min;
        }
    }

    cout << ans;
    return 0;
}