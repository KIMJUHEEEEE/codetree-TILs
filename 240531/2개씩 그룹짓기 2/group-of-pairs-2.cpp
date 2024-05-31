#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[200001] = { 0, };
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + 2*n);
    int maxi = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int dis = arr[2*n - i-1] - arr[n-i-1];
        maxi = min(maxi, dis);
    }
    cout << maxi;
    return 0;
}