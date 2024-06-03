#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[15]={0,};
    for(int i=0;i<15;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+15);
    cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<' '<<arr[14]-(arr[0]+arr[1]+arr[2]);
    return 0;
}