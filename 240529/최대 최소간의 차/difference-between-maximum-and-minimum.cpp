#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 100
#define MAX_NUM 10000
#define MIN_NUM 1

using namespace std;

int n, k;
int arr[MAX_N];

int main() {
    cin >> n >> k;

    int max_num = MIN_NUM;
    int min_num = MAX_NUM;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_num = max(arr[i], max_num);
        min_num = min(arr[i], min_num);

    }

    int min_ans = INT_MAX;

    for (int l = min_num; l <= max_num; l++) {
        int r = l + k;
        if (r - l <= k && r - l >= 0) {
            int cost = 0;
            for (int i = 0; i < n; i++) {
                if (l >= arr[i] || arr[i] >= r)
                    cost += min(abs(l - arr[i]), abs(arr[i] - r));
            }
            min_ans = min(min_ans, cost);
        }
    }

    cout << min_ans;

    return 0;
}