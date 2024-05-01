#include <iostream>
using namespace std;

int fac(int n)
{
    if(n==0||n==1) return 1;
    return fac(n-1)*n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n=0;
    cin>>n;
    cout<<fac(n);
    return 0;
}