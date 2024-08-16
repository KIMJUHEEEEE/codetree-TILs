#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[46]={0,};
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<46;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    int n;
    cin>>n;
    cout<<arr[n-1];
    return 0;
}