#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int arr[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) continue;
        else
        {
            ans++;
            i+=m*2;
        }
    }
    cout<<ans;
    return 0;
}