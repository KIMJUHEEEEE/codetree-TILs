#include <iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[101]={0,};
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int min=9999999;
    for(int i=0;i<n;i++)
    {
        int ans=0;
        for(int j=0;j<n;j++)
        {
            ans+=abs(j-i)*arr[j];
        }
        if(ans<min) min=ans;
    }
    cout<<min;
    return 0;
}