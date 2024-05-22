#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int k, n;
    int arr[11][21] = { 0, };
    int price[11][22] = { 0, };
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            price[i][arr[i][j]] = j+1;
        }
    }
    int ans = 0;
    for (int i = 1; i < n ; i++)
    {
        for (int j = i + 1; j < n+1; j++)
        {
            int cntbig = 0; int cntsmall = 0;
            for (int l = 0; l < k; l++)
            {
                if (price[l][i] < price[l][j]) cntbig++;
                if (price[l][i] > price[l][j]) cntsmall++;
            }
            if (cntbig == k||cntsmall==k) ans++;
        }
    }
    cout << ans;
    return 0;
}