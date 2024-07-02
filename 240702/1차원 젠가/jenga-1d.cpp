#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[101] = { 0, };
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[n - i];
    }
    int s, e;
    cin >> s >> e;
    for (int i = s; i <= e; i++)
    {
        arr[n-i] = 0;
    }
    for (int i = n-1; i >0; i--)
    {
        if (arr[i] != 0&&arr[i-1]==0)
        {
            arr[i-1] = arr[i];
            arr[i] = 0;
            n--;
        }
    }
    cin >> s >> e;
    for (int i = s; i <= e; i++)
    {
        arr[n-i] = 0;
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] != 0 && arr[i - 1] == 0)
        {
            arr[i - 1] = arr[i];
            arr[i] = 0;
            n--;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0) cnt++;
    }
    cout<<cnt<<endl;
    for (int i = cnt-1; i >=0; i--)
    {
        cout << arr[i] << endl;
    }
    return 0;
}