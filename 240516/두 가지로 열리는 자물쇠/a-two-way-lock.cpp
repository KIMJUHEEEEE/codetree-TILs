#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int a1,b1,c1,a2,b2,c2;
    cin>>a1>>b2>>c1;
    cin>>a2>>b2>>c2;
    int cnt;
    if(n>5) {cnt=250; n=5;}
    else
    {
        cnt=n*n*n*2;
    }
    int mul=1;
    if(abs(a1-a2)<=n-1) mul*=(n-abs(a1-a2));
    if(abs(b1-b2)<=n-1) mul*=(n-abs(b1-b2));
    if(abs(c1-c2)<=n-1) mul*=(n-abs(c1-c2));
    cout<<cnt-mul;
    return 0;
}