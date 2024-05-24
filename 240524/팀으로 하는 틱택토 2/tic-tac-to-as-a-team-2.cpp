#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    char arr[3][3] = { 0, };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        int cnt[10] = { 0, };
        for (int j = 0; j < 3; j++)
        {
            cnt[arr[i][j]-48]++;
        }
        int num = 0;
        for (int j = 0; j < 10; j++)
        {
            if (cnt[j] > 0) num++;
        }
        if (num == 2) ans++;
    }
    for (int i = 0; i < 3; i++)
    {
        int cnt[10] = { 0, };
        for (int j = 0; j < 3; j++)
        {
            cnt[arr[j][i]-48]++;
        }
        int num = 0;
        for (int j = 0; j < 10; j++)
        {
            if (cnt[j] > 0) num++;
        }
        if (num == 2) ans++;
    }
    int cnt[10] = { 0, };
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        cnt[arr[i][i]-48]++;
    }
    for (int j = 0; j < 10; j++)
    {
        if (cnt[j] > 0) num++;
    }
    if (num == 2) ans++;
    int cnt2[10] = { 0, };
    num = 0;
    for (int i = 0; i < 3; i++)
    {
        cnt2[arr[i][2 - i]-48]++;
    }
    for (int j = 0; j < 10; j++)
    {
        if (cnt2[j] > 0) num++;
    }
    if (num == 2) ans++;
    cout << ans;
    return 0;
}