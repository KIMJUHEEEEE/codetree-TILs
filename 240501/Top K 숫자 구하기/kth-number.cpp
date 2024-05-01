#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0, k=0;
    cin>>n>>k;
    int arr[1001]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<arr[k-1];
    return 0;
}