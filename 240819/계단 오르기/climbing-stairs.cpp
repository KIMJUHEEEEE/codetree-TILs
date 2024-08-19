#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[1001]={0,};
    arr[2]=1;
    arr[3]=1;
    for(int i=4;i<=n;i++)
    {
        arr[i]=arr[i-2]%10007+arr[i-3]%10007;
    }
    cout<<arr[n]%10007;
    return 0;
}