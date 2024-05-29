#include <iostream>
using namespace std;
int n;
int ans=99999;
int arr[10001]={0,};
int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=1;i<10001;i++)
    {
        arr[i]=arr[i-1]+i;// 1, 3, 6, 10, 15 ...
    }
    cin>>n;
    if(n==1) cout<<1;
    if(n==2) cout<<2;
    for(int i=1;i<10001;i++)
    {
        if(n>arr[i]+arr[i-1]&&n<=arr[i]+arr[i+1])
        {
            if((arr[i]+arr[i-1]+arr[i]+arr[i+1])/2>n) cout<<i*2;
            else cout<<i*2+1;
            break;
        }
        
    }
    return 0;
}
//1-1, 2-2, 3-3, 4-3, 5-4, 6-4, 7-5, 8-5, 9-5, 10-6, 11-6, 12-6, 13-7