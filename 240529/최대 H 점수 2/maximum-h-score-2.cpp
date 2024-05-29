#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, l;
    cin >> n >> l;
    int arr[101] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;

    for (int i = 0; i < 100; i++)//H
    {
        bool ck = 0;
        int tmp[101];
        copy(arr, arr + n, tmp);
        for (int j = 0; j < n; j++)//배열
        {
            copy(arr, arr + n, tmp);
            if (tmp[j] >= i-1)
            {
                if (l > 0)
                {
                    if (tmp[j] >= i)
                    {
                        for (int k = 1; k <= l; k++)
                        {
                            if (j - k > 0)
                            {
                                tmp[j - k] += 1;
                            }
                        }
                    }
                    if (tmp[j] == i - 1)
                    {
                        for (int k = 0; k < l; k++)
                        {
                            if (j - k > 0)
                            {
                                tmp[j - k] += 1;
                            }
                        }
                    }
                }
                sort(tmp, tmp + n);
                for (int k = 0; k < n; k++)
                {
                    if (tmp[k] >= i && n - k >= i)
                    {
                        ans = i;
                        ck = 1;
                        break;
                    }
                }
            }
            if (ck == 1) break;
        }
        if (ans < i) break;
        
    }
    cout << ans;
    return 0;
}