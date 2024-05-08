#include <iostream>
using namespace std;
int arr[1001];

int main() {
    // 여기에 코드를 작성해주세요.
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cnt;
    if(arr[0]>t) cnt=1;
    else cnt=0;
    int max=cnt;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>t)
        {
            cnt++;
            if(max<cnt) max=cnt;
        }
        else cnt=0;
    }
    cout<<max;
    return 0;
}