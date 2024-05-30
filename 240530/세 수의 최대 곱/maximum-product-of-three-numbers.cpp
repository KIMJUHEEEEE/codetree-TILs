#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int arr[100001]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long maxi=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int mul=arr[i]*arr[j]*arr[k];
                if(mul>0)
                {
                    maxi=max(maxi,mul);
                }
            }
        }
    }
    cout<<maxi;
    return 0;
}