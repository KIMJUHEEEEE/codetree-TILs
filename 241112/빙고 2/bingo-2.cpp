#include <iostream>
using namespace std;
int arr[5][5] = { 0, };
int number[25] = { 0, };
int dx[4] = { 1,0,1,-1 };
int dy[4] = { 0,1,1,-1 };

bool bingo()
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i][0] == 0)
        {
            int n = 0;
            for (int j = 0; j < 5; j++)
            {
                if (arr[i][j] == 0) n++;
            }
            if (n == 5) cnt++;
        }
    }
    for (int j = 0; j < 5; j++)
    {
        if (arr[0][j] == 0)
        {
            int n = 0;
            for (int i = 0; i < 5; i++)
            {
                if (arr[i][j] == 0) n++;
            }
            if (n == 5) cnt++;
        }
    }
    if (arr[0][0] == 0)
    {
        int n = 0;
        for (int i = 0; i < 5; i++)
        {
            if (arr[i][i] == 0) n++;
        }
        if (n == 5) cnt++;
    }
    if (arr[0][4] == 0)
    {
        int n = 0;
        for (int i = 0; i < 5; i++)
        {
            if (arr[i][4 - i] == 0) n++;
        }
        if (n == 5) cnt++;
    }

    if (cnt == 3) return true;
    else return false;
}

void check(int n)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == n)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 25; i++)
    {
        cin >> number[i];
        check(number[i]);
        if (i < 12) continue;
        if (bingo() == true)
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans;
    return 0;
}