#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    int maxi=0;
    bool arr[101]={0,};
    for(int i=a;i<b;i++)
    {
        arr[i]=1;
    }
    for(int i=c;i<d;i++)
    {
        arr[i]=1;
    }
    maxi=max(b,d);
    int ans=0;
    for(int i=0;i<=maxi;i++)
    {
        if(arr[i]==1) ans++;

    }
    cout<<ans;
    return 0;
}