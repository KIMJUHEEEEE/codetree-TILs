#include <iostream>
using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[101] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            for (int k = i; k <= j; k++)
            {
                if (sum / (j - i) == arr[k] && sum % (j - i) == 0)
                {
                    ans++; break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}