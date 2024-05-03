#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    int arr[10]={0,};
    int cnt=0;
    while(n>=1)
    {
        arr[cnt]=n%2;
        if(n==1) break;
        n/=2;
        cnt++;
    }
    for(int i=cnt;i>=0;i--)
    {
        cout<<arr[i];
    }
    return 0;
}