#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[21] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool ck = 0;
    sort(arr, arr + n);
    int max = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                
                int tmpc = arr[k];
                int size = arr[k];
                int s = 0;
                int tmpb = arr[j];
                int tmpa = arr[i];
                int cnt = 0;
                while (size > 0)
                {
                    s++;
                    size /= 10;
                }
                while (tmpc > 0)
                {
                    if (tmpc % 10 + tmpb % 10 + tmpa % 10 < 10)
                    {
                        cnt++;
                        tmpc /= 10;
                        tmpb /= 10;
                        tmpa /= 10;
                    }
                    else
                    {
                        break;
                    }
                }
                if (cnt == s)
                {
                    ck=1;
                    int sum = arr[i] + arr[j] + arr[k];
                    if (max < sum) max = sum;
                }

            }
        }
    }
    if (ck == 0) max = -1;
    cout << max;
    return 0;
}