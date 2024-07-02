#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[101] = { 0, };
    int cparr[101]={0,};
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[n - i];
    }
    int s, e;
    cin >> s >> e;
    for (int i = s; i <= e; i++)
    {
        arr[n - i] = 0;
    }
    int a=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            cparr[a]=arr[i];
            a++;
        }
    }
    arr[101]={0,};
    cin >> s >> e;
    n = a;
    for (int i = s; i <= e; i++)
    {
        cparr[n - i] = 0;
    }
    arr[101]={0,};
    int b=0;
    for(int i=0;i<a;i++)
    {
        if(cparr[i]!=0)
        {
            arr[b]=cparr[i];
            b++;
        }
    }
    cout << b << endl;
    for (int i = b - 1; i >= 0; i--)
    {
        cout << arr[i] << endl;
    }
    return 0;
}