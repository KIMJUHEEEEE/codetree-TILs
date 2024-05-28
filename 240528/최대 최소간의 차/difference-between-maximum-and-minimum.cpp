#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    int arr[101] = { 0, };
    int cnt[101] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int ans = 0;
    while (1)
    {
        sort(arr, arr + n);
        if (arr[n-1] - arr[0] <= k)
        {
            break;
        }
        else
        {
            int maxi = cnt[arr[n - 1]];
            int mini = cnt[arr[0]];
            if (mini <= maxi)
            {
                for (int j = 0; j < mini; j++)
                {
                    arr[j] += 1; ans++;
                }
            }
            else
            {
                for (int j = 0; j < maxi; j++)
                {
                    arr[n - 1] -= 1; ans++;
                }
            }

        }
    }
    cout << ans;
    return 0;
}