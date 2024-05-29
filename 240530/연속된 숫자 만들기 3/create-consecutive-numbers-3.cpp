#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,c;
    cin>>a>>b>>c;
    if(abs(a-b)>abs(b-c))
    {
        cout<<b-a-1;
    }
    else
    {
        cout<<c-b-1;
    }
    return 0;
}