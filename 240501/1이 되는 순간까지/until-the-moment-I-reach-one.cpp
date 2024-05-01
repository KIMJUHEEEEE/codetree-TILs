#include <iostream>
using namespace std;

int div(int n){
    if(n==1) return 0;
    if(n%2==0)
    {
        n/=2;
    }
    else 
    {
        n/=3;
    }
    return div(n)+1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    cout<<div(n);
    return 0;
}