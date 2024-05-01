#include <iostream>
using namespace std;

int mul(int n){
    if(n==2) return 4;
    else if(n==1) return 2;
    return mul(n-1)*mul(n-2)%100;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    cout<<mul(n);
    return 0;
}