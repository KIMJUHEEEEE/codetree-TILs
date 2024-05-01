#include <iostream>
using namespace std;

int f(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return f(n/3)+f(n-1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    cout<<f(n);
    return 0;
}