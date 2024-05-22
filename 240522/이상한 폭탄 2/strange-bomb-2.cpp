#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                if(j-i<=k)
                {
                    if(max<arr[j]) max=arr[i];
                }
            }
        }
    }
    if(max==0) max=-1;
    cout<<max;
    return 0;
}