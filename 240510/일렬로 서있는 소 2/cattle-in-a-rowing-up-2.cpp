#include <iostream>
using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    int arr[101]={0,};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cnt=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]<=arr[j]&&arr[j]<=arr[k])
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}