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
    int ck[9][2] = { 0, };

    for (int i = 0; i < 3; i++)
    {
        int cnt[10] = { 0, };
        for (int j = 0; j < 3; j++)
        {
            cnt[arr[i][j]-48]++;
        }
        int num = 0;
        int a = 0;
        int b = 0;
        for (int j = 0; j < 10; j++)
        {
            if (cnt[j] > 0)
            {
                num++;
                if (a == 0) a = j;
                else b = j;
            }
        }
        if (num == 2)
        {
            bool check = 0;
            for (int j = 0; j < 9; j++)
            {
                if (ck[j][0] == a && ck[j][1] == b) check = 1;
            }
            if (check == 0)
            {
                ans++;
                ck[ans][0] = a;
                ck[ans][1] = b;
            }
        }
    } 
    for (int i = 0; i < 3; i++)
    {

        int cnt[10] = { 0, };
        for (int j = 0; j < 3; j++)
        {
            cnt[arr[j][i]-48]++;
        }
        int num = 0;
        int a = 0;
        int b = 0;
        for (int j = 0; j < 10; j++)
        {
            if (cnt[j] > 0)
            {
                num++;
                if (a == 0) a = j;
                else b = j;
            }
        }
        if (num == 2)
        {
            bool check = 0;
            for (int j = 0; j < 9; j++)
            {
                if (ck[j][0] == a && ck[j][1] == b) check = 1;
            }
            if (check == 0)
            {
                ans++;
                ck[ans][0] = a;
                ck[ans][1] = b;
            }
        }
    }
    int cnt[10] = { 0, };
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        cnt[arr[i][i]-48]++;
    }
    int a = 0;
    int b = 0;
    for (int j = 0; j < 10; j++)
    {
        if (cnt[j] > 0)
        {
            num++;
            if (a == 0) a = j;
            else b = j;
        }
    }
    if (num == 2)
    {
        bool check = 0;
        for (int j = 0; j < 9; j++)
        {
            if (ck[j][0] == a && ck[j][1] == b) check = 1;
        }
        if (check == 0)
        {
            ans++;
            ck[ans][0] = a;
            ck[ans][1] = b;
        }
    }
    int cnt2[10] = { 0, };
    num = 0;
    for (int i = 0; i < 3; i++)
    {
        cnt2[arr[i][2 - i]-48]++;
    }
    a = 0;
    b = 0;
    for (int j = 0; j < 10; j++)
    {
        if (cnt[j] > 0)
        {
            num++;
            if (a == 0) a = j;
            else b = j;
        }
    }
    if (num == 2)
    {
        bool check = 0;
        for (int j = 0; j < 9; j++)
        {
            if (ck[j][0] == a && ck[j][1] == b) check = 1;
        }
        if (check == 0)
        {
            ans++;
            ck[ans][0] = a;
            ck[ans][1] = b;
        }
    }
    cout << ans;
    return 0;
}