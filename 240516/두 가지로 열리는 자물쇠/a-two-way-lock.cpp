#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int a1,b1,c1,a2,b2,c2;
    cin>>a1>>b2>>c1;
    cin>>a2>>b2>>c2;
    int cnt=250;
    int mul=1;
    if(abs(a1-a2)<=4) mul*=(5-abs(a1-a2));
    if(abs(b1-b2)<=4) mul*=(5-abs(b1-b2));
    if(abs(c1-c2)<=4) mul*=(5-abs(c1-c2));
    cout<<cnt-mul;
    return 0;
}