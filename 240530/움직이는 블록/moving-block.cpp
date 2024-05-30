#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[10001] = { 0, };
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int avg = sum / n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if (arr[i] == avg) break;
                if (arr[j] < avg)
                {
                    if (avg - arr[j] <= arr[i] - avg)
                    {
                        int need = avg - arr[j];
                        arr[j] = avg;
                        arr[i] = arr[i] - need;
                        ans += need;
                    }
                    else if (avg - arr[j] > arr[i] - avg)
                    {
                        int give = arr[i] - avg;
                        arr[i] = avg;
                        arr[j] += give;
                        ans += give;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}