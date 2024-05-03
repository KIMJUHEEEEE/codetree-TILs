#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[101]={0,};
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=a;j<=b;j++)
        {
            arr[j]++;
        }
    }
    int max=0;
    for(int i=0;i<=n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<max;
    return 0;
}