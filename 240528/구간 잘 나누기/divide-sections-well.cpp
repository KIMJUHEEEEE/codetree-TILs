#include <iostream>
using namespace std;
int arr[102] = { 0, };
int sum[102] = { 0, };
int n;
int mini=99999;

void find(int pidx, int i, int cnt, int m,  int max)
{
    if (pidx > n||i>n) return;
    if (cnt == m)
    {
       int num = sum[n] - sum[pidx] ;
       if (num > max) max = num;
       if (max < mini) mini = max;
       return;
    }
    
    for (int j = 0; j < n; j++)
    {
        int previdx = pidx;
        int num = sum[i + j] - sum[previdx];
        if (num > max) max = num;
        previdx = i + j;
        if (previdx > n||i+j>n) return;
        find(previdx, i + j+1, cnt + 1, m, max);
        previdx = pidx;
    }
    
}


int main() {
    int m;
    cin >> n >> m;

    int arrmax = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arrmax < arr[i]) arrmax = arr[i];
        if (i == 0) sum[i] = arr[i];
        else
        {
            sum[i] = arr[i] + sum[i - 1];
        }
    }
    int ans = 99999999;
    int i = 0;
    find(i, i+1, 0, m - 1, 0);
    cout << mini;
    // 여기에 코드를 작성해주세요.
    return 0;
}