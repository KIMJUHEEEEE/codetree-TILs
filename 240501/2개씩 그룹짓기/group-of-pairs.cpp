#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n = 0;
    cin >> n;
    int arr[2001] = { 0, };
    for (int i = 0; i < 2* n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + 2*n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i] + arr[2 * n - i-1]) max = arr[i] + arr[2 * n - i-1];
    }
    cout << max;
    return 0;
}