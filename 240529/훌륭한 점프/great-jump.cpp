#include <iostream>
using namespace std;

int IsPossible(int arr[], int a, int n, int k)
{
    int available_indices[101] = { 0, };
    int cnt = 0;
    int maxi=0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= a)
        {
            available_indices[cnt++] = i;
            maxi = max(maxi, arr[i]);
        }
    if (cnt == 1) return 101;
    for (int i = 1; i < cnt; i++) {
        int dist = available_indices[i] - available_indices[i - 1];
        if (dist > k)
            return 101;
    }

    return maxi;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    int arr[101] = { 0, };
    int maxnum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxnum=max(maxnum, arr[i]);
    }
    int ans = 101;
    for (int i = maxnum; i >=1;i--)
    {
        int num=IsPossible(arr,i,n,k);
        ans = min(ans,num );
    }
    cout << ans;
    return 0;
}