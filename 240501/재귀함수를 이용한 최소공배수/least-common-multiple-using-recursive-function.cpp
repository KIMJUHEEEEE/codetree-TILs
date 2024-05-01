#include <iostream>
using namespace std;
int f(int arr[], int c[], int i, int n)
{
    if (i == n) return 1;
    int tmp = arr[i];
    for (int a = 2; a <= tmp; a++)
    {int cnt = 0;
        while (1) {
            
            if (tmp % a == 0)
            {
                cnt++;
                tmp /= a;
            }
            else {
                if (cnt > c[a]) c[a] = cnt;
                break;
            }
        }
    }
    return f(arr, c, i + 1, n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n = 0;
    cin >> n;
    int arr[11] = { 0, };
    int cnt[11] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    f(arr, cnt, 0, n);
    int ans = 1;
    for (int i = 0; i < 11; i++)
    {
        if (cnt[i] > 0)
        {
            while(cnt[i]--)
            {
                ans*=i;
            }
        }
    }
    cout << ans;
    return 0;
}