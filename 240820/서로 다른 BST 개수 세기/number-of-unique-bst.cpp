#include <iostream>
using namespace std;
int arr[20];
int n;


int main() {
    // 여기에 코드를 작성해주세요.

    cin>>n;
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    arr[3]=5;
    for(int i=4;i<=n;i++)
    {
        for(int a=0;a<n;a++)
        {
            arr[i]+=arr[i-a-1]*arr[a];
        }
    }
    cout<<arr[n];
    return 0;
}