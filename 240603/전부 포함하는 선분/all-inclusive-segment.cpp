#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    int arra[101]={0,};
    int arrb[101]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>arra[i]>>arrb[i];
    }
    int ans=9999;
    for(int i=0;i<n;i++)
    {
        int mini=999;
        int maxi=0;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(mini>arra[j]) mini=arra[j];
            if(maxi<arrb[j]) maxi=arrb[j];
        }
        ans=min(ans,maxi-mini);
    }
    cout<<ans;
    return 0;
}