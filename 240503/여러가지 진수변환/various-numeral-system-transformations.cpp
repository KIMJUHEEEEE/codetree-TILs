#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,b;
    cin>>n>>b;
    int arr[101]={0,};
    int cnt=0;
    while(n>=1)
    {
        arr[cnt]=n%b;
        n/=b;
        if(n==0) break;
        cnt++;
    }
    for(int i=cnt;i>=0;i--)
    {
        cout<<arr[i];
    }
    return 0;
}