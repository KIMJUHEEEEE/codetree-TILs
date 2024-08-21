#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[1001]={0,};
    arr[1]=1;
    arr[2]=3;
    for(int i=3;i<=n;i++)
    {
        arr[i]=arr[i-1]%10007+2*arr[i-2]%10007;
    }
    cout<<arr[n]%10007;
    return 0;
}