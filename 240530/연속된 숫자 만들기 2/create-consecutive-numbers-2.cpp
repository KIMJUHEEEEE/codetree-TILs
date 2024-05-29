#include <iostream>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,c;
    cin>>a>>b>>c;
    if(a+1==b&&b+1==c) cout<<0;
    else if(a+2==b||b+2==c) cout<<1;
    else cout<<2;
    return 0;
}