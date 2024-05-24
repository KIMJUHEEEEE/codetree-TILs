#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    string arr;
    cin>>arr;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int max=9999;
        if(arr[i]=='1') continue;
        else
        {
            for(int j=0;j<n;j++)
            {
                int dis=0;
                if(i==j) continue;
                else{
                    if(arr[j]=='1')
                    {
                        dis=abs(j-i);
            
                if(max>dis) max=dis;
                    }}
            }
        }
        if(ans<max) ans=max;
    }
    cout<<ans;
    return 0;
}