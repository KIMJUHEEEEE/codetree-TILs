#include <iostream>
using namespace std;
int arr[1001];

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cnt=1;
    int max=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        { 
            cnt++;
            if(max<cnt) max=cnt;
        }
        else cnt=1;
    }
    cout<<max;
    return 0;
}