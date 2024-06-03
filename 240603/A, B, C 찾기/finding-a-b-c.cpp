#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int arr[7]={0,};
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+7);
    int bc=arr[6]-arr[0];
    cout<<arr[0]<<' ';
    for(int i=1;i<6;i++)
    {
        for(int j=i+1;j<7;j++)
        {
            if(arr[i]+arr[j]==bc)
            {
                cout<<arr[i]<<' '<<arr[j];
            }
        }
    }
    return 0;
}