#include <iostream>
using namespace std;

int multi(int mul){
    if(mul<10) return mul;
    return multi(mul/10)+mul%10;
}

int main() {
    int a=0,b=0,c=0;
    cin>>a>>b>>c;
    int mul=a*b*c;
    cout<<multi(mul);
    // 여기에 코드를 작성해주세요.
    return 0;
}