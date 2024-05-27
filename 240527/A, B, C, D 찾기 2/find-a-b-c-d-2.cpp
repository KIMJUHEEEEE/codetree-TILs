#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[16]={0,};
    for(int i=0;i<15;i++)
    {  
        cin>>arr[i];
    }
    sort(arr,arr+15);
    int a=arr[0];
    int b=arr[1];
    int c=0;
    int d=0;
    if(a+b==arr[2])
    {
        c=arr[3];
        d=arr[14]-a-b-c;
    }
    else
    {
        c=arr[2];
        d=arr[14]-a-b-c;
    }
    cout<<a<<" "<<b<<" "<<c<<" "<<d;
    return 0;
}