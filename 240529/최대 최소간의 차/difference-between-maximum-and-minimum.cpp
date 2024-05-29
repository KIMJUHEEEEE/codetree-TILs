#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    int arr[101] = { 0, };
    int cnt[10001] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int ans = 0;
    int tmp[101];
    for (int i = 0; i < 10000; i++)
    {
        sort(arr, arr + n);

        copy(arr, arr + n, tmp);
        int num = i; 
        int cpcnt[10001];
        copy(cnt, cnt + 10001, cpcnt);
        while (num >= 0)
        {

            if (cpcnt[tmp[0]] <= cpcnt[tmp[n - 1]])
            {
                int a = cpcnt[tmp[0]];
                cpcnt[tmp[0]] = 0;
                for (int j = 0; j < a; j++)
                {
                    tmp[j] += 1;
                    cpcnt[tmp[j]]++;
                    num--;
                    if (num < 0) break;
                }
                //sort(arr,arr+n);
            }
            else {
                int a = cpcnt[tmp[n - 1]];
                cpcnt[tmp[n - 1]] = 0;
                for (int j = 0; j < a; j++)
                {
                    tmp[n - 1 - j] -= 1;
                    cpcnt[tmp[n - 1 - j]]++;
                    num--;
                    if (num < 0) break;
                }
            }
        }
        sort(tmp, tmp + n);
        if (tmp[n - 1] - tmp[0] <= k)
        {
            ans = i+1;
            break;
        }
    }
    cout << ans;
    return 0;
}