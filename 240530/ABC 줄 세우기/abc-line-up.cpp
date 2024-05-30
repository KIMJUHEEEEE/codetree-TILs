#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    char arr[27] = { 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)//알파벳 순서 탐색
    {
        for (int j = 0; j < n; j++) //배열 탐색
        {
            if (arr[j] == char('A' + i))
            {
                if (i == j) break;
                else if (j > i)
                {
                    while (1)
                    {
                        int tmp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = tmp;
                        cnt++;
                        j--;
                        if (arr[i] == char('A' + i)) break;
                    }
                }
                else if (i > j)
                {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                    cnt++;
                    j++;
                    if (arr[i] == char('A' + i)) break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}