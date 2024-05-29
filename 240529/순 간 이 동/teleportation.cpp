#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    int maxi=abs(b-a);
    maxi=min(maxi,abs(a-y)+abs(x-b));
    maxi=min(maxi,abs(a-x)+abs(y-b));
    cout<<maxi;
    return 0;
}